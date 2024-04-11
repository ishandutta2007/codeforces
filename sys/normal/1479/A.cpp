#include <bits/stdc++.h>
using namespace std;

int n;
void work(int lt, int rt)
{
	if (lt == rt)
	{
		printf("! %d\n", lt);
		fflush(stdout);
		exit(0);
	}
	int mid = (lt + rt) >> 1;
	printf("? %d\n", mid);
	fflush(stdout);
	int x, y;
	scanf("%d", &x);
	printf("? %d\n", mid + 1);
	fflush(stdout);
	scanf("%d", &y);
	if (x < y) work(lt, mid);
	else work(mid + 1, rt);
}
int main()
{
	scanf("%d", &n);
	work(1, n);
	return 0;
}