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

set<int> pr{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511};

signed main()
{
    IFN
    (
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    )


    int n;
    cin>>n;
    int m=n;
    while(!pr.count(m))
        m++;
    cout<<m<<"\n";
    for(int i=1;i<=n;i++)
        cout<<i<<" "<<i%n+1<<"\n";
    m-=n;
    for(int i=1;i<=m;i++)
        cout<<i<<" "<<n-i<<"\n";


    IFD(cout<<fixed<<setprecision(10)<<"\n\nTIME: "<<runtime<<" sec\n\n";)
}