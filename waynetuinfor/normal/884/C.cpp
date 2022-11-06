#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int p[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    vector<int> c;
    for (int i = 1; i <= n; ++i) if (!v[i]) {
        int now = i, sz = 0;
        while (!v[now]) v[now] = true, now = p[now], ++sz;
        c.push_back(sz);
    }
    sort(c.begin(), c.end()); reverse(c.begin(), c.end());
    if (c.size() == 1) return cout << n * 1ll * n << endl, 0;
    c[1] += c[0];
    long long ans = 0;
    for (int i = 1; i < c.size(); ++i) ans += c[i] * 1ll * c[i];
    cout << ans << endl;
    return 0;
}