#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.5
	Changes:
    Added warning against using pragmas on USACO.
*/
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
// #include <atcoder/all>
// using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul or USACO.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0)
#define nfio cin.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
#endif
vector<ll> vec;
ll n,m,i,j,k,t,t1,u,v,a,b;
ll fac[3000004];
ll inv[3000004];
ll dp[3000004];
int main()
{
	fio;
    cin>>n;
    fac[0]=inv[0]=1;
    for (i=1;i<=3*n+3;i++)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=MOD;
    }
    inv[3*n+3]=INV(fac[3*n+3],MOD);
    for (i=3*n+2;i>=1;i--)
    {
        inv[i]=inv[i+1]*(i+1);
        inv[i]%=MOD;
    }
    ll iv3=INV(3,MOD);
    dp[0]=n+1;
    for (i=1;i<=3*n;i++)
    {
        dp[i]=fac[3*n+3];
        // cout<<i<<' '<<dp[i]<<endl;
        dp[i]*=inv[i+1];
        dp[i]%=MOD;
        dp[i]*=inv[3*n+2-i];
        dp[i]%=MOD;
        // cout<<i<<' '<<dp[i]<<endl;
        if (i>=1)
        {
            dp[i]-=dp[i-1]*3;
        }
        if (i>=2)
        {
            dp[i]-=dp[i-2];
        }
        dp[i]+=MOD*4;
        dp[i]%=MOD;
        dp[i]*=iv3;
        dp[i]%=MOD;
        // cout<<i<<' '<<dp[i]<<endl;
    }
    cin>>m;
    for (i=1;i<=m;i++)
    {
        cin>>u;
        cout<<dp[u]<<endl;

    }
}