#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

//#define DEBUG
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
#define runtime (clock()*1.0/CLOCKS_PER_SEC)
#define x first
#define y second

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int ll

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef set<int> si;
typedef set<int> sll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;

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
    return out<<"("<<p.x<<","<<p.y<<")";
}

template<class Iter>
struct rng
{
    Iter from,to;
    rng(Iter from,Iter to):from(from),to(to){}
};

template<class Iter>
rng<Iter> range(Iter from,Iter to)
{
    return rng<Iter>(from,to);
}

template<class Iter>
ostream&operator<<(ostream&out,rng<Iter> r)
{
    out<<distance(r.from,r.to)<<":";
    for(Iter i=r.from;i!=r.to;i++)
        out<<" "<<*i;
    return out;
}

signed main()
{
    IFN
    (
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    )
    
    int n,k;
    cin>>n>>k;
    int ans=0;
    while(n--)
    {
        int y;
        cin>>y;
        if(y+k<=5)
            ans++;
    }
    cout<<ans/3;
    
    IFD(cout<<"\n\nTIME: "<<runtime<<" sec\n\n";)
}