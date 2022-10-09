// 617E
// XOR and Favorite Number

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18
#define maxn 100010
#define pb push_back

ll i, i1, j, k, k1, t, n, m, res, f[maxn], flag[10], a[maxn], b, l, r, sq, c[1048586];
vector<array<ll, 5>> q;

void upd(ll d, ll l, ll r) {
    // cout << d << ' ' << l << ' ' << r << endl;
    if (d == 0) {
        c[a[l]]--;
        res -= c[k ^ a[l]];
    } else if (d == 1) {
        l--;
        res += c[k ^ a[l]];
        c[a[l]]++;
    } else if (d == 2) {
        c[a[r]]--;
        res -= c[k ^ a[r]];
    } else {
        r++;
        res += c[k ^ a[r]];
        c[a[r]]++;
    }
    // cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> m >> k;
    sq = sqrt(n);
    a[0] = 0;
    for (i = 1; i <= n; i++) {
        cin >> a[i]; a[i] ^= a[i - 1];
    }
    for (i = 0; i < m; i++) {
        cin >> l >> r; l--;
        q.push_back({l / sq, r, l, i, 0});
    }

    sort(q.begin(), q.end());
    for (auto &u : q) swap(u[0], u[2]);

    for (i = 0; i < (1 << 20); i++) c[i] = 0;
    l = 1; r = 0; res = 0;
    for (auto &u : q) {
        while (r > u[1]) {
            upd(2, l, r); r--;
        }
        while (r < u[1]) {
            upd(3, l, r); r++;
        }
        while (l < u[0]) {
            upd(0, l, r); l++;
        }
        while (l > u[0]) {
            upd(1, l, r); l--;
        }
        u[4] = res;
    }

    for (auto u : q) f[u[3]] = u[4];

    for (i = 0; i < m; i++) {
        cout << f[i] << endl;
    }

    return 0;
}