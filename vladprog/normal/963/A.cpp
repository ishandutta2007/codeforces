#pragma GCC optimize("O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

//#define DEBUG
#ifdef DEBUG
    #define IFD(...) __VA_ARGS__
    #define IFN(...)
    #define L cout<<__LINE__<<"\n";
    #define PRINT(...) __VA_ARGS__ cout<<__LINE__<" : "<<#__VA_ARGS__<<"\n"
    #define PRT(x) cout<<__LINE__<<" : "<<#x<<" = "<<x<<"\n"
#else // DEBUG
    #define IFD(...)
    #define IFN(...) __VA_ARGS__
    #define L
    #define PRINT(...) __VA_ARGS__
    #define PRT(x)
#endif // DEBUG

#define it iterator
#define rit reverse_iterator
#define mp make_pair
#define mems(a,b) memset(a,b,sizeof(a))
#define mem0(a) mems(a,0)
#define mem1(a) mems(a,1)
#define mem255(a) mems(a,255)
#define halt exit(0)
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
#define fort0(i,a,b) for(ll i=a,i##_TO=b;i<i##_TO;i++)
#define for0(i,n) fort0(i,0,n)
#define fort1(i,a,b) for(ll i=a,i##_TO=b;i<=i##_TO;i++)
#define for1(i,n) fort1(i,1,n)
#define ford(i,a,b) for(ll i=a,i##_TO=b;i>=i##_TO;i--)

using namespace __gnu_pbds;
using namespace std;

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template
<
    class key,
    class val=null_type,
    class comp=less<key>
>
using ord_set=tree
<
    key,
    val,
    comp,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

const ll MOD=1e9+9;

ll ppow(ll x,ll y)
{
    if(!y)
        return 1;
    if(y&1)
        return (ppow(x,y^1)*x)%MOD;
    ll p=ppow(x,y>>1);
    return (p*p)%MOD;
}

const int K=1e5+10;

char s[K];

signed main()
{
    ll n,a,b,k;
    scanf("%I64d%I64d%I64d%I64d%s",&n,&a,&b,&k,s);
    ll res=0;
    for(ll i=0;i<k;i++)
        res=((res+(s[i]=='+'?1:-1)*ppow(a,n-i)*ppow(b,i))%MOD+MOD)%MOD;
    ll p=(ppow(b,k)*ppow(a,MOD-k-1))%MOD;
    n=(n+1)/k;
    ll ans=res;
    if(p==1)
    {
        ans=(ans*n)%MOD;
        printf("%I64d",ans);
        exit(0);
    }
    ans=(ans*(1-ppow(p,n))%MOD+MOD)%MOD;
    ans=((ans*ppow(1-p+MOD,MOD-2))%MOD+MOD)%MOD;
    printf("%I64d",ans);
}