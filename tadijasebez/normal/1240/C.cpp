#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ldb long double
const int mod=1e9+7;//998244353;
void ckmx(int &x, int y){ x=max(x,y);}
void ckmn(int &x, int y){ x=min(x,y);}
void ckmx(ll &x, ll y){ x=max(x,y);}
void ckmn(ll &x, ll y){ x=min(x,y);}
int mul(int x, int y){ return (ll)x*y%mod;}
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
const int N=500050;
vector<pair<int,int>> E[N];
int n,k;
ll dp1[N],dp2[N];
void DFS(int u, int p)
{
	dp1[u]=dp2[u]=0;
	vector<ll> vals;
	ll sum=0;
	for(auto e:E[u]) if(e.first!=p)
	{
		int v,w;tie(v,w)=e;
		DFS(v,u);
		sum+=dp2[v];
		vals.pb(dp1[v]-dp2[v]+w);
	}
	sort(vals.rbegin(),vals.rend());
	while(vals.size() && vals.back()<=0) vals.pop_back();
	dp1[u]=dp2[u]=sum;
	for(int i=0;i<min(k-1,(int)vals.size());i++) dp1[u]+=vals[i];
	dp2[u]=dp1[u];
	if(k-1<vals.size()) dp2[u]+=vals[k-1];
	//printf("u:%i  dp1:%lld dp2:%lld\n",u,dp1[u],dp2[u]);
	//for(ll x:vals) printf("%lld ",x);printf("\n");
}
void Solve()
{
	scanf("%i %i",&n,&k);
	for(int i=1,u,v,w;i<n;i++) scanf("%i %i %i",&u,&v,&w),E[u].pb({v,w}),E[v].pb({u,w});
	DFS(1,0);
	printf("%lld\n",dp2[1]);
	for(int i=1;i<=n;i++) E[i].clear();
}
int main()
{
    int q;
    scanf("%i",&q);
    while(q--)
	{
		Solve();
	}
	return 0;
}