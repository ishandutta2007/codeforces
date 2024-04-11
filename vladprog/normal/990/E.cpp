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

const int N=1e6+100;
int a[N];
int r[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    set<int> s;
    for(int i=0;i<=n;i++)
        s.insert(i);
    while(m--)
    {
        int t;
        cin>>t;
        if(t==0)
            cout<<-1,exit(0);
        s.erase(t);
    }
    for(int i=1;i<=k;i++)
        cin>>a[i];
    int p=1;
    for(auto i=s.begin();i!=s.end();)
    {
        int p1=*i;
        i++;
        if(i==s.end())
            break;
        int p2=*i;
        p=max(p,p2-p1);
    }
    if(p>k)
        cout<<-1,exit(0);
    for(int x:s)
        r[x]=x;
    for(int i=0;i<=n;i++)
        if(r[i]==0&&i!=0)
            r[i]=r[i-1];
    int ans=1e18;
    for(int i=p;i<=k;i++)
    {
        int t=0,c=1;
        //cout<<i<<":\n";
        while(t!=n)
            t=r[min(t+i,n)],
            //cout<<t<<"\n";
            c++;
        c--;
        ans=min(ans,c*a[i]);
    }
    cout<<ans;
}