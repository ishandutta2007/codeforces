#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 2005
#define ll long long
#define mod 998244353
int a[N][N],f[N][N],n,fac[N],ans,g[N],c[N],s[N],pf[N],vis1[N],vis2[N];
void fix(int *a,int x,int op){for(;x<=n;x+=x&-x)a[x]+=op;}
int find(int *a,int x){int ret=0;for(;x;x-=x&-x)ret+=a[x];return ret;}
void init(){memset(c,0,sizeof(c));memset(s,0,sizeof(s));}
int main()
{
	scanf("%d",&n);fac[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);g[1]=0,g[2]=1;
	for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	for(int i=3;i<=n;i++)g[i]=(ll)(g[i-1]+g[i-2])*(i-1)%mod;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=fac[i];
		for(int j=1;j<i;j++)f[i][j]=((ll)(i-j)*f[i-1][j]+(ll)j*f[i-1][j-1])%mod;
		f[i][i]=g[i];
	}pf[0]=1;
	for(int i=1;i<=n;i++)pf[i]=(ll)pf[i-1]*g[n]%mod;
	init();
	for(int i=n;i;i--)
	{
		fix(c,a[1][i],1);
		ans=(ans+(ll)find(c,a[1][i]-1)*fac[n-i]%mod*pf[n-1])%mod;
	}
	for(int i=2;i<=n;i++)
	{
		init();memset(vis1,0,sizeof(vis1));memset(vis2,0,sizeof(vis2));
		for(int j=n;j;j--)
		{
			vis2[a[i][j]]=1;
			if(!vis1[a[i][j]])fix(c,a[i][j],1);
			else fix(s,a[i][j],1);
			int cnt=find(s,n);
			ans=(ans+(ll)find(c,a[i][j]-1)*f[n-j][cnt]%mod*pf[n-i])%mod;
			if(cnt)ans=(ans+(ll)find(s,a[i][j]-1)*f[n-j][cnt-1]%mod*pf[n-i])%mod;
			if(a[i][j]>a[i-1][j]&&vis2[a[i-1][j]])
				ans=(ans-(ll)f[n-j][cnt]*pf[n-i])%mod;
			if(!vis2[a[i-1][j]])vis1[a[i-1][j]]=1;
			else
			{
				vis1[a[i-1][j]]=1;
				fix(c,a[i-1][j],-1);
				fix(s,a[i-1][j],1);
			}
		}
	}
	printf("%d\n",(ans+mod)%mod);
}