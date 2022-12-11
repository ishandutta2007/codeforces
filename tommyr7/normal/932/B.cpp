#include <bits/stdc++.h>
#define Maxn 1000007
using namespace std;
int f[Maxn];
int s[Maxn][10];
int calc(int x)
{
	int res=1;
	while (x!=0)
	{
		if (x%10!=0) res*=(x%10);
		x/=10;
	}
	return res;
}
int main()
{
	for (int i=1;i<10;i++)
		f[i]=i;
	for (int i=10;i<=1000000;i++)
		f[i]=f[calc(i)];
	memset(s,0,sizeof(s));
	for (int i=1;i<=1000000;i++)
	{
		for (int j=0;j<=9;j++)
			s[i][j]=s[i-1][j];
		++s[i][f[i]];
	}
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",s[r][k]-s[l-1][k]);
	}
	return 0;
}