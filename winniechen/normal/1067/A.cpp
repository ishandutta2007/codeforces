#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
#define ll long long
#define mod 998244353
ll f[2][205][2],s[2][205][2];
int n,a[N];
int main()
{
	scanf("%d",&n);int now=0,last=1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(a[1]==-1){for(int i=1;i<=200;i++)f[1][i][0]=1,s[1][i][0]=200-i+1;}
	else {f[1][a[1]][0]=1;for(int i=1;i<=a[1];i++)s[1][i][0]=1;};
	for(int i=2;i<=n;i++)
	{
		memset(f[now],0,sizeof(f[now]));
		memset(s[now],0,sizeof(s[now]));
		if(a[i]!=-1)
		{
			f[now][a[i]][1]=(s[last][a[i]][1]+f[last][a[i]][0])%mod;
			f[now][a[i]][0]=(s[last][1][0]-s[last][a[i]][0]+s[last][1][1]-s[last][a[i]][1])%mod;
		}else
		{
			for(int j=1;j<=200;j++)
			{
				f[now][j][1]=(s[last][j][1]+f[last][j][0])%mod;
				f[now][j][0]=(s[last][1][0]-s[last][j][0]+s[last][1][1]-s[last][j][1])%mod;
			}
		}
		for(int j=200;j;j--)for(int k=0;k<2;k++)s[now][j][k]=(s[now][j+1][k]+f[now][j][k])%mod;
		last^=1;now^=1;
		// printf("%lld\n",s[last][1][1]);
	}
	printf("%lld\n",(s[last][1][1]%mod+mod)%mod);
}