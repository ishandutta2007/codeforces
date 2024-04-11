#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 300005
#define ll long long
#define int long long
#define mod 998244353
struct node{int to,next;}e[N<<1];
int head[N],cnt,f[N][3],n;
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
int q_pow(int x,int n){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
void dfs(int x,int from)
{
	f[x][2]=f[x][1]=1;int tmp=1;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)
		{
			dfs(to1,x);
			f[x][1]=(ll)f[x][1]*((f[to1][0]+f[to1][0])%mod+f[to1][2])%mod;
			f[x][2]=(ll)f[x][2]*(f[to1][0]+f[to1][2])%mod;
			tmp=(ll)tmp*((f[to1][0]+f[to1][0])%mod+f[to1][2])%mod;
		}
	}
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)
			f[x][0]=(f[x][0]+(ll)tmp*q_pow((f[to1][0]+f[to1][0])%mod+f[to1][2],mod-2)%mod*f[to1][1])%mod;
	}
	// printf("%lld %lld %lld %lld\n",x,f[x][0],f[x][1],f[x][2]);
}
signed main()
{
	scanf("%lld",&n);memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<n;i++)scanf("%lld%lld",&x,&y),add(x,y),add(y,x);
	dfs(1,0);
	printf("%lld\n",(f[1][0]+f[1][2])%mod);
}
//1+2+2+4+1