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
    vector<ll> a(n), b(n); for(ll& x : a) cin >> x;
    int t = 1, ans = 1;
    for (int i = 1; i < n; ++i) {
        b[i] = abs(a[i] - a[i-1]);
        for (int j = i-1; j > 0; --j) {
            ll prv = b[j];
            b[j] = __gcd(b[j], b[j+1]);
            if (b[j] == prv) break;
        }

        while (t <= i && b[t] == 1) ++t;

        if (t <= i) ckmax(ans, 2+i-t);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t; 
    while(t--) solve();
}