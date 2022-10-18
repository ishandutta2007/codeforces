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

typedef pair<ld,int> num;
#define man first
#define exp second

const int MOD=1e9+7;

int ppow(int x,int y)
{
    if(y==0)
        return 1;
    if(y%2)
        return ppow(x,y-1)*x%MOD;
    int p=ppow(x,y/2);
    return p*p%MOD;
}

num ppow(num x,int y)
{
    if(y==0)
        return num(1,0);
    num p;
    if(y%2)
    {
        p=ppow(x,y-1);
        p.man*=x.man;
        p.exp+=x.exp;
    }
    else
    {
        num p=ppow(x,y/2);
        cout<<"ppow 0:\n";
        cout<<x.first<<" e "<<x.second<<"\n";
        cout<<y<<"\n";
        cout<<p.first<<" e "<<p.second<<"\n";
        cout<<"===\n";
        p.man=p.man*p.man;
        p.exp*=2;
    }
    cout<<"ppow 1:\n";
    cout<<x.first<<" e "<<x.second<<"\n";
    cout<<y<<"\n";
    cout<<p.first<<" e "<<p.second<<"\n";
    cout<<"===\n";
    while(p.man>=10)
        p.man/=10,p.exp++;
    cout<<"ppow 2:\n";
    cout<<x.first<<" e "<<x.second<<"\n";
    cout<<y<<"\n";
    cout<<p.first<<" e "<<p.second<<"\n";
    cout<<"===\n";
    return p;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x,y;
    cin>>x>>y;/*
    num xx=num(x,0);
    while(xx.man>=10)
        xx.man/=10,xx.exp++;
    num yy=num(y,0);
    while(yy.man>=10)
        yy.man/=10,yy.exp++;
    num aa=ppow(xx,y);
    num bb=ppow(yy,x);
    int a=ppow(x,y);
    int b=ppow(y,x);
    cout<<xx.first<<" e "<<xx.second<<"\n";
    cout<<yy.first<<" e "<<yy.second<<"\n";
    cout<<aa.first<<" e "<<aa.second<<"\n";
    cout<<bb.first<<" e "<<bb.second<<"\n";
    if(a==b)
        cout<<"=";
    else if(aa.exp<bb.exp||(aa.exp==bb.exp&&aa.man<bb.man))
        cout<<"<";
    else
        cout<<">";*/
    if(x==y)
        cout<<"=";
    else
    if(x<=10&&y<=10)
    {
        int a=round(pow(x,y)),b=round(pow(y,x));
        if(a==b)
            cout<<"=";
        else if(a<b)
            cout<<"<";
        else
            cout<<">";
    }
    else if(x==1)
        cout<<"<";
    else if(y==1)
        cout<<">";
    else if(x>y)
        cout<<"<";
    else
        cout<<">";
}