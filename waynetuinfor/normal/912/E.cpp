#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
const double eps = 1e-8;
int a[maxn], n, k;
vector<long long> v[2];

void dfs(int pos, int tar, long long now, int idx) {
    if (pos >= tar) return;
    long long tnow = now * a[pos];
    v[idx].push_back(now);
    for (int i = pos; i < tar; ++i) {
        if (now <= 1000000000000000000ll / a[i]) dfs(i, tar, now * a[i], idx);
        else break;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    cin >> k;
    // v[0].push_back(1); v[1].push_back(1);
    dfs(0, min(6, n / 2), 1, 0); dfs(min(6, n / 2), n, 1, 1);
    v[0].push_back(1);
    v[1].push_back(1);
    sort(v[0].begin(), v[0].end()); sort(v[1].begin(), v[1].end());
    v[0].resize(unique(v[0].begin(), v[0].end()) - v[0].begin());
    v[1].resize(unique(v[1].begin(), v[1].end()) - v[1].begin());
    // for (long long i : v[0]) cout << i << ' '; cout << endl;
    // for (long long i : v[1]) cout << i << ' '; cout << endl;
    int d = 62;
    long long ans = 1000000000000000000ll;
    while (d--) if (ans - (1ll << d) >= 1) {
        long long t = ans - (1ll << d);
        int cnt = 0;
        for (long long i : v[0]) {
            // cnt += v[1].size() - (v[1].end() - upper_bound(v[1].begin(), v[1].end(), t / i));
            cnt += upper_bound(v[1].begin(), v[1].end(), t / i) - v[1].begin();
        }
        // cout << "t = " << t << " cnt = " << cnt << endl;
        if (cnt >= k) ans -= (1ll << d);
    }
    cout << ans << endl;
    return 0;
}