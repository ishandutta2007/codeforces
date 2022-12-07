// Problem : Asterism (Easy Version)
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1371/problem/E1
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1001000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<ll,ll>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
ll n,p,m,k,c[501],pos[100001],t,t1,i,j;
vector<ll> lis,res; vector<pii> banned,actions;
void check (ll x)
{
	ll ways;
	for (ll i=0;i<n;i++)
	{
		ways=min(n-(lis[n-1-i])+x,n)-i;
		if ((ways<=0) or(ways==p)) return;
	}
	res.push_back(x);
}
int main()
{
//  ofile;
    fio;
    cin>>n>>p;
    for (i=1;i<=n;i++)
    {
    	cin>>m;
    lis.push_back(m);
    }
    sort(lis.begin(),lis.end());
    for (i=0;i<n;i++)
    {
    	banned.push_back({0,max(i-n+lis[n-i-1],0)});
    	if (n-i==p)
    	banned.push_back({lis[n-i-1],MOD});
    	else if (n-i>p)
    	banned.push_back({p+i+lis[n-1-i]-n,p+i+lis[n-1-i]-n});
    }
    banned.push_back({0,0});
    for (pii pp : banned) if (pp.fi<=pp.se)
    {
  //  	cout<<pp.fi<<' '<<pp.se<<endl;
    	actions.push_back({pp.fi,1});
    	actions.push_back({pp.se+1,-1});
    }
    sort(actions.begin(),actions.end(),[](pii a, pii b){return (a.fi<b.fi);});
    for (i=0;i<actions.size();i++) if (actions[i].fi==MOD+1) break; else
    {
    	t+=actions[i].se;
    	if (t==0)
    	{
    		for (j=actions[i].fi;j<actions[i+1].fi;j++) res.push_back(j);
    	}
    }
    cout<<res.size()<<endl;
    for (ll g:res) cout<<g<<' ';
}
//n-lis[n-i-1]+x-i==p