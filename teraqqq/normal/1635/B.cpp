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
    int m = 0;
    for (int& x : a) cin >> x;
    for (int i = 1; i+1 < n; ++i) {
        if (a[i] > a[i-1] && a[i] > a[i+1]) {
            if (i+2 < n) {
                a[i+1] = max(a[i], a[i+2]);
            } else {
                a[i+1] = a[i];
            }
            m++;
        }
    }

    cout << m << '\n';
    for (int x : a) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1; 
    cin >> t;
    while (t--) solve();
}