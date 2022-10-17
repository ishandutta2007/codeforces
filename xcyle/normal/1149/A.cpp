#include <iostream>
#include <cstdio>
#define maxn 200005
using namespace std;
int n, a, t1, t2;
int ans = 0, ord[maxn];
int check(int t)
{
	if(t == 1) return 0;
	for (int j = 2; j * j <= t; j++)
	{
		if(t % j == 0) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		if(a == 1) t1++;
		else t2++;
	}
	int now = 0, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if((!check(now + 1) && t2 != 0) || t1 == 0)
		{
			printf("2 ");
			t2--;
			now += 2;
		}
		else
		{
			printf("1 ");
			t1--;
			now++; 
		}
	}
	return 0;
}