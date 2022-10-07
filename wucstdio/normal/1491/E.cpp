#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#define ll long long
using namespace std;
const ll MOD1=1000000007,MOD2=1000000009;
const ll b1=19260817,b2=19491001;
struct Edge
{
	int to;
	int nxt;
}e[400005];
map<pair<ll,ll>,int>mp;
vector<pair<pair<int,int>,pair<int,bool> > >v;
int n,m,edgenum=1,fib[35],head[200005],pa[200005],sze[200005],pre[200005];
ll s1[200005],s2[200005],pw1[200005],pw2[200005];
bool flag[200005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node,int k)
{
	s1[node]=pw1[node];
	s2[node]=pw2[node];
	sze[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		if(flag[hd>>1])continue;
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		pre[to]=hd>>1;
		dfs(to,k);
		sze[node]+=sze[to];
		s1[node]=(s1[node]+s1[to])%MOD1;
		s2[node]=(s2[node]+s2[to])%MOD2;
	}
	if(sze[node]==fib[k-1])v.push_back(make_pair(make_pair(node,pa[node]),make_pair(pre[node],1)));
	if(sze[node]==fib[k-2])v.push_back(make_pair(make_pair(node,pa[node]),make_pair(pre[node],0)));
}
bool check(int x,int k)
{
	if(k<=3)return 1;
	v.clear();
	pa[x]=0;
	dfs(x,k);
	int&ans=mp[make_pair(s1[x],s2[x])];
	if(ans)return ans==1;
	pair<pair<int,int>,pair<int,bool> >res1,res2;
	bool f1=0,f2=0;
	if(v.size()>=1)res1=v[0],f1=1;
	if(v.size()>=2)res2=v[1],f2=1;
	if(f1)
	{
		flag[res1.second.first]=1;
		if(check(res1.first.first,k-1-(res1.second.second^1))&&check(res1.first.second,k-1-res1.second.second))
		{
			ans=1;
			return 1;
		}
		flag[res1.second.first]=0;
	}
	if(f2)
	{
		res1=res2;
		flag[res1.second.first]=1;
		if(check(res1.first.first,k-1-(res1.second.second^1))&&check(res1.first.second,k-1-res1.second.second))
		{
			ans=1;
			return 1;
		}
		flag[res1.second.first]=0;
	}
	ans=-1;
	return 0;
}
int main()
{
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=200000;i++)pw1[i]=pw1[i-1]*b1%MOD1;
	for(int i=1;i<=200000;i++)pw2[i]=pw2[i-1]*b2%MOD2;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	fib[0]=fib[1]=1;
	int i=1;
	while(fib[i]<n)
	{
		i++;
		fib[i]=fib[i-1]+fib[i-2];
	}
	if(fib[i]!=n)
	{
		printf("No\n");
		return 0;
	}
	if(check(1,i))printf("Yes\n");
	else printf("No\n");
	return 0;
}