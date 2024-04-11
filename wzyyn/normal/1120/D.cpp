#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 200005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,A[N],a,b,ecnt,last[N],idx,vis[N],posl[N],posr[N],fa[N],ans[N];ll Sum;
struct edge{int id,fr,to,v;}E[N];
struct road{int to,nex;}e[N<<1];
void adde(int u,int v) {e[++ecnt]=(road){v,last[u]},last[u]=ecnt;}
int find(int x) {return fa[x]^x?fa[x]=find(fa[x]):x;}
void dfs(int x,int fath=0)
{
	int leaf=1;posl[x]=n;
	for(int k=last[x];k;k=e[k].nex)
		if(e[k].to^fath)
			dfs(e[k].to,x),leaf=0,posl[x]=min(posl[x],posl[e[k].to]),posr[x]=max(posr[x],posr[e[k].to]);
	if(leaf) vis[++idx]=x,posl[x]=posr[x]=idx;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	for(int i=1;i<n;i++) scanf("%d%d",&a,&b),adde(a,b),adde(b,a);
	dfs(1);
	for(int i=1;i<=n;i++) E[i]={i,posl[i]-1,posr[i],A[i]};
	std::sort(E+1,E+1+n,[](edge t1,edge t2){return t1.v<t2.v;});
	for(int i=1;i<=idx;i++) fa[i]=i;
	for(int i=1,pre=1,f1,f2;i<=n;i++) if(E[i].v^E[i+1].v||i==n)
	{
		for(int j=pre;j<=i;j++)
		{
			f1=find(E[j].fr),f2=find(E[j].to);
			if(f1^f2) ans[++ans[0]]=E[j].id;
		}
		for(int j=pre;j<=i;j++)
		{
			f1=find(E[j].fr),f2=find(E[j].to);
			if(f1^f2) fa[f1]=f2,Sum+=E[j].v;
		}
		pre=i+1;
	}
	std::sort(ans+1,ans+1+ans[0]);
	printf("%lld %d\n",Sum,ans[0]);
	for(int i=1;i<=ans[0];i++) printf("%d ",ans[i]);puts("");
	return 0;
}