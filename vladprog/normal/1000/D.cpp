#pragma GCC optimize("O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define DEBUG
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

const int N=1010,MOD=998244353;

int a[N+1],c[N+1][N+1],k[N+1];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    c[0][0]=1;
    for(int n=1;n<=N;n++)
        for(int k=0;k<=n;k++)
            c[n][k]=(c[n-1][k-1]+c[n-1][k])%MOD;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]<1)
            continue;
        int &res=k[i];
        if(a[i]<=n-i)
            res=c[n-i][a[i]];
        for(int j=i+a[i]+1;j<=n;j++)
            res=(res+k[j]*c[j-i-1][a[i]]%MOD)%MOD;
        ans=(ans+res)%MOD;
    }
    cout<<ans;
}