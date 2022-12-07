
// Problem : C. Discrete Acceleration
// Contest : Codeforces - Grakn Forces 2020
// URL : https://codeforces.com/contest/1408/problem/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
#define tm tmm
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
ll n,m,k,c[501],pos[100001],t,t1,i,j;
long double posa,posb; ll fla,flb; long double ta,tb,tm,el;
int main()
{
//  ofile;
    fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
    	cin>>n>>m;
    	for (i=1;i<=n;i++) cin>>pos[i];
    	flb=n;
    	fla=1;
    	posa=0;
    	posb=m;
    	el=0;
    	while(true)
    	{
 //   		cout<<fla<<' '<<flb<<' '<<posa<<' '<<posb<<' '<<el<<endl;
    		if ((1<=fla)and(fla<=n))  ta=(pos[fla]-posa)/fla; else ta=2e9;
    		if ((1<=flb)and(flb<=n))  tb=(-pos[flb]+posb)/(n+1-flb); else tb=2e9;
    		tm=(posb-posa)/(fla+(n+1-flb));
    		if ((tm<=ta)and(tm<=tb)) 
    		{
    			cout<<fixed<<setprecision(9)<<tm+el<<endl;
    			break;
    		}
    		else if ((ta<=tm)and(ta<=tb))
    		{
    			posa+=fla*ta;
    			posb-=(n+1-flb)*ta;
    			el+=ta;
    			fla++;
    		}
    		else
    		{
    			
    			posa+=fla*tb;
    			posb-=(n+1-flb)*tb;
    			el+=tb;
    			flb--;
    		}
    	}
    }
}