#pragma GCC optimize("O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define mp make_pair
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front

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

const int N=4e5+100,INF=1e18;

vector<pair<int,int>> g[N];
int dist[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,c;
    cin>>n>>c;
    for(int i=1;i<=n;i++)
        g[i].push_back(mp(n+i,0)),
        g[n+i].push_back(mp(i,c));
    for(int i=1;i<=n-1;i++)
    {
        int a;
        cin>>a;
        g[n+i].push_back(mp(n+i+1,a));
        g[n+i+1].push_back(mp(n+i,a));
    }
    for(int i=1;i<=n-1;i++)
    {
        int b;
        cin>>b;
        g[i].push_back(mp(i+1,b));
        g[i+1].push_back(mp(i,b));
    }
    for(int i=1;i<=2*n;i++)
        dist[i]=INF;
    dist[n+1]=0;
    set<pair<int,int>> s;
    s.insert(mp(0,n+1));
    while(!s.empty())
    {
        int v=s.begin()->second;
        s.erase(s.begin());
        for(auto p:g[v])
        {
            int to=p.first,len=p.second;
            int nxt=dist[v]+len;
            if(nxt<dist[to])
            {
                s.erase(mp(dist[to],to));
                dist[to]=nxt;
                s.insert(mp(dist[to],to));
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<dist[n+i]<<" ";
}