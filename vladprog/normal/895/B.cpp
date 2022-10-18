#include<bits/stdc++.h>

//#define DEBUG
#ifdef DEBUG
    #define IFD(...) __VA_ARGS__
    #define IFN(...)
    #define L mstr<<__LINE__<<"\n";
    #define PRINT(...) __VA_ARGS__ mstr<<#__VA_ARGS__<<"\n"
    #define PRT(x) mstr<<#x<<"="<<x<<"\n"
#else
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
#define forc(i,c) for(auto _N_##i##_=c.begin(),i=(_N_##i##_==c.end())?_N_##i##_:(_N_##i##_++);\
                      i!=c.end();\
                      i=(_N_##i##_==c.end())?_N_##i##_:(_N_##i##_++))
#define forr(i,c) for(auto _N_##i##_=c.rbegin(),i=(_N_##i##_==c.rend())?_N_##i##_:(_N_##i##_++);\
                      i!=c.rend();\
                      i=(_N_##i##_==c.rend())?_N_##i##_:(_N_##i##_++))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,x,k;
    cin>>n>>x>>k;
    multiset<pll>s0;
    for0(i,n)
    {
        ll t;
        cin>>t;
        s0.insert({t,0});
    }
    ll m=0;
    multiset<pll>s;
    for(pll p:s0)
        s.insert({p.first,m++});
    s.insert({1e18,m++});
    IFD
    (
    for(pll p:s)
        cout<<p.first<<" "<<p.second<<"\n";
    )
    m=0;
    for(pll p:s)
    {
        ll t=p.first,l,r;
        if(t==1e18)break;
        if(t%x==0)
            l=t+x*(k-1),r=t+x*k-1;
        else
            l=t-t%x+x*k,r=t-t%x+x*(k+1)-1;
        l=max(l,t);
        l=s.lower_bound({l,0})->second;
        r=s.upper_bound({r,1e18})->second-1;
        m+=max(r-l+1,0ll);
        IFD( cout<<p.second<<" -> "<<l<<" "<<r<<"\n"; )
    }
    cout<<m;
}