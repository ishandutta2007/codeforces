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

const int N=5010;

int m;
vector<int> g[N];
int c[N];
int ans[N];

void dfs(int v)
{
    if(c[v]==1)
    {
        cout<<"2\n";
        for(int i=1;i<=m;i++)
            cout<<ans[i]<<" ";
        exit(0);
    }
    if(c[v]==2)
        return;
    c[v]=1;
    for(int to:g[v])
        dfs(to);
    c[v]=2;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        ans[i]=(a>b)+1;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
        dfs(i);
    cout<<"1\n";
    for(int i=1;i<=m;i++)
        cout<<"1 ";
}