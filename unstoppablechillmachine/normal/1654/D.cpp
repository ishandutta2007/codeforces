#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

const int mod = 998244353;
void add(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int mul(int a, int b) {
    return (a * 1ll * b) % mod;
}

int b_pow(int a, int b) {
    if (!b) {
        return 1;
    }
    if (b & 1) {
        return mul(a, b_pow(a, b - 1));
    }
    return b_pow(mul(a, a), b / 2);
}

int inv(int x) {
    return b_pow(x, mod - 2);
}

map<int, int> current_dels;
map<int, int> mx;
const int N = 2e5 + 10;
vector<pair<int, pair<int, int>>> g[N];
vector<pair<int, int>> factorization[N];
void dfs(int v, int parent = 0) {
    for (auto it : g[v]) {
        int u = it.first;
        if (u != parent) {
            for (auto [p, alpha] : factorization[it.second.first]) {
                current_dels[p] += alpha;
            }
            for (auto [p, alpha] : factorization[it.second.second]) {
                current_dels[p] -= alpha;
                mx[p] = max(mx[p], -current_dels[p]);
            }
            dfs(u, v);
            for (auto [p, alpha] : factorization[it.second.first]) {
                current_dels[p] -= alpha;
            }
            for (auto [p, alpha] : factorization[it.second.second]) {
                current_dels[p] += alpha;
            }
        }
    }
}

int sum;
void dfs2(int v, int cur, int parent = 0) {
    add(sum, cur);
    for (auto it : g[v]) {
        if (it.first != parent) {
            dfs2(it.first, mul(cur, mul(it.second.first, inv(it.second.second))), v);
        }
    }
}

signed main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 2; i <= 200000; i++) {
        int cur = i;
        for (int j = 2; j * j <= cur; j++) {
            if (cur % j == 0) {
                factorization[i].emplace_back(j, 0);
                while (cur % j == 0) {
                    factorization[i].back().second++;
                    cur /= j;
                }
            }
        }
        if (cur > 1) {
            factorization[i].emplace_back(cur, 1);
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            g[i] = {};
        }
        current_dels = {};
        mx = {};
        for (int i = 1; i < n; i++) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            g[u].push_back({v, {y, x}});
            g[v].push_back({u, {x, y}});
        }
        dfs(1);
        int a = 1;
        for (auto it : mx) {
            a = mul(a, b_pow(it.first, it.second));
        }
        sum = 0;
        dfs2(1, a);
        cout << sum << '\n';
    }
}