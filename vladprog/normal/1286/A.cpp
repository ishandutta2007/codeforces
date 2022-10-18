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

const int N=110;

int p[N],dp[N][N][N][2];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int cnt[2]={};
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        if(p[i])
            cnt[p[i]%2]++;
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<=n;k++)
                dp[i][j][k][0]=dp[i][j][k][1]=1e9;
    if(p[1])
        dp[1][0][0][p[1]%2]=0;
    else
        dp[1][1][0][0]=dp[1][0][1][1]=0;
    #define upd(x,y) /*cout<<#x<<" min= "<<y<<"\n",*/ x=min(x,y)
    for(int i=1;i<=n-1;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<=n;k++)
                for(int r=0;r<=1;r++)
                {
//                    cout<<i<<" "<<j<<" "<<k<<" "<<r<<" -> "<<dp[i][j][k][r]<<"\n";
                    if(p[i+1])
                        upd(dp[i+1][j][k][p[i+1]%2],dp[i][j][k][r]+(r!=p[i+1]%2));
                    else
                        upd(dp[i+1][j+1][k][0],dp[i][j][k][r]+(r!=0)),
                        upd(dp[i+1][j][k+1][1],dp[i][j][k][r]+(r!=1));
                }
    cout<<min(dp[n][n/2-cnt[0]][(n+1)/2-cnt[1]][0],dp[n][n/2-cnt[0]][(n+1)/2-cnt[1]][1]);
}