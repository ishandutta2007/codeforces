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
    int n, z; cin >> n >> z;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ans = max(ans, x | z);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}