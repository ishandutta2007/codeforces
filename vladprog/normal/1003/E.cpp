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

const int N=4e5+100;

vector<int> g[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,d,k;
    cin>>n>>d>>k;
    if(d>n-1)
        cout<<"NO\n",exit(0);
    if(k==1)
        if(d==1&&n==2)
            cout<<"YES\n1 2\n",exit(0);
        else
            cout<<"NO\n",exit(0);
    queue<pii> q;
    for(int i=1;i<=d+1;i++)
        q.push(pii(i,min(i-1,d-i+1)));
    int c=d+1;
    while(c<n&&!q.empty())
    {
        pii p=q.front();
        int v=p.first,h=p.second;
        //cerr<<v<<" "<<h<<" ";
        if(h==0)
        {
            q.pop();
            continue;
        }
        int s=g[v].size();
        //cerr<<s<<" ";
        if(v<=d+1)
            s+=2;
        else
            s++;
        //cerr<<s<<"\n";
        if(s<k)
        {
            c++;
            q.push(pii(c,h-1));
            g[v].phb(c);
        }
        else
            q.pop();
    }
    if(c==n)
    {
        cout<<"YES\n";
        for(int i=1;i<=d;i++)
            cout<<i<<" "<<i+1<<"\n";
        for(int i=1;i<=n;i++)
            for(int to:g[i])
                cout<<i<<" "<<to<<"\n";
    }
    else
        cout<<"NO\n";
}