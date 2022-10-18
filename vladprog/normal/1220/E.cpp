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

const int N=2e5+100;

int w[N];
vector<int> g[N];
bool used[N],cyc[N];

bool dfs1(int v,int p)
{
    used[v]=true;
    for(int to:g[v])
        if(to!=p&&(used[to]||dfs1(to,v)))
            cyc[v]=true;
    return cyc[v];
}

int dfs2(int v,int p)
{
    used[v]=true;
    int ans=0;
    for(int to:g[v])
        if(!used[to])
            ans=max(ans,dfs2(to,v));
    if(!cyc[v])
        ans+=w[v];
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>w[i];
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int s;
    cin>>s;
    dfs1(s,0);
    memset(used,0,sizeof(used));
    int ans=0;
    for(int i=1;i<=n;i++)
        if(cyc[i])
            ans+=w[i];
    cout<<ans+dfs2(s,0);
}