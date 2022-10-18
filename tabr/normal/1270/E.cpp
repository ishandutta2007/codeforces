#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<ll, ll>> z(n);
    rep(i, 0, n) {
        ll x, y;
        cin >> x >> y;
        z[i] = make_pair(x + 1e6, y + 1e6);
    }

    while (true) {
        vector<vector<ll>> cnt(2, vector<ll>(2));
        for (auto p : z)
            cnt[p.first % 2][p.second % 2]++;

        if (cnt[1][0] + cnt[0][1] > 0 && cnt[0][0] + cnt[1][1] > 0) {
            vector<ll> a;
            rep(i, 0, n) if ((z[i].first + z[i].second) % 2 == 0)
                a.emplace_back(i + 1);
            cout << a.size() << endl;
            for (auto b : a)
                cout << b << ' ';
            cout << endl;
            return 0;
        }
        if (cnt[0][0] + cnt[0][1] > 0 && cnt[1][0] + cnt[1][1] > 0) {
            vector<ll> a;
            rep(i, 0, n) if ((z[i].first) % 2 == 0) a.emplace_back(i + 1);
            cout << a.size() << endl;
            for (auto b : a)
                cout << b << ' ';
            cout << endl;
            return 0;
        }

        ll x, y;
        rep(i, 0, 2) rep(j, 0, 2) if (cnt[i][j] > 0) x = i, y = j;

        for (auto &p : z)
            p.first = (p.first - x) / 2, p.second = (p.second - y) / 2;
    }

    return 0;
}