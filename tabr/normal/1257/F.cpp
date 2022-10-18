#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(10);

    int n;
    cin >> n;
    vector<int> a(n), a1(n), a2(n);
    rep(i, 0, n) {
        cin >> a[i];
        a1[i] = a[i] >> 15;
        a2[i] = a[i] ^ (a1[i] << 15);
    }

    map<vector<int>, int> mp;
    rep(i, 0, 1 << 15) {
        vector<int> cnt(n);
        rep(j, 0, n) cnt[j] = __builtin_popcount(a1[j] ^ i);
        vector<int> r;
        rep(j, 1, n) {
            r.emplace_back(cnt[j] - cnt[0]);
        }
        mp[r] = i + 1;
    }
    rep(i, 0, 1 << 15) {
        vector<int> cnt(n);
        rep(j, 0, n) cnt[j] = __builtin_popcount(a2[j] ^ i);
        vector<int> r, r2;
        rep(j, 1, n) {
            r.emplace_back(cnt[0] - cnt[j]);
            r2.emplace_back(cnt[j] - cnt[0]);
        }
        if (mp[r] != 0) {
            int j = mp[r] - 1;
            j <<= 15;
            j += i;
            cout << j << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}