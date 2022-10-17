#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
char s[10];
bool query(int r1, int c1, int r2, int c2)
{
	printf("? %d %d %d %d\n", r1, c1, r2, c2);
	fflush(stdout);
	scanf("%s", s);
	return s[0] == 'Y';
}
char ans[1010];
int x, y, ansn, ansn2;
void down()
{
	ans[ansn++] = 'D', x++;
}
void right()
{
	ans[ansn++] = 'R', y++;
}
void up()
{
	ans[--ansn2] = 'D', x--;
}
void left()
{
	ans[--ansn2] = 'R', y--;
}
int main()
{
	scanf("%d", &n);
	ansn2 = n * 2 - 2;
	ans[ansn2] = '\0';
	x = 1, y = 1;
	ansn = 0;
	while(x + y < n + 1)
	{
		if(query(x + 1, y, n, n))
			down();
		else
			right();
	}
	x = n, y = n;
	while(x + y > n + 1)
	{
		if(query(1, 1, x, y - 1))
			left();
		else
			up();
	}
	printf("! %s\n", ans);
	fflush(stdout);
	return 0;
}