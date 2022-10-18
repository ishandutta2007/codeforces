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

const int N=5e3+10;
//const int L=15;

int a[N];
int res[N][N];
int mres[N][N];
//int st[L][N];
//int log_2[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    for(int i=1;i<N;i++)
//    {
//        log2_[i]=log_2[i-1];
//        if((1ll<<r)<i)
//            log2_[i]++;
//    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int add=0;add<n;add++)
        for(int i=0;i<n-add;i++)
        {
            int j=i+add;
            if(i==j)
                mres[i][j]=res[i][j]=a[i];
            else
                mres[i][j]=max({res[i][j]=res[i][j-1]^res[i+1][j],mres[i][j-1],mres[i+1][j]});
            //IFD( cerr<<i<<" "<<j<<" -> "<<res[i][j]<<" "<<mres[i][j]<<"\n"; )
        }
//    for(int i=0;i<=log_2[n];i++)
//    {
//        int len=1ll<<i,len2=len>>1;
//        for(int j=0;j<=n-len;j++)
//            sp[i][j]=min({res[i][i+len-1],res[i][i+len2-1],res[i+len2][i+len]});
//    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        cout<<mres[l][r]<<"\n";
    }

}