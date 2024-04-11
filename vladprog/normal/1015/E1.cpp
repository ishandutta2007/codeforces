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
#define halt(s) cout<<s,exit(0)IFD(,cout<<"\n\nTIME: "<<runtime<<" sec\n\n")
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
#define runtime (clock()*1.0/CLOCKS_PER_SEC)
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
auto rng(const Cont&c,Str delim)
{
    return rng(all(c),delim);
}

template<class Cont>
auto rng(const Cont&c)
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
    cin>>rng(all(res));
    return res;
}

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

const int N=1010;
//const int MOD=;
//const int INF=;

string s[N];
int l[N][N],r[N][N],u[N][N],d[N][N],ans[N][N];
bool b[N][N];



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
    for0(i,n)
        cin>>s[i];
    for0(i,n)
    {
        l[i][0]=s[i][0]=='*';
        fort1(j,1,m-1)
            l[i][j]=(s[i][j]=='*'?l[i][j-1]+1:0);
        r[i][m-1]=s[i][m-1]=='*';
        ford(j,m-2,0)
            r[i][j]=(s[i][j]=='*'?r[i][j+1]+1:0);
    }
    for0(i,m)
    {
        u[0][i]=s[0][i]=='*';
        fort1(j,1,n-1)
            u[j][i]=(s[j][i]=='*'?u[j-1][i]+1:0);
        d[n-1][i]=s[n-1][i]=='*';
        ford(j,n-2,0)
            d[j][i]=(s[j][i]=='*'?d[j+1][i]+1:0);
    }
    for0(i,n)
        for0(j,m)
            ans[i][j]=max(0ll,min({l[i][j],r[i][j],u[i][j],d[i][j]})-1);
    for0(i,n)
    {
        int cnt;
        cnt=0;
        fort1(j,0,m-1)
        {
            if(ans[i][j])
                cnt=max(cnt,ans[i][j]+1);
            b[i][j]|=cnt>0;
            cnt--;
        }
        cnt=0;
        ford(j,m-1,0)
        {
            if(ans[i][j])
                cnt=max(cnt,ans[i][j]+1);
            b[i][j]|=cnt>0;
            cnt--;
        }
    }
    for0(j,m)
    {
        int cnt;
        cnt=0;
        fort1(i,0,n-1)
        {
            if(ans[i][j])
                cnt=max(cnt,ans[i][j]+1);
            b[i][j]|=cnt>0;
            cnt--;
        }
        cnt=0;
        ford(i,n-1,0)
        {
            if(ans[i][j])
                cnt=max(cnt,ans[i][j]+1);
            b[i][j]|=cnt>0;
            cnt--;
        }
    }
    #define DEB(x) IFD( { cout<<#x<<":\n"; for0(i,n) { for0(j,m) cout<<x[i][j]; cout<<"\n"; } cout<<"\n"; } )
    DEB(s);
    DEB(l);
    DEB(r);
    DEB(u);
    DEB(d);
    DEB(ans);
    DEB(b);
    for0(i,n)
        for0(j,m)
            if(s[i][j]=='*'&&!b[i][j])
                halt(-1);
    int cnt=0;
    for0(i,n)
        for0(j,m)
            cnt+=bool(ans[i][j]);
    cout<<cnt<<"\n";
    for0(i,n)
        for0(j,m)
            if(ans[i][j])
                cout<<i+1<<" "<<j+1<<" "<<ans[i][j]<<"\n";

    IFD(cout<<"\n\nTIME: "<<runtime<<" sec\n\n";)
}