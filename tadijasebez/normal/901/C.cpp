#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N=300050;
const int inf=1e9;
int p[N],r[N];
int Find(int x)
{
	if(p[x]!=x) p[x]=Find(p[x]);
	return p[x];
}
void Union(int x, int y)
{
	x=Find(x);
	y=Find(y);
	if(r[x]>r[y]) p[y]=x;
	if(r[y]>r[x]) p[x]=y;
	if(r[x]==r[y]) r[x]++,p[y]=x;
}
vector<int> E[N];
int par[N],dep[N];
bool vis[N];
void DFS(int u, int o, int d)
{
	vis[u]=1;
	par[u]=o;
	dep[u]=d;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=o) DFS(v,u,d+1);
	}
}
vector< pair<int,int> > Cicle;
int u[N],v[N];
void Swap(int &a, int &b)
{
	a^=b;
	b^=a;
	a^=b;
}
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
struct Seg
{
	int l,r,id;
	Seg(){}
	Seg(int b, int c, int d){ l=b,r=c,id=d;}
	bool operator < (Seg b) const
	{
		return l<b.l;
	}
};
struct Event
{
	int t,l,r,id;
	Event(){}
	Event(int a, int b, int c, int d){ t=a,l=b,r=c,id=d;}
	bool operator < (Event b) const
	{
		if(l==b.l) return t<b.t;
		return l<b.l;
	}
};
set<Seg> Set;
set<Seg>::iterator it;
int val[N];
bool sol[N];
int RMQ[N];
const int M=2*N;
int ls[M],rs[M],clock,root;
vector<ll> x[M],y[M];
ll Fun[M];
void Build(int &c, int ss, int se)
{
	c=++clock;
	x[c].pb(0);
	y[c].pb(0);
	int i;
	for(i=ss;i<=se;i++) x[c].pb(val[i]),y[c].pb(val[i]),Fun[c]+=i;
	sort(x[c].begin(),x[c].end());
	sort(y[c].begin(),y[c].end());
	for(i=1;i<=x[c].size();i++) x[c][i]+=x[c][i-1];
	if(ss==se) return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
ll Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se)
	{
		ll sum=0;
		int i=upper_bound(y[c].begin(),y[c].end(),qe)-y[c].begin();
		i--;
		//printf("%i ",i);
		sum+=x[c][i];
		//printf("%i ",sum);
		i=x[c].size()-i-1;
		//printf("%i %i ",i,x[c].size());
		sum+=(ll)(qe+1)*i;
		//printf("%i ",sum);
		sum-=Fun[c];//(ll)se*(se+1)/2-(ll)ss*(ss-1)/2;
		//sum+=se-ss+1;
		//printf("%i %i %i\n",ss,se,sum);
		return sum;
	}
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
ll dp[N];
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) p[i]=i;
	for(i=1;i<=m;i++)
	{
		scanf("%i %i",&u[i],&v[i]);
		if(Find(u[i])==Find(v[i])) Cicle.pb(mp(u[i],v[i]));
		else Union(u[i],v[i]),E[u[i]].pb(v[i]),E[v[i]].pb(u[i]);
	}
	for(i=1;i<=n;i++) if(!vis[i]) DFS(i,0,1);
	//printf("%i\n",Cicle.size());
	for(i=0;i<Cicle.size();i++)
	{
		int u=Cicle[i].first;
		int v=Cicle[i].second;
		vector<int> tmp;
		if(dep[u]<dep[v]) Swap(u,v);
		while(dep[u]>dep[v]) tmp.pb(u),u=par[u];
		while(u!=v) tmp.pb(u),tmp.pb(v),u=par[u],v=par[v];
		tmp.pb(v);
		int Max=0,Min=1e9;
		for(j=0;j<tmp.size();j++) Max=max(Max,tmp[j]),Min=min(Min,tmp[j]);
		Set.insert(Seg(Min,Max,0));
	}

	i=1;
	for(it=Set.begin();it!=Set.end();)
	{
		Seg tmp=*it;
		it++;
		Set.erase(tmp);
		tmp.id=i;
		RMQ[i]=tmp.r;
		Set.insert(tmp);
		i++;
		//printf(" %i %i\n",tmp.l,tmp.r);
	}
	//printf(":D\n");
	RMQ[i]=inf;
	for(i--;i;i--)
	{
		RMQ[i]=min(RMQ[i+1],RMQ[i]);
	}
	for(i=1;i<=n;i++)
	{
		it=Set.lower_bound(Seg(i,i,0));
		if(it==Set.end()) val[i]=n+1;
		else j=it->id,val[i]=RMQ[j];
	}
	for(i=1;i<=n;i++) dp[i]=dp[i-1]+val[i];
	//for(i=1;i<=n;i++) printf("%i ",val[i]); printf("\n");
	//Build(root,1,n);
	int q,l,r;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&l,&r);
		int top=r,bot=l,ans=l-1,mid;
		while(top>=bot)
        {
            mid=top+bot>>1;
            if(val[mid]<=r) ans=mid,bot=mid+1;
            else top=mid-1;
        }
        ll sum=dp[ans]-dp[l-1];
        sum+=(ll)(r-ans)*(r+1);
        sum-=(ll)r*(r+1)/2-(ll)l*(l-1)/2;
        printf("%lld\n",sum);
		//printf("%lld\n",Get(root,1,n,l,r));
	}
	return 0;
}