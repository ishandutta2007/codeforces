#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 5005
#define ll long long
int n;
ll f[N][N][2],a[N];
int main()
{
	scanf("%d",&n);memset(f,0x3f,sizeof(f));
	if(n==1){puts("0");return 0;}
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);f[0][0][0]=0;
	if(n==2){puts(a[1]==a[2]?"1":"0");return 0;}
	f[1][0][0]=0;f[1][1][1]=0;
	f[2][0][0]=0;f[2][1][0]=max(0ll,a[2]-a[1]+1);f[2][1][1]=max(0ll,a[1]-a[2]+1);
	for(int i=3;i<=n;i++)
	{
		f[i][0][0]=0;
		for(int j=1;j<=((i+1)>>1);j++)
		{
			f[i][j][1]=min(f[i-1][j-1][0]+max(0ll,a[i-1]-a[i]+1),f[i-2][j-1][1]+max(0ll,a[i-1]-min(a[i-2],a[i])+1));
			f[i][j][0]=min(f[i-1][j][1]+max(0ll,a[i]-a[i-1]+1),f[i-1][j][0]);
			//printf("%d %d %lld %lld\n",i,j,f[i][j][1],f[i][j][0]);
		}
	}
	for(int i=1;i<=((n+1)>>1);i++)printf("%lld ",min(f[n][i][0],f[n][i][1]));
}