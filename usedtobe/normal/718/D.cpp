#include<bits/stdc++.h>
#define N 200010
#define m1 998244353
#define m2 1000000007
using namespace std;
map<pair<int,int>,int>mp;
int sz[N],dad[N],a1[10],a2[10],tot,n,i,x,y,ans;
int v[N],l,ne[N],head[N],gs[N],f1[N],f2[N],F1[N],F2[N],g1[N],g2[N],s1[N],s2[N];
bool cmp1(int x,int y){return g1[x]<g1[y];}
bool cmp2(int x,int y){return g2[x]<g2[y];}
void add(int x,int y)
{
	v[++l]=y;ne[l]=head[x];head[x]=l;gs[x]++;
}
void dfs(int x)
{
	sz[x]=1;
	for(int i=head[x];i;i=ne[i])
		if(v[i]!=dad[x])dad[v[i]]=x,dfs(v[i]),sz[x]+=sz[v[i]];
	int l=0;
	for(int i=head[x];i;i=ne[i])
		if(v[i]!=dad[x])++l,a1[l]=v[i],a2[l]=v[i];
	sort(a1+1,a1+l+1,cmp1);
	sort(a2+1,a2+l+1,cmp2);
	tot=1;
	for(int i=1;i<=l;i++)
		g1[x]=(g1[x]+1ll*g1[a1[i]]*f1[tot])%m1,tot+=sz[a1[i]]<<1;
	(g1[x]+=f1[tot])%m1;
	tot=1;
	for(int i=1;i<=l;i++)
		g2[x]=(g2[x]+1ll*g2[a2[i]]*f2[tot])%m2,tot+=sz[a2[i]]<<1;
	(g2[x]+=f2[tot])%m2;
}
void dfs1(int x)
{
	int l=1,y=s1[x],z=s2[x];
	a1[l]=a2[l]=n+1;
	g1[n+1]=y;
	g2[n+1]=z;
	sz[n+1]=n-sz[x];
	for(int i=head[x];i;i=ne[i])
		if(v[i]!=dad[x])++l,a1[l]=v[i],a2[l]=v[i];
	sort(a1+1,a1+l+1,cmp1);
	sort(a2+1,a2+l+1,cmp2);
	tot=1;
	for(int i=1;i<=l;i++)
		F1[x]=(F1[x]+1ll*g1[a1[i]]*f1[tot])%m1,tot+=sz[a1[i]]<<1;
	(F1[x]+=f1[tot])%m1;
	tot=1;
	for(int i=1;i<=l;i++)
		F2[x]=(F2[x]+1ll*g2[a2[i]]*f2[tot])%m2,tot+=sz[a2[i]]<<1;
	(F2[x]+=f2[tot])%m2;
	for(int j=head[x];j;j=ne[j])if(v[j]!=dad[x])
	{
		l=1;a1[l]=a2[l]=n+1;
		for(int i=head[x];i;i=ne[i])
			if(i!=j&&v[i]!=dad[x])++l,a1[l]=v[i],a2[l]=v[i];
		sort(a1+1,a1+l+1,cmp1);
		sort(a2+1,a2+l+1,cmp2);
		tot=1;
		for(int i=1;i<=l;i++)
			s1[v[j]]=(s1[v[j]]+1ll*g1[a1[i]]*f1[tot])%m1,tot+=sz[a1[i]]<<1;
		(s1[v[j]]+=f1[tot])%m1;
		tot=1;
		for(int i=1;i<=l;i++)
			s2[v[j]]=(s2[v[j]]+1ll*g2[a2[i]]*f2[tot])%m2,tot+=sz[a2[i]]<<1;
		(s2[v[j]]+=f2[tot])%m2;
	}
	for(int i=head[x];i;i=ne[i])
		if(v[i]!=dad[x])dfs1(v[i]);
}
int main()
{
	scanf("%d",&n);
	f1[0]=f2[0]=1;
	for(i=1;i<=n<<1;i++)
	{
		f1[i]=f1[i-1]*3%m1;
		f2[i]=f2[i-1]*3%m2;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(1);
	dfs1(1);
	//for(i=1;i<=n;i++)printf("%d %d %d %d\n",F1[i],F2[i],s1[i],s2[i]);
	for(i=1;i<=n;i++)
	if(gs[i]<4)
	{
		if(!mp[make_pair(F1[i],F2[i])])
			ans++,mp[make_pair(F1[i],F2[i])]=1;
	}
	printf("%d\n",ans);
}