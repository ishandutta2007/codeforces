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

const int N=2e5+100;

pii ai[N];
int a[N],dp[N][6];
int cnt[N];
int ans[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>ai[i].x,ai[i].y=i;
    sort(ai+1,ai+n+1);
    for(int i=1;i<=n;i++)
        a[i]=ai[i].x;
    for(int i=1;i<=n+1;i++)
    {
        tie(dp[i][1],cnt[i-1])=min({mp(dp[i-1][3],3),mp(dp[i-1][4],4),mp(dp[i-1][5],5)});
        for(int j=2;j<=5;j++)
            if(j<=i)
                dp[i][j]=dp[i-j+1][1]+a[i]-a[i-j+1];
            else
                dp[i][j]=1e18;
    }
    cout<<dp[n+1][1]<<" ";
    int k=0;
    for(int i=n;i>=1;)
    {
        k++;
        int j=i-cnt[i]+1;
        for(int l=j;l<=i;l++)
            ans[ai[l].y]=k;
        i=j-1;
    }
    cout<<k<<"\n";
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
}