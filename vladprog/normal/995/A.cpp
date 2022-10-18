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
//#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
//#define phb push_back
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

const int N=200;

int a[5][N];

struct out
{
    int ind,x,y;
    out(){}
    out(int ind,int x,int y):ind(ind),x(x),y(y){}
};

int n;

pii nex(pii t)
{
    if(t==pii{2,n})
        return pii{3,n};
    if(t==pii{3,1})
        return pii{2,1};
    if(t.x==2)
        t.y++;
    else
        t.y--;
    return t;
}

pii pre(pii t)
{
    if(t==pii{3,n})
        return pii{2,n};
    if(t==pii{2,1})
        return pii{3,1};
    if(t.x==2)
        t.y--;
    else
        t.y++;
    return t;
}

out v[20010];
int s=0;

void phb(out t)
{
    //if(s==20000) cout<<-1,exit(0);
    v[s++]=t;
    //cerr<<t.ind<<" "<<t.x<<" "<<t.y<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin>>n>>k;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    while(true)
    {
        bool no=true,all=true;
        pii zero;
        for(int j=1;j<=n;j++)
        {
            if(a[2][j]!=0&&a[2][j]==a[1][j])
                phb(out(a[2][j],1,j)),
                a[2][j]=0;
            if(a[3][j]!=0&&a[3][j]==a[4][j])
                phb(out(a[3][j],4,j)),
                a[3][j]=0;
            if(a[2][j]==0)
                all=false,
                zero={2,j};
            else
                no=false;
            if(a[3][j]==0)
                all=false,
                zero={3,j};
            else
                no=false;
        }
        if(all)
            cout<<-1,exit(0);
        if(no)
        {
            cout<<s<<"\n";
            for(int i=0;i<s;i++)
            {
                out t=v[i];
                cout<<t.ind<<" "<<t.x<<" "<<t.y<<"\n";
            }
            exit(0);
        }
        for(pii t=nex(zero);t!=zero;t=nex(t))
        {
            if(a[t.x][t.y]!=0)
            {
                pii pt=pre(t);
                phb(out(a[t.x][t.y],pt.x,pt.y));
                swap(a[t.x][t.y],a[pt.x][pt.y]);
            }
            //if(t==zero||n==1) break;
        }
        //cerr<<"===\n";
    }
}