#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 1e6 + 5;
mt19937 rng(time(0));

int n, x, sel[N];
bool v[N];
vector<int> a[N], g[N];

void dfs(int x, int d) {
    v[x] = true;
    sel[x] = d % 2 + 1;
    for (auto u : g[x])
        if (!v[u])
            dfs(u, d + 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    if (n % 2 == 0) {
        cout << "First" << endl;
        rep(i, 1, n * 2) cout << (i - 1) % n + 1 << " ";
        cout << endl;
    } else {
        cout << "Second" << endl;
        rep(i, 1, n * 2) cin >> x, a[x].PB(i);
        rep(i, 1, n) g[i].PB(i + n), g[i + n].PB(i);
        rep(i, 1, n) {
            int x = a[i][0], y = a[i][1];
            if (x % n != y % n)
                g[x].PB(y), g[y].PB(x);
        }
        memset(v, 0, sizeof v);
        rep(i, 1, n * 2) if (!v[i]) dfs(i, 0);
        LL sum = 0;
        rep(i, 1, n * 2) if (sel[i] == 1) sum += 1ll * i;
        if (sum % (2 * n) == 0) {
            rep(i, 1, n * 2) if (sel[i] == 1) cout << i << " ";
        } else {
            rep(i, 1, n * 2) if (sel[i] == 2) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}