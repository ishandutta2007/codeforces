/*
khoi orz, go check out his algo
-normie-
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "ninja.inp"
#define FILE_OUT "ninja.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 1048576
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
#define ll long long
#define pi 3.1415926535897
//------START-----------//
struct dsu
{
	ll n,par[200001],h[200001],sz[200001];
	dsu (ll n)
	{
		for (ll i=1;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
			h[i]=1;
		}
		this->n=n;
	}
	ll get_par(ll x)
	{
		if (par[par[x]]==par[x]) return par[x];
		else return par[x]=get_par(par[x]);
	}
	ll check_same(ll a, ll b)
	{
		return (get_par(a)==get_par(b));
	}
	void add_edge(ll a, ll b)
	{
		ll ha=get_par(a),hb=get_par(b);
		if (ha!=hb)
		{
			if (h[ha]<h[hb])
			{
				par[ha]=hb;
				sz[hb]+=sz[ha];
			}
			else
			if (h[ha]>h[hb])
			{
				par[hb]=ha;
				sz[ha]+=sz[hb];
			}
			else
			{
				par[hb]=ha;
				sz[ha]+=sz[hb];
				h[ha]++;
			}
		}
	}
} gr(200000);
//------END-----------//
ll n,m,k,t,t1,i,j,a,b, res=-1,resi,resj;
ll ca[200001],cb[200001],e[200001],u[200001],v[200001];
string s[32001];
vector<ll> gt[32001];
vector<ll> edges;
ll cmp2(ll a, ll b)
{
	return (e[a]>e[b]);
}
int main()
{
	//ofile;
	fio;
	cin>>m>>n;
	for (i=1;i<=m;i++) cin>>cb[i];
	for (i=1;i<=n;i++) cin>>ca[i];
	for (i=1;i<=m;i++)
	{
		cin>>k;
		for (j=0;j<k;j++)
		{
			cin>>a;
			t++;
			u[t]=a;
			v[t]=100000+i;
			e[t]=ca[a]+cb[i];
	//		cout<<u[t]<<' '<<v[t]<<' '<<e[t]<<endl;
		edges.push_back(t);
		resi+=e[t];
		}
	}
	sort(edges.begin(),edges.end(),cmp2);
	for (ll g : edges)
	{
		if (gr.check_same(u[g],v[g]));
		else
		{
			resj+=e[g];
			gr.add_edge(u[g],v[g]);
		}
	}
//	cout<<resi<<' '<<resj<<endl;
	cout<<resi-resj;
	
}