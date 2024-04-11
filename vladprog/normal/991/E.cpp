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

#define per(i) for(t[i]=min(1ll,k[i]);t[i]<=k[i];t[i]++)

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    int f[19]={1,1};
    for(int i=2;i<=19;i++)
        f[i]=f[i-1]*i;
    int k[10]={};
    for(char c:s)
        k[c-'0']++;
    int t[10];
    int ans=0;
    per(0)
    per(1)
    per(2)
    per(3)
    per(4)
    per(5)
    per(6)
    per(7)
    per(8)
    per(9)
    per(10)
    {
        int s=t[0]+t[1]+t[2]+t[3]+t[4]+t[5]+t[6]+
              t[7]+t[8]+t[9];
        //cout<<"s="<<s<<"\n";
        int res=f[s];
        for(int i=0;i<=9;i++)
        {
            //cout<<"t["<<i<<"]="<<t[i]<<"\n";
            //cout<<"f[t["<<i<<"]]="<<f[t[i]]<<"\n";
            res/=f[t[i]];
        }
        ans+=res;
        if(t[0])
        {
            res=f[s-1]/f[t[0]-1];
            for(int i=1;i<=9;i++)
                res/=f[t[i]];
            ans-=res;
        }
    }
    cout<<ans;
}