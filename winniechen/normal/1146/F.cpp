#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 200005
#define ll long long
#define mod 998244353
struct node{int to,next;}e[N<<1];
int f[N][3],ans,head[N],cnt,out[N],n;
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;out[x]++;}
void dfs(int x)
{
	if(!out[x]){f[x][0]=1,f[x][1]=1;return ;}f[x][0]=1;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;dfs(to1);
		int t1=f[x][0],t2=f[x][1],t3=f[x][2];
		f[x][0]=(ll)t1*(f[to1][0]+f[to1][2])%mod;
		f[x][1]=((ll)t1*f[to1][1]+(ll)t2*(f[to1][0]+f[to1][2]))%mod;
		f[x][2]=((ll)t3*(f[to1][0]+f[to1][2])+(ll)(t2+t3)*f[to1][1])%mod;
	}
	(f[x][1]+=f[x][2])%=mod;
}
int main()
{
	scanf("%d",&n);memset(head,-1,sizeof(head));
	for(int i=2,x;i<=n;i++)scanf("%d",&x),add(x,i);dfs(1);
	printf("%d\n",(f[1][0]+f[1][2])%mod);
}