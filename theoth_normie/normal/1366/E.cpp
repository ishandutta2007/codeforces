
// Problem : E. Two Arrays
// Contest : Codeforces - Educational Codeforces Round 89 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1366/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
ll n,m,k,c[501],ar[200001],b[200001],t,t1,i,j,maxx1=-1,maxx2=-1,ways=1;
vector<int> ind;
set<int> lis;
int main()
{
//  ofile;
    fio;
    cin>>n>>m;
    for (i=0;i<n;i++) 
    {
    	cin>>ar[i];
    	ind.push_back(i);
    }
    for (i=0;i<m;i++) cin>>b[i];
    sort(ind.begin(),ind.end(),[](int a, int b){return (ar[a]<ar[b]);});
    if (ar[ind[0]]!=b[0]) return cout<<0,0;
    i=0;
    for (j=1;j<m;j++)
    {
    	for (i=i;i<n;i++) if (ar[ind[i]]<b[j]) maxx1=max(maxx1,ind[i]); else break;
    	if ((i==n)or(ar[ind[i]]!=b[j])) return cout<<0,0;
    	maxx2=-1;
    	for (k=i;k<n;k++) if (ar[ind[k]]==b[j]) maxx2=max(maxx2,ind[k]); else break;
    	if (maxx1>=maxx2) return cout<<0,0;
    	else 
    	{
    		ways*=maxx2-maxx1;
    		ways%=998244353;
    	}
    }
    cout<<ways;
}