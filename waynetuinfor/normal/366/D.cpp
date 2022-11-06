#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e3 + 10;
int a[maxn], b[maxn], l[maxn], r[maxn], m, n;
vector<int> ord;

struct djset {
    int p[maxn];
    void init() { for (int i = 0; i < maxn; ++i) p[i] = i; }
    int find(int v) { return v == p[v] ? v : p[v] = find(p[v]); }
    void merge(int u, int v) { p[find(u)] = find(v); }
} djs;

bool check(int range) {
    for (int i = 0; i < m; ++i) {
        djs.init();
        for (int j = 0; j < m; ++j) {
            if (r[j] >= r[i] && l[j] <= r[i] - range + 1) djs.merge(a[j], b[j]);
        }
        if (djs.find(1) == djs.find(n)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) cin >> a[i] >> b[i] >> l[i] >> r[i];
    ord.resize(m); iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](const int &i, const int &j) { return r[i] < r[j]; });
    int d = 20, ans = 0; while (d--) if (ans + (1 << d) <= 1e6) if (check(ans + (1 << d))) ans += (1 << d);
    if (ans == 0) cout << "Nice work, Dima!" << endl;
    else cout << ans << endl;
    return 0;
}