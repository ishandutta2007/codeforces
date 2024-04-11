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

ll cnt(ll x)
{
    IFD( cout<<"\ncnt("<<x<<")="; )
    for(ll p=0,pp=1;;p++,pp<<=1)
        if(pp>x)
            return IFD( cout<<p<<"\n", ) p;
}

ll cut(ll x,ll p)
{
    p--;
    IFD(
    cout<<"\ncut("<<x<<","<<p+1<<")="<<
        ((x&((1ll<<p)-1))|(1ll<<p))<<"\n"; )
    return (x&((1ll<<p)-1))|(1ll<<p);
}

ll mult(ll x,ll y,ll m)
{
    x=((x%m)+m)%m;
    y=((y%m)+m)%m;
    if(x<y)
        swap(x,y);
    if(!y)
        return 0;
    if(y&1)
        return (mult(x,y^1,m)+x)%m;
    ll res=mult(x,y>>1,m);
    return (res+res)%m;
}

ll mov[70];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll q;
    cin>>q;
    while(q--)
    {
        ll t;
        cin>>t;
        if(t!=3)
        {
            ll x,k;
            cin>>x>>k;
            ll p=cnt(x);
            mov[p]=(mov[p]+k)%(1ll<<(p-1));
            if(t==2)
                for(ll s=p+1;s<=60;s++)
                    mov[s]=(mov[s]+mult(k,1ll<<(s-p),1ll<<s-1))%(1ll<<s-1);
        }
        else
        {
            ll x;
            cin>>x;
            cout<<x<<" ";
            while(x>1)
            {
                ll p=cnt(x);
                x=cut((cut(x+mov[p],p)>>1)-mov[p-1],p-1);
                cout<<x<<" ";
            }
            cout<<"\n";
        }
    }
}