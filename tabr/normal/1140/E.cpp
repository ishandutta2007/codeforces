#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, k, mod = 998244353, ans = 1;
    cin >> n >> k;
    vector<ll> a(1), b(1);
    rep(i, 1, n + 1) {
        ll x;
        cin >> x;
        if (i % 2)
            a.emplace_back(x);
        else
            b.emplace_back(x);
    }
    a.emplace_back(0);
    b.emplace_back(0);

    rep(l, 0, a.size() - 1) {
        int r = l + 1;
        while (r + 1 < a.size() && a[r] == -1)
            r++;
        if (r - l == 1) {
            if (a[l] == a[r])
                ans = 0;
            continue;
        }
        vector<vector<ll>> cal(2, vector<ll>(r - l - 1));
        if (a[r] != a[l]) {
            cal[0][0] = k - 2;
            cal[1][0] = 1;
        } else {
            cal[0][0] = k - 1;
        }
        if (a[l] == 0)
            cal[0][0]++;
        rep(i, 0, r - l - 2) {
            cal[0][i + 1] = (k - 1) * cal[1][i] + (k - 2) * cal[0][i];
            cal[0][i + 1] %= mod;
            cal[1][i + 1] = cal[0][i];
        }
        if (a[r] == 0)
            cal[0][r - l - 2] += cal[1][r - l - 2];
        ans = ans * cal[0][r - l - 2] % mod;
        l = r - 1;
    }

    rep(l, 0, b.size() - 1) {
        int r = l + 1;
        while (r + 1 < b.size() && b[r] == -1)
            r++;
        if (r - l == 1) {
            if (b[l] == b[r])
                ans = 0;
            continue;
        }
        vector<vector<ll>> cal(2, vector<ll>(r - l - 1));
        if (b[r] != b[l]) {
            cal[0][0] = k - 2;
            cal[1][0] = 1;
        } else {
            cal[0][0] = k - 1;
        }
        if (b[l] == 0)
            cal[0][0]++;
        rep(i, 0, r - l - 2) {
            cal[0][i + 1] = (k - 1) * cal[1][i] + (k - 2) * cal[0][i];
            cal[0][i + 1] %= mod;
            cal[1][i + 1] = cal[0][i];
        }
        if (b[r] == 0)
            cal[0][r - l - 2] += cal[1][r - l - 2];

        ans = ans * cal[0][r - l - 2] % mod;
        l = r - 1;
    }
    cout << ans << endl;

    return 0;
}