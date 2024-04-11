#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int g[1000010];
int sum[1000010][10];

int len;

LL getf(LL x)
{
	len = 0;
	LL res = 1;
	while(x)
	{
		if (x % 10)
			res = res * (x % 10);
		if (res > 1e12) return -1;
		x /= 10;
	}
	return res;
}

int calc(LL x)
{
	for (int i=1;i<15 && x>=10;i++)
	{
		x = getf(x);
	}
	return x;
}

int main()
{
	for (int i=1;i<=1000000;i++)
	{
		g[i] = calc(i);
		for (int j=0;j<10;j++)sum[i][j] = sum[i-1][j];
		if (g[i] > 0) 
			sum[i][g[i]]++;
	}
	int Q,L,R,K;
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d%d",&L,&R,&K);
		printf("%d\n",sum[R][K] - sum[L-1][K]);
	}
}