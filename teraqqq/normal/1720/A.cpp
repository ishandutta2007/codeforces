#include <bits/stdc++.h>

#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T>;

void solve() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll p = a * d, q = b * c;

    if (p == q) {
        cout << 0 << '\n';
    } else {
        if (p == 0 || q % p == 0 || p % q == 0) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}