#include <bits/stdc++.h>

#define F first
#define S second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

void solve() {
    int n; cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i], x[i] /= 2, y[i] /= 2;

    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        vector<int> cnt(4);
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            cnt[abs(x[i] - x[j])%2*2 + abs(y[i] - y[j])%2]++;
        }

        for (int a = 0; a < 4; ++a)
        for (int b = a; b < 4; ++b) {
            const int c = a ^ b;
            int s = max(a/2,a%2) + max(b/2,b%2) + max(c/2,c%2);
            if (s % 2 == 0) {
                if (a != b) ans += (ll) cnt[a] * cnt[b];
                else ans += (ll) (cnt[a] - 1) * cnt[a] / 2;
            }
        }
    }

    cout << ans/3 << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t; 
    while(t--) solve();
}