#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

#ifndef ONLINE_JUDGE
    #define DEBUG
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

int px[667],py[667];


signed main()
{
    IFN
    (
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    )

    int x,y;
    cin>>x>>y;
    int k[2][2]={};
    set<pair<int,int>> s;
    for1(i,666)
    {
        int a,b;
        cin>>a>>b;
        s.insert({a,b});
        k[a>500][b>500]++;
        px[i]=a,py[i]=b;
    }
    loop(1000)
    {
        if(s.count({x+1,y+1})||s.count({x+1,y-1}))
            x++;
        else if(s.count({x-1,y-1})||s.count({x-1,y+1}))
            x--;
        else
        {
            if(x>500) x--; else x++;
            if(y>500) y--; else y++;
        }
        cout<<x<<" "<<y<<endl;
        int i,a,b;
        cin>>i>>a>>b;
        if(i<=0)
            exit(i+1);
        k[px[i]>500][py[i]>500]--;
        s.erase({px[i],py[i]});
        px[i]=a,py[i]=b;
        k[px[i]>500][py[i]>500]++;
        s.insert({px[i],py[i]});
    }
    int dx=0,dy=0;
    for0(tx,2) for0(ty,2)
        if(k[tx][ty]<k[dx][dy])
            dx=tx,dy=ty;
    dx=1-dx*2,dy=1-dy*2;
    loop(1000)
    {
        if(s.count({x+1,y+1})||s.count({x+1,y-1}))
            x++;
        else if(s.count({x-1,y-1})||s.count({x-1,y+1}))
            x--;
        else
            x+=dx,y+=dy;
        if(x==0&&y==0) x=1,y=2;
        if(x==1000&&y==0) x=999,y=2;
        if(x==0&&y==1000) x=1,y=998;
        if(x==1000&&y==1000) x=999,y=998;
        x=max(1ll,min(x,999ll));
        y=max(1ll,min(y,999ll));
        cout<<x<<" "<<y<<endl;
        int i,a,b;
        cin>>i>>a>>b;
        if(i<=0)
            exit(i+1);
        k[px[i]>500][py[i]>500]--;
        s.erase({px[i],py[i]});
        px[i]=a,py[i]=b;
        k[px[i]>500][py[i]>500]++;
        s.insert({px[i],py[i]});
    }

    IFD(cout<<fixed<<setprecision(10)<<"\n\nTIME: "<<runtime<<" sec\n\n";)
}