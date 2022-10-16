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
    ll hc, dc, hm, dm; cin >> hc >> dc >> hm >> dm;
    int k; ll w, a; cin >> k >> w >> a;

    bool ans = false;
    hc += k * a;
    for (int i = 0; i <= k; ++i) {
        ll tm = (hm + dc - 1) / dc;
        ll tc = (hc + dm - 1) / dm;

        if (tm <= tc) {
            ans = true;
            break;
        }

        hc -= a;
        dc += w;
    }

    cout << (ans ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1; 
    cin >> t;
    while (t--) solve();
}