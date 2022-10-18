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

const int N=5e5+100;

int k;
vector<pair<int,int>> g[N];
int dp[N][2];

void dfs(int v,int p)
{
    int ans=0;
    vector<int> add;
    for(auto to:g[v])
        if(to.first!=p)
        {
            dfs(to.first,v);
            ans+=dp[to.first][1];
            add.push_back(dp[to.first][0]+to.second-dp[to.first][1]);
        }
    sort(add.begin(),add.end(),greater<int>());
    while(!add.empty()&&add.back()<0)
        add.pop_back();
    dp[v][0]=ans+accumulate(add.begin(),add.begin()+min<int>(k-1,add.size()),0ll);
    dp[v][1]=ans+accumulate(add.begin(),add.begin()+min<int>(k,add.size()),0ll);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<=n-1;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        dfs(1,0);
        cout<<dp[1][1]<<"\n";
    }
}