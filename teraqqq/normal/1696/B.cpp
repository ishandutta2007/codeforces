#include <bits/stdc++.h>

#define F first
#define S second

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    bool hasZero = false, allZero = true;

    int l = 0, r = n;
    while (l < n && a[l] == 0) l++;
    while (r > 0 && a[r-1] == 0) r--;

    for (int i = l; i < r; ++i) {
        const int x = a[i];
        if (x == 0) hasZero = true;
        if (x != 0) allZero = false;
    }

    cout << (allZero ? 0 : (hasZero ? 2 : 1)) << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}