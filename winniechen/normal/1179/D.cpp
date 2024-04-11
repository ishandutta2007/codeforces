#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
struct node{int to,next;}e[N<<1];
int head[N],cnt,siz[N],n;ll f[N];
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
void dfs(int x,int from)
{
	siz[x]=1;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)dfs(to1,x),siz[x]+=siz[to1];
	}
}
void get_ans(int x,int from)
{
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)f[to1]=f[x]+(ll)(siz[x]-siz[to1])*siz[to1],get_ans(to1,x);
	}
}
int main()
{
	scanf("%d",&n);memset(head,-1,sizeof(head));memset(f,0x3f,sizeof(f));
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	dfs(1,0),f[1]=(ll)n*(n-1)/2,get_ans(1,0);int rt=2;
	for(int i=3;i<=n;i++)if(f[rt]<f[i])rt=i;
	dfs(rt,0),f[rt]=(ll)n*(n-1)/2,get_ans(rt,0);ll ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,f[i]);
	printf("%lld\n",ans);
}