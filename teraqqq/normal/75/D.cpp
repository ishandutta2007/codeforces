#include <bits/stdc++.h>

#define F first
#define S second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

const ll LINF = 1e18;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    vector<ll> s(n);
    vector a(n, vi());
    vector<ll> mx_suf(n, -LINF), mx_prf(n, -LINF), mx_sub(n, -LINF);
    vector<ll> mn_pref(n, LINF);

    ll ans = -LINF;

    for (int i = 0; i < n; ++i) {
        int c; cin >> c;
        a[i].resize(c);

        ll mx = 0;

        for (int& x : a[i]) {
            cin >> x;
            s[i] += x;

            ckmax(mx_sub[i], s[i] - mx);
            ckmax(mx_prf[i], s[i]);
            ckmin(mx, s[i]);
        }

        ll q = 0;
        for (int j = c; j--; ) {
            q += a[i][j];
            ckmax(mx_suf[i], q);
        }
    }

    ll ps = 0;
    vector<int> u(m);

    for (int i = 0; i < m; ++i) {
        cin >> u[i]; u[i]--;
        ckmax(ans, mx_sub[u[i]]);

        for (int j = 0; j < n; ++j) {
            ckmax(ans, max<ll>(0, mx_prf[u[i]]) + ps - mn_pref[j] + max<ll>(0, mx_suf[j]));
        }

        if (i != 0) {
            ckmax(ans, mx_prf[u[i]] + max<ll>(0, mx_suf[u[i-1]]));
            ckmax(ans, mx_suf[u[i-1]] + max<ll>(0, mx_prf[u[i]]));
            ckmin(mn_pref[u[i-1]], ps);
        }

        ps += s[u[i]];
    }

    cout << ans << endl;
}

// 3 3 -5 1 1 6 -2 -5 1