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
#define MOD 1000000007
#define MAXN 1000005
typedef long long ll;
using namespace std;
ll i,j,k,z,q,timer, v,x,y,xx, yy,INF, sz,m, cnt, even, flag, ans;
vector<int> g[100500];
ll n,l,s, a[100500];
int dp[100500];
vector<pii> dpv[100500];

void dfs(int v) {
    dp[v] = 1;
    vector<pii> f;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        dfs(to);
        dp[v] += dp[to];
        for (int j = 0; j < dpv[to].size(); j++)
            f.push_back(dpv[to][j]);
    }
    sort(f.begin(), f.end());
    if (f.size() == 0) {
        dpv[v].push_back(mp(a[v], 1));
        return;
    }
    int minlen = 100500;
    int flag = 0;
    for (int i = 0; i < f.size(); i++) {
        if (f[i].Y + 1 <= l && f[i].X + a[v] <= s)
            flag = 1;
    }
    if (!flag) {
        dpv[v].push_back(mp(a[v], 1));
        return;
    }
    dp[v]--;
    for (int i = 0; i < f.size(); i++) {
        if (f[i].Y + 1 <= l && f[i].X + a[v] <= s && f[i].Y < minlen) {
            minlen = f[i].Y;
            dpv[v].push_back(mp(f[i].X+a[v], f[i].Y+1));
        }
    }
}
int main() {
    //freopen("input.txt", "r", stdin);

    cin >> n >> l >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > s) {
            cout << -1 << endl;
            return 0;
        }
    }
    if (l == 1) {
        cout << n << endl;
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        cin >> x;
        g[x].push_back(i);
    }
    dfs(1);
    cout << dp[1] << endl;
    return 0;
}