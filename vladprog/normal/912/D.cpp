#include<bits/stdc++.h>

#define DEBUG
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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef array<ll,3> cell;

ll n,m,r,k;

ll inc(ll x,ll y)
{
    ll px=min({x,r,n-x+1,n-r+1}),
       py=min({y,r,m-y+1,m-r+1});
    return px*py;
}

cell mcell(ll x,ll y)
{
    return {inc(x,y),x,y};
}

set<pll> used;
set<cell> can;

void add(ll x,ll y)
{
    if(x<1||x>n||y<1||y>m)
        return;
    if(used.count({x,y}))
        return;
    used.insert({x,y});
    can.insert(mcell(x,y));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m>>r>>k;
    add(n/2,m/2);
    add(n/2+1,m/2);
    add(n/2,m/2+1);
    add(n/2+1,m/2+1);
    ll res=0;
    for(int i=0;i<k;i++)
    {
        set<cell>::iterator it=can.end();
        it--;
        cell t=*it;
        can.erase(it);
        res+=t[0];
        ll x=t[1],y=t[2];
        for(ll dx=-1;dx<=1;dx++)
            for(ll dy=-1;dy<=1;dy++)
                add(x+dx,y+dy);
    }
    cout<<setprecision(10)
        <<(ld(res)/(n-r+1)/(m-r+1));
}