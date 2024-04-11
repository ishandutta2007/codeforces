#if 0
CONTESTS
GYM
PROBLEMSET
GROUPS
RATING
API
VK CUP 
SECTIONS

PROBLEMSSUBMIT CODEMY SUBMISSIONSSTATUSHACKSROOMSTANDINGSCUSTOM INVOCATION
    
My contest submissions 
  
#	When	Who	Problem	Lang	Verdict	Time	Memory
20004960	2016-08-20 18:04:52	* unused	E - Garlands	GNU C++11	Runtime error on pretest 17	1076 ms	32200 KB
20004511	2016-08-20 18:02:45	* unused	E - Garlands	GNU C++11	Runtime error on pretest 17	1075 ms	32200 KB
20004129	2016-08-20 18:00:29	* unused	E - Garlands	GNU C++11	Runtime error on pretest 17	1075 ms	32200 KB
20002740	2016-08-20 17:51:10	* unused	D - Persistent Bookcase	GNU C++11	Runtime error on test 72	187 ms	67000 KB
19998280	2016-08-20 17:19:51	* unused	D - Persistent Bookcase	GNU C++11	Skipped	15 ms	67000 KB
19987865	2016-08-20 16:22:42	* unused	C - Pythagorean Triples	GNU C++11	Wrong answer on test 42	30 ms	1800 KB
19985296	2016-08-20 16:13:19	* unused	B - Bakery	GNU C++11	Accepted	109 ms	6000 KB
19982363	2016-08-20 16:06:39	* unused	A - Brain's Photos	GNU C++11	Accepted	15 ms	1800 KB
  
Codeforces Round #368 (Div. 2)
Finished
Practice
 Add to favourites
  
 Virtual participation
Virtual contest is a way to take part in past contest, as close as possible to participation on time. It is supported only ACM-ICPC mode for virtual contests. If you've seen these problems, a virtual contest is not for you - solve these problems in the archive. If you just want to solve some problem from a contest, a virtual contest is not for you - solve this problem in the archive. Never use someone else's code, read the tutorials or communicate with other person during a virtual contest.
Start virtual contest
  
 Practice
You are registered for practice. You can solve problems unofficially. Results can be found in the contest status and in the bottom of standings.

Codeforces (c) Copyright 2010-2016 Mike Mirzayanov
The only programming contests Web 2.0 platform
#endif
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	if (n <= 2) printf("-1");
	else
	{
		if (n % 2 == 0)
		{
			printf("%lld %lld", (n / 2ll)*(n / 2ll) - 1, (n / 2ll)*(n / 2ll) + 1);
			return 0;
		}

		
		long long foo = ((long long)n * n - 1) / 2;
		printf("%lld %lld", foo, foo + 1);
	}
}