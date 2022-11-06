#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
const int mod[] = { 479001599, 433494437, 1073807359, 1442968193, 715827883 };
const int p[] = { 101, 233, 457, 173, 211, 727, 701 };
int ms, ps;

long long pr[maxn], g[maxn];

inline int add(int a, int b) { return a + b >= mod[ms] ? a + b - mod[ms] : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod[ms] : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod[ms]; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    ms = rand() % 5; ps = 6;
    int n, m; cin >> n >> m; pr[0] = 1;
    for (int i = 1; i <= n; ++i) pr[i] = pr[i - 1] * p[ps];
    while (m--) {
        int a, b; cin >> a >> b;
        g[a] += pr[b]; g[b] += pr[a];
    }
    map<long long, int> c;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) ++c[g[i]];
    for (auto it : c) ans += it.second * 1ll * (it.second - 1);
    c.clear();
    for (int i = 1; i <= n; ++i) ++c[g[i] + pr[i]];
    for (auto it : c) ans += it.second * 1ll * (it.second - 1);
    cout << ans / 2 << endl;
}