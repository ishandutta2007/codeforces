#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
const ll inf=9e18;
const int oo=1e9+7;
const int N=100050;
ll min(ll a, ll b){ return a>b?b:a;}
bool Q;
struct Line
{
	mutable ll k,n,x;
	Line(ll a, ll b, ll c=0){ k=a,n=b,x=c;}
	bool operator < (Line b) const{ return Q?x<b.x:k>b.k;}
	ll operator ^ (Line b) const
	{
		ll p=n-b.n,q=b.k-k;
		if(q<0) p=-p,q=-q;
		if(p>0) return p/q;
		return -((-p+q-1)/q);
	}
};
struct DynamicConvexHullTrick : multiset<Line>
{
	bool Bad(iterator it)
	{
		if(it==end()) return 0;
		iterator it1,it2;
		it1=it;it1++;
		if(it1==end()) it->x=inf;
		else it->x=*it^*it1;
		if(it==begin() || it1==end()) return 0;
		it1=it;it1--;
		it2=it;it2++;
		if((*it1^*it)>=(*it1^*it2)) erase(it);
		else return 0;
		return 1;
	}
	void AddLine(ll k, ll n)
	{
		iterator it=lower_bound(Line(k,n)),it1;
		if(it!=end() && it->k==k)
		{
			if(it->n<n) return;
			it->n=n;
		}
		else insert(Line(k,n));
		it=find(Line(k,n));
		if(Bad(it)) return;
		do{it1=it;it1++;}while(Bad(it1));
		while(it!=begin())
		{
			it1=it;it1--;
			if(!Bad(it1)) break;
		}
		Bad(it);
	}
	ll Query(ll x)
	{
		if(empty()) return inf;
		Q=1;iterator it=lower_bound(Line(0,0,x));Q=0;
		if(it!=end()) return it->k*x+it->n;
	}
} Hull[N];
vector<int> E[N];
int a[N],b[N],id[N],cnt;
ll dp[N];
DynamicConvexHullTrick::iterator it;
void DFS(int u, int p)
{
	int HC=0;
	int i;
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u);
	}
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p && Hull[id[v]].size()>Hull[id[HC]].size()) HC=v;
	}
	if(!HC)
	{
		id[u]=++cnt;
		Hull[id[u]].AddLine(b[u],0);
	}
	else
	{
		id[u]=id[HC];
		for(i=0;i<E[u].size();i++)
		{
			int v=E[u][i];
			if(v!=p && v!=HC)
			{
				for(it=Hull[id[v]].begin();it!=Hull[id[v]].end();it++)
				{
					Hull[id[u]].AddLine(it->k,it->n);
				}
			}
		}
		dp[u]=Hull[id[u]].Query(a[u]);
		Hull[id[u]].AddLine(b[u],dp[u]);
	}
}
int main()
{
	int n,i,u,v;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) scanf("%i",&b[i]);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	for(i=1;i<=n;i++) printf("%lld ",dp[i]);
	printf("\n");
	return 0;
}