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

void solve() {
    int n; cin >> n;
    vector<int> a(201), b(201);
    for (int i = n; i--; ) { int x; cin >> x; a[x+100]++; }
    for (int i = n; i--; ) { int x; cin >> x; b[x+100]++; }

    bool ok = true;
    for (int i = 0; i < 200; ++i) {
        if (a[i] < b[i]) { ok = false; break; }
        b[i+1] -= a[i] - b[i];
        if (b[i+1] < 0) { ok = false; break; }
    }

    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}