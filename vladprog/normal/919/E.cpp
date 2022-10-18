#include<bits/stdc++.h>

//#define DEBUG
#ifdef DEBUG
    #define IFD(...) __VA_ARGS__
    #define IFN(...)
    #define L cout<<__LINE__<<"\n";
    #define PRINT(...) __VA_ARGS__ cout<<#__VA_ARGS__<<"\n"
    #define PRT(x) cout<<#x<<"="<<x<<"\n"
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

ll p;

ll ppow(ll x,ll y)
{
    if(y==0)
        return 1;
    if(y&1)
        return (ppow(x,y-1)*x)%p;
    ll t=ppow(x,y>>1);
    return (t*t)%p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a,b,x;
    cin>>a>>b>>p>>x;
    map<ll, vector<ll> > m;
    for(ll i=1,t=a;i<p;i++,t=(t*a)%p)
        m[t].phb(i);
    ll d=x/((p)*(p-1)),mod=x%((p)*(p-1));
    ll ans=0;
    for(ll i=1;i<p;i++)
    {
        PRT(i);
        ll r=ppow(i,p-2);
        PRT(r);
        r=(r*b)%p;
        PRT(r);
        if(m[r].empty())
            continue;
        for(ll k:m[r])
        {
            ll t=i+p*((k-i+p-1)%(p-1));
            ans+=d+(mod>=t);
        }
        PRT(ans);
        IFD( cout<<"\n"; )
    }
    cout<<ans;
}