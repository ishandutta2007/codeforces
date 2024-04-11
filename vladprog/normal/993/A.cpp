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

void mov(int&x,int&y)
{
    int tx=x-y,ty=x+y;
    x=tx,y=ty;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ax[5],ay[5],bx[5],by[5];
    cin>>ax[1]>>ay[1]>>ax[2]>>ay[2]>>ax[3]>>ay[3]>>ax[4]>>ay[4];
    cin>>bx[1]>>by[1]>>bx[2]>>by[2]>>bx[3]>>by[3]>>bx[4]>>by[4];
    for(int i=1;i<=4;i++)
        for(int j1=1;j1<=4;j1++)
            for(int j2=1;j2<=4;j2++)
                for(int k1=1;k1<=4;k1++)
                    for(int k2=1;k2<=4;k2++)
                        if(ax[j1]<=bx[i]&&bx[i]<=ax[j2]&&
                           ay[k1]<=by[i]&&by[i]<=ay[k2])
                            cout<<"Yes",exit(0);
    for(int i=1;i<=4;i++)
        mov(bx[i],by[i]);
    for(int x=-100;x<=100;x++)
        for(int y=-100;y<=100;y++)
        {
            bool okaxl=false;
            for(int i=1;i<=4;i++)
                if(ax[i]<=x)
                    okaxl=true;
            bool okaxr=false;
            for(int i=1;i<=4;i++)
                if(ax[i]>=x)
                    okaxr=true;
            bool okayl=false;
            for(int i=1;i<=4;i++)
                if(ay[i]<=y)
                    okayl=true;
            bool okayr=false;
            for(int i=1;i<=4;i++)
                if(ay[i]>=y)
                    okayr=true;
            int tx=x,ty=y;
            mov(x,y);
            bool okbxl=false;
            for(int i=1;i<=4;i++)
                if(bx[i]<=x)
                    okbxl=true;
            bool okbxr=false;
            for(int i=1;i<=4;i++)
                if(bx[i]>=x)
                    okbxr=true;
            bool okbyl=false;
            for(int i=1;i<=4;i++)
                if(by[i]<=y)
                    okbyl=true;
            bool okbyr=false;
            for(int i=1;i<=4;i++)
                if(by[i]>=y)
                    okbyr=true;
            x=tx,y=ty;
            if(okaxl&&okaxr&&okayl&&okayr&&okbxl&&okbxr&&okbyl&&okbyr)
                cout<<"Yes",exit(0);
        }
    for(int i=1;i<=4;i++)
        mov(ax[i],ay[i]),
        swap(ax[i],bx[i]),
        swap(ay[i],by[i]);
    for(int i=1;i<=4;i++)
        for(int j1=1;j1<=4;j1++)
            for(int j2=1;j2<=4;j2++)
                for(int k1=1;k1<=4;k1++)
                    for(int k2=1;k2<=4;k2++)
                        if(ax[j1]<=bx[i]&&bx[i]<=ax[j2]&&
                           ay[k1]<=by[i]&&by[i]<=ay[k2])
                            cout<<"Yes",exit(0);
    cout<<"No";
}