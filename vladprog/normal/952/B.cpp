#pragma GCC optimize("O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define DEBUG
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

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    map<string,int> norm=
    {
        {"no",5},
        {"great!",1},
        {"great",1},
        {"don't think so",1},
        {"dont think so",1},
        {"don't touch me!",1},
        {"dont touch me",1},
        {"not bad",1},
        {"cool",1}
    };
    map<string,int> grum=
    {
        {"no",3},
        {"don't even",1},
        {"dont even",1},
        {"are you serious?",1},
        {"are you serious",1},
        {"worse",1},
        {"go die in a hole",1},
        {"terrible",1},
        {"no way",2}
    };
    map<string,int> in;
    for(int i=0;i<=9;i++)
    {
        cout<<i<<endl;
        string s;
        getline(cin,s);
        in[s]++;
        if(norm[s]>=in[s]&&grum[s]<in[s])
            cout<<"normal"<<endl,exit(0);
        if(norm[s]<in[s]&&grum[s]>=in[s])
            cout<<"grumpy"<<endl,exit(0);
    }
}