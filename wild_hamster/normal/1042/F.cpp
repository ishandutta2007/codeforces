#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
#define ROW 5
#define N 1000005
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,mx,l, v,tot,x,y,INF, sz,ans;
vector<int> g[1005000];
int dp[1005000];
void dfs(int v, int p = -1) {
    int cnt = 0;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != p) {
            dfs(to, v);
            cnt++;
        }
    }
    if (cnt == 0) {
        dp[v] = 1;
        return;
    }
    vector<ll> f;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != p)
            f.push_back(dp[to]);
    }
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());
    int tmp = 0;
    if (f[0] == 0)
        return;
    if (f.size() == 1) {
        tmp = f[0];
    } else {
        tmp = f.back();
        for (int i = 0; i + 1 < f.size(); i++) {
            if (f[i] + f[i+1] > k) {
                ans++;
            }
            else {
                tmp = f[i];
                break;
            }
        }
    }
    if (tmp == 0)
        return;
    tmp++;
    if (tmp > k || v == mx) {
            //cout << v << endl;
        dp[v] = 0;
        ans++;
    } else {
        dp[v] = tmp;
    }
    //cout << v << " " << dp[v] << endl;
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int v;
    for (int i = 1; i <= n; i++)
        if (g[i].size() > 1)
            v = i;
    mx = v;
    dfs(v);
    cout << ans << endl;
    return 0;
}