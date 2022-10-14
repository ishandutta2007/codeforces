#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
#define N 8388607
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,l,timer,mx;
ll a[100500], b[100500], dp[100500][12][5];
ll dp2[100500][15];
vector<ll> g[100500];
void dfs(ll v, ll p = -1)
{
    ll cnt = 0;
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (to != p)
        {
            dfs(to, v);
            cnt++;
        }
    }
    if (cnt == 0)
    {
        dp[v][0][0] = k-1;
        dp[v][1][1] = 1;
        dp[v][0][2] = m-k;
        return;
    }
    //1..k-1
    ll pnt = 0;
    for (int i = 0; i <= g[v].size(); i++)
        for (int j = 0; j <= mx; j++)
            dp2[i][j] = 0;
    dp2[pnt][0] = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (to != p)
        {
            for (int j = 0; j <= mx; j++)
                for (int l = 0; l+j <= mx; l++)
                    dp2[pnt+1][j+l] = (dp2[pnt+1][j+l] + dp2[pnt][j]*(dp[to][l][0] + dp[to][l][1] + dp[to][l][2]))%MOD;
            pnt++;
        }
    }
    for (int j = 0; j <= mx; j++)
        dp[v][j][0] = dp2[pnt][j]*(k-1)%MOD;

    //k
    pnt = 0;
    for (int i = 0; i <= g[v].size(); i++)
        for (int j = 0; j <= mx; j++)
            dp2[i][j] = 0;
    dp2[pnt][0] = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (to != p)
        {
            for (int j = 0; j < mx; j++)
                for (int l = 0; l+j < mx; l++)
                    dp2[pnt+1][j+l] = (dp2[pnt+1][j+l] + dp2[pnt][j]*(dp[to][l][0]))%MOD;
            pnt++;
        }
    }
    for (int j = 0; j < mx; j++)
        dp[v][j+1][1] = dp2[pnt][j];

    //k+1..m
    pnt = 0;
    for (int i = 0; i <= g[v].size(); i++)
        for (int j = 0; j <= mx; j++)
            dp2[i][j] = 0;
    dp2[pnt][0] = 1;
    for (int i = 0; i < g[v].size(); i++)
    {
        ll to = g[v][i];
        if (to != p)
        {
            for (int j = 0; j <= mx; j++)
                for (int l = 0; l+j <= mx; l++)
                    dp2[pnt+1][j+l] = (dp2[pnt+1][j+l] + dp2[pnt][j]*(dp[to][l][0]+dp[to][l][2]))%MOD;
            pnt++;
        }
    }
    for (int j = 0; j <= mx; j++)
        dp[v][j][2] = dp2[pnt][j]*(m-k)%MOD;
}
int main() {

    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (i = 0; i < n-1; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> k >> mx;
    dfs(1);
    ll ans = 0;
    for (i = 0; i <= mx; i++)
    {
        ans += dp[1][i][0] + dp[1][i][1] + dp[1][i][2];
    }
    cout << ans%MOD << endl;
    return 0;
}