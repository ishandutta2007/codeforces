#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef int ll;
using namespace std;
#define MAXN 300500
#define OFF 200001
#define MOD 1000000007
ll N;
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll a[3][205000];
ll d[3005][3005], w[3005][3005], curw[3005];
long long dp[3005][3005];
pii t[3005][3005];
vector<ll> g[3005], f;
ll Abs(ll x) {
    return x > 0 ? x : -x;
}

void dfs(ll v, ll lvl, ll p = -1) {
    f.push_back(v);
    d[root][v] = lvl;
    d[v][root] = lvl;
    curw[v] = 1;
    if (f.size() > 1) {
        t[root][v] = mp(f[1], f[lvl - 1]);
    }
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, lvl + 1, v);
        curw[v] += curw[to];
    }
    if (p != -1) {
        w[v][p] = curw[v];
    }
    f.pop_back();
}

vector<pii> gg[3005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        //x = i+1; y = i+2;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        f.clear();
        root = i;
        dfs(i, 0);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] > 0) {
                gg[d[i][j]].push_back(mp(i, j));
            }
        }
    }


    long long ans = 0;
    for (int j = 1; j <= 3000; j++) {
        for (auto p : gg[j]) {
            ll x = p.X;
            ll y = p.Y;
            ll px = t[x][y].X;
            ll py = t[x][y].Y;
            ll ad = (w[x][px]) * (w[y][py]);
            dp[x][y] = max(dp[px][y], dp[x][py]) + ad;
            ans = max(ans, dp[x][y]);
        }
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    cout << ans << "\n";



    return 0;

}