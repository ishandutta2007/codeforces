#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

void solve() {
    int n, m; cin >> n >> m; ++m;

    int x = 0;
    int ans = 0;
    for (int i = 30; i--; ) {
        ans = 2 * ans;
        if ((n>>i) & 1) {
            if ((~m>>i) & 1) {
                ans <<= i;
                break;
            }
        } else {
            if ((m>>i) & 1) ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--) solve();
}