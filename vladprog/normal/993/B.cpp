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

#define int ll

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

#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    pii a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].x>>a[i].y;
        if(a[i].x>a[i].y)
            swap(a[i].x,a[i].y);
    }
    pii b[m];
    for(int i=0;i<m;i++)
    {
        cin>>b[i].x>>b[i].y;
        if(b[i].x>b[i].y)
            swap(b[i].x,b[i].y);
    }
    set<int> s;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(a[i]==b[j])
                continue;
            if(a[i].x==b[j].x||a[i].x==b[j].y)
                s.insert(a[i].x);
            if(a[i].y==b[j].x||a[i].y==b[j].y)
                s.insert(a[i].y);
        }
    if(s.size()==1)
        cout<<*s.begin(),exit(0);
    for(int i=0;i<n;i++)
    {
        s.clear();
        for(int j=0;j<m;j++)
        {
            if(a[i]==b[j])
                continue;
            if(a[i].x==b[j].x||a[i].x==b[j].y)
                s.insert(a[i].x);
            if(a[i].y==b[j].x||a[i].y==b[j].y)
                s.insert(a[i].y);
        }
        if(s.size()>1)
            cout<<-1,exit(0);
    }
    for(int j=0;j<m;j++)
    {
        s.clear();
        for(int i=0;i<n;i++)
        {
            if(a[i]==b[j])
                continue;
            if(a[i].x==b[j].x||a[i].x==b[j].y)
                s.insert(a[i].x);
            if(a[i].y==b[j].x||a[i].y==b[j].y)
                s.insert(a[i].y);
        }
        if(s.size()>1)
            cout<<-1,exit(0);
    }
    cout<<0;
}