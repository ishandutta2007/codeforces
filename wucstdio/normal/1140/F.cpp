#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#include<set>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
#define ll long long
using namespace std;
struct Edge
{
	int from;
	int to;
	int st,en;
}e[300005];
vector<int>s[1200005];
map<ll,int>last;
pair<int,int>st[26][600005];
set<ll>ss;
int q,edgenum,top[26],size1[600005],size2[600005],pa[600005];
ll ans;
int find(int x)
{
	return x==pa[x]?x:find(pa[x]);
}
void add(int o,int l,int r,int from,int to,int x)
{
	if(l>=from&&r<=to)
	{
		s[o].push_back(x);
		return;
	}
	if(from<=mid)add(lson,l,mid,from,to,x);
	if(to>mid)add(rson,mid+1,r,from,to,x);
}
void dfs(int dep,int o,int l,int r)
{
//	printf("dfs %d %d %d %d\n",dep,o,l,r);
	top[dep]=0;
	int n=(int)s[o].size();
	for(int i=0;i<n;i++)
	{
		int u=e[s[o][i]].from;
		int v=e[s[o][i]].to;
		u=find(u),v=find(v);
		if(u==v)continue;
		if(size1[u]+size2[u]>size1[v]+size2[v])swap(u,v);
		pa[u]=v;
		ans-=1ll*size1[u]*size2[u];
		ans-=1ll*size1[v]*size2[v];
		size1[v]+=size1[u];
		size2[v]+=size2[u];
		ans+=1ll*size1[v]*size2[v];
		st[dep][++top[dep]]=make_pair(u,v);
//		printf("(%d,%d)\n",u,v);
	}
//	printf("x: ");
//	for(int i=1;i<=2;i++)printf("(%d,%d,%d) ",find(i),size1[find(i)],size2[find(i)]);
//	printf("\n");
//	printf("y: ");
//	for(int i=300001;i<=300003;i++)printf("(%d,%d,%d) ",find(i),size1[find(i)],size2[find(i)]);
//	printf("\n");
	if(l==r)printf("%I64d ",ans);
	else
	{
		dfs(dep+1,lson,l,mid);
		dfs(dep+1,rson,mid+1,r);
	}
	while(top[dep])
	{
		int u=st[dep][top[dep]].first;
		int v=st[dep][top[dep]].second;
		top[dep]--;
		ans-=1ll*size1[v]*size2[v];
		size2[v]-=size2[u];
		size1[v]-=size1[u];
		ans+=1ll*size1[v]*size2[v];
		ans+=1ll*size1[u]*size2[u];
		pa[u]=u;
	}
}
int main()
{
	scanf("%d",&q);
	for(int i=1;i<=300000;i++)pa[i]=i,size1[i]=1;
	for(int i=1;i<=300000;i++)
	{
		pa[i+300000]=i+300000;
		size2[i+300000]=1;
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(last[x*400000ll+y])
		{
			e[++edgenum].from=x;
			e[edgenum].to=y+300000;
			e[edgenum].st=last[x*400000ll+y];
			e[edgenum].en=i-1;
			last[x*400000ll+y]=0;
		}
		else last[x*400000ll+y]=i;
		ss.insert(x*400000ll+y);
	}
	for(set<ll>::iterator it=ss.begin();it!=ss.end();it++)
	{
		if(last[*it])
		{
			e[++edgenum].from=(*it)/400000;
			e[edgenum].to=(*it)%400000+300000;
			e[edgenum].st=last[*it];
			e[edgenum].en=q;
		}
	}
	for(int i=1;i<=edgenum;i++)
	{
		add(1,1,q,e[i].st,e[i].en,i);
	}
	dfs(1,1,1,q);
	printf("\n");
	return 0;
}