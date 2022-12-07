
// Problem : D. Searchlights
// Contest : Codeforces - Grakn Forces 2020
// URL : https://codeforces.com/contest/1408/problem/D
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
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
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
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
int n,m,k,a[2001],b[2001],c[2001],d[2001],t,t1,i,j,maxx=1e8;
vector<pii> bruh,neww,final;
int main()
{
//  ofile;
    fio;
    cin>>n>>m;
    for (i=1;i<=n;i++) cin>>a[i]>>b[i];
    for (i=1;i<=m;i++) cin>>c[i]>>d[i];
    for (i=1;i<=n;i++) for (j=1;j<=m;j++)
    {
    	bruh.push_back({c[j]-a[i],d[j]-b[i]});
    }
    
    sort(bruh.begin(),bruh.end(),
    [](pii a, pii b) {if (a.fi-b.fi) return (a.fi>b.fi); return (a.se>b.se);});
    maxx=-1e8;
    for (pii pp : bruh)
    {
    	if (pp.se> maxx)
    	{
    		maxx=pp.se;
    		neww.push_back({pp.fi+1,pp.se+1});
    	}
    }
    maxx=1e8;
   // cout<<neww.size()<<endl;
    final.push_back({neww[0].fi,-1e8});
    for (i=0;i<neww.size();i++)
    {
    	if (i) final.push_back({neww[i].fi,neww[i-1].se});
    	final.push_back(neww[i]);
    }
    final.push_back({-1e8,neww[neww.size()-1].se});
    
    for (i=1;i<final.size();i++)
    {
    	if ((final[i].fi>=0) and (final[i].se>=0)) maxx=min(maxx,final[i].fi+final[i].se);
    	if (final[i].fi==final[i-1].fi)
    	{
    		if ((final[i-1].se<=0)and(final[i].se>=0)and(final[i].fi>=0)) maxx=min(maxx,final[i].fi);
    	}
    	else
    	{
    		if ((final[i-1].fi>=0)and(final[i].fi<=0)and(final[i].se>=0)) maxx=min(maxx,final[i].se);
    	}
    }
    if (maxx==1e8) cout<<0; else cout<<maxx;
    
}