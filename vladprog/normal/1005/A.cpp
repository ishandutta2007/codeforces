#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

//#define DEBUG
#ifdef DEBUG
    #define IFD(...) __VA_ARGS__
    #define IFN(...)
    #define L cerr<<__LINE__<<"\n";
    #define PRINT(...) __VA_ARGS__ cerr<<__LINE__<" : "<<#__VA_ARGS__<<"\n"
    #define PRT(x) cerr<<__LINE__<<" : "<<#x<<" = "<<x<<"\n"
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
#define runtime (clock()*1.0/CLOCKS_PER_SEC)

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int ll

typedef long long ll;
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
    vector<int> ans;
    int p=0;
    while(n--)
    {
        int a;
        cin>>a;
        if(a==1)
            ans.phb(p);
        p=a;
    }
    cout<<ans.size()<<"\n";
    for(int x:ans)
        if(x!=0)
            cout<<x<<" ";
    cout<<p;
    
    IFD(cerr<<"\n\nTIME: "<<runtime<<" sec\n\n";)
}