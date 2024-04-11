#pragma GCC optimize("O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

#define DEBUG
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

#define x first
#define y second

const int N=1e6+100;

int last,cnt1[N],cnt2[N],cnt3[N];

void check1()
{
    #define cnt cnt1
    unordered_map< int , unordered_map<int,int> > m;
    vector<pii> vis;
    m[0][0]=0;
    vis.phb(pii(0,0));
    int p=4,xl=0,xr=0,yl=0,yr=0;
    for(int i=1;i<=last+1;i++)
    {
        if(cnt[i]<0||cnt[i]>p)
            return;
        p=cnt[i];
        #define add(x,y) m[x][y]=i, \
                         xl=min(xl,x), \
                         xr=max(xr,x), \
                         yl=min(yl,y), \
                         yr=max(yr,y), \
                         vis.phb(pii(x,y))//, cerr<<x<<" "<<y<<" <- "<<i<<"\n"
        if(cnt[i]>=1)
            add(i,0ll);
        if(cnt[i]>=2)
            add(0ll,i);
        if(cnt[i]>=3)
            add(-i,0ll);
        if(cnt[i]>=4)
            add(0ll,-i);
        #undef add
        vector<pii> tvis;
        for(pii xy:vis)
        {
            int x=xy.x,y=xy.y;
            #define add(x,y) if(!m[x][y]&&(x||y)&&xl<=x&&x<=xr&&yl<=y&&y<=yr) \
                                 m[x][y]=i+1, \
                                 tvis.phb(pii(x,y)), \
                                 cnt[i+1]--//, cerr<<x<<" "<<y<<" <- "<<i+1<<"\n"
            add(x,y+1);
            add(x+1,y);
            add(x,y-1);
            add(x-1,y);
            #undef add
        }
        vis=tvis;
    }
    cout<<xr-xl+1<<" "<<yr-yl+1<<"\n"<<xr+1<<" "<<yr+1;
    exit(0);
    #undef cnt
}

void check2()
{
    #define cnt cnt2
    unordered_map< int , unordered_map<int,int> > m;
    vector<pii> vis;
    m[0][0]=0;
    vis.phb(pii(0,0));
    int p=4,xl=0,xr=0,yl=0,yr=0;
    for(int i=1;i<=last+1;i++)
    {
        if(cnt[i]<0||cnt[i]>p)
            return;
        p=cnt[i];
        #define add(x,y) m[x][y]=i, \
                         xl=min(xl,x), \
                         xr=max(xr,x), \
                         yl=min(yl,y), \
                         yr=max(yr,y), \
                         vis.phb(pii(x,y))//, cerr<<x<<" "<<y<<" <- "<<i<<"\n"
        if(cnt[i]>=1)
            add(i,0ll);
        if(cnt[i]>=2)
            add(-i,0ll);
        if(cnt[i]>=3)
            add(0ll,i);
        if(cnt[i]>=4)
            add(0ll,-i);
        #undef add
        vector<pii> tvis;
        for(pii xy:vis)
        {
            int x=xy.x,y=xy.y;
            #define add(x,y) if(!m[x][y]&&(x||y)&&xl<=x&&x<=xr&&yl<=y&&y<=yr) \
                                 m[x][y]=i+1, \
                                 tvis.phb(pii(x,y)), \
                                 cnt[i+1]--//, cerr<<x<<" "<<y<<" <- "<<i+1<<"\n"
            add(x,y+1);
            add(x+1,y);
            add(x,y-1);
            add(x-1,y);
            #undef add
        }
        vis=tvis;
    }
    cout<<xr-xl+1<<" "<<yr-yl+1<<"\n"<<xr+1<<" "<<yr+1;
    exit(0);
    #undef cnt
}

void check3()
{
    #define cnt cnt3
    unordered_map< int , unordered_map<int,int> > m;
    vector<pii> vis;
    m[0][0]=0;
    vis.phb(pii(0,0));
    int p=4,xl=0,xr=0,yl=0,yr=0;
    for(int i=1;i<=last+1;i++)
    {
        if(cnt[i]<0||cnt[i]>p)
            return;
        p=cnt[i];
        #define add(x,y) m[x][y]=i, \
                         xl=min(xl,x), \
                         xr=max(xr,x), \
                         yl=min(yl,y), \
                         yr=max(yr,y), \
                         vis.phb(pii(x,y))//, cerr<<x<<" "<<y<<" <- "<<i<<"\n"
        if(cnt[i]>=1)
            add(i,0ll);
        if(cnt[i]>=2)
            add(0ll,i);
        if(cnt[i]>=3)
            add(0ll,-i);
        if(cnt[i]>=4)
            add(-i,0ll);
        #undef add
        vector<pii> tvis;
        for(pii xy:vis)
        {
            int x=xy.x,y=xy.y;
            #define add(x,y) if(!m[x][y]&&(x||y)&&xl<=x&&x<=xr&&yl<=y&&y<=yr) \
                                 m[x][y]=i+1, \
                                 tvis.phb(pii(x,y)), \
                                 cnt[i+1]--//, cerr<<x<<" "<<y<<" <- "<<i+1<<"\n"
            add(x,y+1);
            add(x+1,y);
            add(x,y-1);
            add(x-1,y);
            #undef add
        }
        vis=tvis;
    }
    cout<<xr-xl+1<<" "<<yr-yl+1<<"\n"<<xr+1<<" "<<yr+1;
    exit(0);
    #undef cnt
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    int n,m,x,y;
//    cin>>n>>m>>x>>y;
//    x--,y--;
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a;
//        a=abs(x-i%n)+abs(y-i/n);
        cin>>a;
        last=max(last,a);
        cnt1[a]++;
        cnt2[a]++;
        cnt3[a]++;
    }
    if(cnt1[0]!=1)
        cout<<-1,exit(0);
    check1();
    //cerr<<"===\n";
    check2();
    //cerr<<"===\n";
    check3();
    cout<<-1;
}

/**
36
0
1 1
2 2 2
3 3 3 3
4 4 4 4 4
5 5 5 5 5 5
6 6 6 6 6
7 7 7 7
8 8 8
9 9
10

*/