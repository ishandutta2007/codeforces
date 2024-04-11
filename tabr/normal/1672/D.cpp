#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    auto Rle = [&](const vector<int> &x) {
        vector<pair<int, int>> y;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && x[i] == x[j]) {
                j++;
            }
            y.emplace_back(x[i], j - i);
        }
        return y;
    };
    auto c = Rle(b);
    auto d = Rle(a);
    vector<int> cnt(n + 1);
    string ans = "YES";
    for (int i = 0, j = 0; i < (int) c.size(); i++) {
        while (j < (int) d.size() && c[i].first != d[j].first) {
            cnt[d[j].first] -= d[j].second;
            if (cnt[d[j].first] < 0) {
                ans = "NO";
                break;
            }
            j++;
        }
        if (j == (int) d.size()) {
            ans = "NO";
            break;
        }
        cnt[c[i].first] += c[i].second;
        cnt[d[j].first] -= d[j].second;
        if (cnt[c[i].first] < 0) {
            ans = "NO";
            break;
        }
        j++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}