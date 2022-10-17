#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
void found(int x)
{
	printf("! %d\n", x);
	fflush(stdout);
	exit(0);
}
int qry(int x)
{
	int ret1, ret2;
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", &ret1);
	printf("? %d\n", x + n / 2);
	fflush(stdout);
	scanf("%d", &ret2);
	if(ret1 == ret2)
		found(x);
	return ret2 - ret1;
}
int main()
{
	scanf("%d", &n);
	if(n % 4 == 2)
		found(-1);
	int l = 1, r = n / 2;
	int lv = qry(l);
	int rv = qry(r);
	while(r - l > 2)
	{
		int m = (l + r) / 2;
		int mv = qry(m);
		if((lv > 0) == (mv > 0))
			l = m, lv = mv;
		else
			r = m, rv = mv;
	}
	for(int i = l + 1; i < r; i++)
		qry(i);
	found(-1);
	return 0;
}