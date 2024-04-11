#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 998244353;
const LL INF = 5e15 + 5;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n, x, y, z, w, p[N];
int fm, sum;
vector<array<int, 3>> g[N];
int pw[N], mapw[N];

int power(int x, int n) {
    int res = 1;
    for (; n; n >>= 1, x = 1ll * x * x % P)
        if (n & 1)
            res = 1ll * res * x % P;
    return res;
}
void calc(map<int, int> &mp, int x, int sgn) {
    while (x > 1)
        mp[p[x]] += sgn, x /= p[x];
}
void dfs(int x, int fa, int up, int down, int num) {
    sum = (sum + num) % P;
    map<int, int> mp;
    calc(mp, up, 1), calc(mp, down, -1);
    for (auto [p, k] : mp) {
        pw[p] += k;
        if (-pw[p] > mapw[p])
            fm = 1ll * fm * power(p, -pw[p] - mapw[p]) % P, mapw[p] = -pw[p];
    }
    for (auto [u, up, down] : g[x])
        if (u != fa)
            dfs(u, x, up, down, 1ll * num * up % P * power(down, P - 2) % P);
    for (auto [p, k] : mp)
        pw[p] -= k;
}

int main() {
    rep(i, 2, N - 1) if (!p[i]) for (int j = i; j <= N - 1; j += i) p[j] = i;
    ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) g[i].clear();
        rep(i, 1, n - 1) {
            cin >> x >> y >> z >> w;
            g[x].PB({y, w, z}), g[y].PB({x, z, w});
        }
        rep(i, 1, n) pw[i] = mapw[i] = 0;
        fm = 1, sum = 0;
        dfs(1, 0, 1, 1, 1);
        cout << 1ll * fm * sum % P << endl;
    }
    return 0;
}