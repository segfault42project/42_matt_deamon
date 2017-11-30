#ifndef MATTDAEMON_H
#define MATTDAEMON_H

#include <iostream>
#include <string>
#include <ctime>

#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/file.h>

class	Tintin_reporter
{
	public:

	Tintin_reporter();
	void	write_log(std::string log, std::string type) const;
	void	create_lock_file(void);
	void	create_log_file(void);
	void	delete_lock_file(void) const;
	~Tintin_reporter();

	private:

	int	m_fd_lock;
	int	m_fd_log;

};

void	daemon(Tintin_reporter *tintin);
void	create_deamon();
int		setup_deamon(void);
void	quit(void);
int		main(void);

#endif
