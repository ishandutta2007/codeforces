#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

#ifndef ONLINE_JUDGE
    //#define DEBUG
#endif

#ifdef DEBUG
    #define IFD(...) __VA_ARGS__
    #define IFN(...)
    #define L cout<<__LINE__<<"\n";
    #define PRINT(...) __VA_ARGS__ cout<<__LINE__<<" : "<<#__VA_ARGS__<<"\n"
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
#define all(c) begin(c) , end(c)
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
#define loop(n) for0(LOOP_COUNTER,n)
#define start_program IFD((start_time=clock()))
#define runtime ((clock()-start_time)*1.0/CLOCKS_PER_SEC)
#define halt(s) cout<<s,IFD(cout<<fixed<<setprecision(10)<<"\n\nTIME: "<<runtime<<" sec\n\n",)exit(0)
#define x first
#define y second

using namespace std;
using namespace __gnu_pbds; // pb_ds
using namespace __gnu_cxx;

#define int ll

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template
<
    class key,
    class val=null_type, /// null_mapped_type
    class comp=less<key>
>
using ord_set=tree /// find_by_order(), order_of_key()
<
    key,
    val,
    comp,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

typedef trie
<
    string,
    null_type,
    trie_string_access_traits<>,
    pat_trie_tag,
    trie_prefix_search_node_update
>
pref_trie; /// insert(), prefix_range()

template<class T,class U>
ostream&operator<<(ostream&out,pair<T,U> p)
{
    #ifdef DEBUG
        return out<<"("<<p.x<<","<<p.y<<")";
    #else
        return out<<p.x<<" "<<p.y;
    #endif
}

template<class T,class U>
istream&operator>>(istream&in,pair<T,U> p)
{
    return in>>p.x>>p.y;
}

template<class Iter,class Str>
struct _rng_
{
    Iter from,to;
    Str delim;
    _rng_(Iter from,Iter to,Str delim):from(from),to(to),delim(delim){}
};

template<class Iter,class Str>
_rng_<Iter,Str> rng(Iter from,Iter to,Str delim)
{
    return _rng_<Iter,Str>(from,to,delim);
}

template<class Iter>
auto rng(Iter from,Iter to)
{
    return rng(from,to," ");
}

template<class Cont,class Str>
auto rng(Cont&c,Str delim)
{
    return rng(all(c),delim);
}

template<class Cont>
auto rng(Cont&c)
{
    return rng(all(c));
}

template<class Iter,class Str>
ostream&operator<<(ostream&out,_rng_<Iter,Str> r)
{
    #ifdef DEBUG
        out<<distance(r.from,r.to)<<":"<<r.delim;
    #endif
    for(Iter i=r.from;i!=r.to;i++)
        out<<*i<<r.delim;
    return out;
}

template<class Iter,class Str>
istream&operator>>(istream&in,_rng_<Iter,Str> r)
{
    for(Iter i=r.from;i!=r.to;i++)
        in>>*i;
    return in;
}

template<class T>
T read()
{
    T res;
    cin>>res;
    return res;
}

template<class T>
vector<T> read(int n)
{
    vector<T> res(n);
    cin>>rng(res);
    return res;
}

IFD( clock_t start_time; )

//const int MOD=;

ll ppow(ll x,ll y,ll mod)
{
    ll res=1;
    while(y)
    {
        if(y&1)
            res=res*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return res;
}

//const int N=;
//const int INF=;

//int a[N];

int cnt_eq[512],cnt_sub[512];
pii best[512],almost[512];

signed main()
{
    IFN
    (
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    )

    int n,m;
    cin>>n>>m;
    loop(n)
    {
        int f;
        cin>>f;
        int mask=0;
        loop(f)
        {
            int b;
            cin>>b;
            mask|=(1ll<<(b-1));
        }
        cnt_eq[mask]++;
//        cout<<mask<<"\n";
    }
    for(int submask=0;submask<512;submask++)
        for(int mask=0;mask<512;mask++)
            if((mask&submask)==submask)
                cnt_sub[mask]+=cnt_eq[submask];
    for(int i=0;i<512;i++)
        best[i]=almost[i]={int(1e18),0};
    for1(i,m)
    {
        int c,r;
        cin>>c>>r;
        int mask=0;
        loop(r)
        {
            int a;
            cin>>a;
            mask|=(1ll<<(a-1));
        }
        pii cur={c,i};
        almost[mask]=min(almost[mask],cur);
        if(almost[mask]<best[mask])
            swap(almost[mask],best[mask]);
    }
    /// good,cost,j1,j2
    array<int,4> ans={1,int(1e18),0,0};
    for(int mask1=0;mask1<512;mask1++)
        for(int mask2=mask1+1;mask2<512;mask2++)
        {
            int good=-cnt_sub[mask1|mask2],
                cost=best[mask1].x+best[mask2].x,
                j1=best[mask1].y,
                j2=best[mask2].y;
//            if(mask1==22&&mask2==258)
//                cout<<mask1<<" | "<<mask2<<" = "<<(mask1|mask2)<<" -> "<<-good<<" "<<cost<<"\n";
            if(cost<=1e17)
                ans=min(ans,{good,cost,j1,j2});
        }
    for(int mask=0;mask<512;mask++)
        {
            int good=-cnt_sub[mask],
                cost=best[mask].x+almost[mask].x,
                j1=best[mask].y,
                j2=almost[mask].y;
            if(cost<=1e17)
                ans=min(ans,{good,cost,j1,j2});
        }
//    cout<<-ans[0]<<" "<<ans[1]<<"\n";
    cout<<ans[2]<<" "<<ans[3];

    IFD(cout<<fixed<<setprecision(10)<<"\n\nTIME: "<<runtime<<" sec\n\n";)
}