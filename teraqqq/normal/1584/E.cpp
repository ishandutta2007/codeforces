#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define eb emplace_back

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

const ll LINF = 1e18;

ll solve(const vector<int>& a, int l, int r) {
    if (l + 1 == r) return a[l] == 0 ? 1 : 0;

    int m = (l + r) / 2;

    ll mn = 0, mx = LINF, s = 0, ans = 0;
    int sgn = 1;

    map<ll, int> cnt;

    for (int i = m - 1; i >= l; --i) {
        if (s + mn <= a[i] && s + mx >= a[i]) cnt[sgn * (a[i] - s)]++;
        sgn = -sgn;

        s = a[i] - s;
        ckmin(mx, s);
        swap(mn, mx); mn *= -1, mx *= -1;
    }

    mn = 0, mx = LINF, s = 0;
    sgn = 1;

    for (int i = m; i < r; ++i) {
        if (s + mn <= a[i] && s + mx >= a[i]) ans += cnt[sgn * (a[i] - s)];

        sgn = -sgn;
        s = a[i] - s;
        ckmin(mx, s);
        swap(mn, mx); mn *= -1, mx *= -1;
    }

    ans += solve(a, l, m);
    ans += solve(a, m, r);

    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    ll ans = solve(a, 0, n);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}