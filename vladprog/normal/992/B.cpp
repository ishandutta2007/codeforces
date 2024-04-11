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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int l,r,x,y;
    cin>>l>>r>>x>>y;
    if(y%x!=0)
        cout<<0,exit(0);
    vector<int> v{x};
    int t=y/x;
    for(int i=2;i*i<=t;i++)
        if(t%i==0)
        {
            int k=0;
            while(t%i==0)
                t/=i,k++;
            int n=v.size();
            for(int j=0;j<n;j++)
                for(int add=v[j]*i,cnt=1;cnt<=k;cnt++,add*=i)
                    v.phb(add);
        }
    //cout<<t<<"\n";
    if(t!=1)
    {
        int n=v.size();
        for(int j=0;j<n;j++)
            v.phb(v[j]*t);
    }
    int ans=0;
    for(int a:v)//cout<<a<<"\n";
        if(l<=a&&a<=r&&l<=x*y/a&&x*y/a<=r&&__gcd(a,x*y/a)==x)
            ans++;//,cout<<a<<" "<<x*y/a<<"\n";
    cout<<ans;
}