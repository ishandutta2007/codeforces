#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (int& x : a) cin >> x, cnt[x]++;

    bool ok = true;
    for (auto [x, k] : cnt) if (k % 2) ok = false;

    if (!ok) {
        cout << -1 << '\n';
        return;
    }

    vector<pi> ans;
    vector<int> t;

    while (!a.empty()) {
        int n = a.size();
        int i = a.size() - 2;
        while (a[i] != a.back()) --i;

        int u = i;
        for (int t = n - 2; t > i; --t) ans.emplace_back(u++, a[t]);

        t.push_back((n - i - 1) * 2);
        reverse(a.begin()+i, a.end()-1);
        a.pop_back();
        a.pop_back();
    }

    reverse(t.begin(), t.end());

    cout << ans.size() << '\n';
    for (auto [p, c] : ans) cout << p << ' ' << c << '\n';

    cout << t.size() << '\n';
    for (int x : t) cout << x << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1; 
    cin >> t;
    while (t--) solve();
}