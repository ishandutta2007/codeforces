#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7 + 10;
int x[maxn], c[maxn], mindiv[maxn];
bitset<maxn> v;
vector<int> pr;

void sieve() {
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) pr.push_back(i), mindiv[i] = pr.size() - 1;
        for (int j = 0; i * pr[j] < maxn; ++j) {
            v[i * pr[j]] = true;
            mindiv[i * pr[j]] = j;
            if (i % pr[j] == 0) break;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i];
    vector<int> npr;
    for (int i = 0; i < n; ++i) {
        int now = x[i];
        int ind = 0;
        while (now > 1) {
            int d = mindiv[now];
            while (now > 1 && now % pr[d] == 0) now /= pr[d];
            ++c[d];
        }
        if (now > 1) npr.push_back(now);
    }
    sort(npr.begin(), npr.end());
    // sort(pr.begin(), pr.end());
    for (int i = 1; i < pr.size(); ++i) c[i] += c[i - 1];
    int m; cin >> m; while (m--) {
        int l, r; cin >> l >> r;
        int ql = lower_bound(pr.begin(), pr.end(), l) - pr.begin() - 1;
        int qr = upper_bound(pr.begin(), pr.end(), r) - pr.begin() - 1;
        int ans = c[qr];
        if (ql >= 0) ans -= c[ql];
        int nqr = upper_bound(npr.begin(), npr.end(), r) - npr.begin() - 1;        
        int nql = lower_bound(npr.begin(), npr.end(), l) - npr.begin() - 1;
        ans += nqr - nql;
        cout << ans << '\n';
    }
    return 0;
}