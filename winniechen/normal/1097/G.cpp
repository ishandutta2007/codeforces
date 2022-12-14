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
#define M 205
#define ll long long
#define mod 1000000007
int q_pow(int x,int n){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
#define inv(x) q_pow(x,mod-2)
struct node{int to,next;}e[N<<1];
int head[N],siz[N],cnt,f[N][M],s[M][M],fac[M],mi[N],ans[M],n,K;
inline void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
void dfs(int x,int from)
{
	siz[x]=1;f[x][0]=1;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)
		{
			dfs(to1,x);
			for(int j=min(siz[to1],K)-1;~j;j--)
			{
				int val=f[to1][j];
				if(!j)val=(ll)val*(1-mi[siz[to1]])%mod;
				ans[j+1]=(ans[j+1]+(ll)val*(1-mi[n-siz[to1]]))%mod;
				f[to1][j+1]=(f[to1][j+1]+val)%mod;
			}
			for(int j=min(siz[x]-1,K);~j;j--)
				for(int k=1;k<=siz[to1]&&j+k<=K;k++)
				{
					int val=(ll)f[to1][k]*f[x][j]%mod;
					if(j)ans[j+k]=(ans[j+k]+val)%mod;
					f[x][j+k]=(f[x][j+k]+val)%mod;
				}
			siz[x]+=siz[to1];
		}
	}
}
#define inv2 500000004
int main()
{
	scanf("%d%d",&n,&K);memset(head,-1,sizeof(head));s[0][0]=1;
	mi[0]=1;for(int i=1;i<=n;i++)mi[i]=(ll)mi[i-1]*inv2%mod;
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);dfs(1,0);
	for(int i=1;i<=K;i++)for(int j=1;j<=i;j++)s[i][j]=((ll)s[i-1][j]*j+s[i-1][j-1])%mod;
	fac[0]=1;for(int i=1;i<=K;i++)fac[i]=(ll)fac[i-1]*i%mod;int ret=0;
	for(int i=1;i<=K;i++)ret=(ret+(ll)s[K][i]*ans[i]%mod*fac[i])%mod;ret=(ll)ret*q_pow(2,n)%mod;
	printf("%d\n",(ret+mod)%mod);
}

//