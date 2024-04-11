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
#define x first
#define y second

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

const int N=90,M=1e5+100,INF=1e18;

pii xs[N];
int x[N],s[N],dp[N][M];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>xs[i].x>>xs[i].y;
    sort(xs+1,xs+n+1);
    for(int i=1;i<=n;i++)
        x[i]=xs[i].x,
        s[i]=xs[i].y;
    for(int j=1;j<=m;j++)
        dp[0][j]=j;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int add=max(0ll,j-(x[i]+s[i]));
            int l=max(1ll,x[i]-s[i]-add);
            dp[i][j]=dp[i-1][l-1]+add;
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
        }
    cout<<dp[n][m];
}