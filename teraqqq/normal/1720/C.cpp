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
    int ans = 0;
    int n, m; cin >> n >> m;
    vector a(n, vi(m));

    for (auto& w : a) {
        string s; cin >> s;
        for (int i = 0; i < m; ++i) {
            w[i] = s[i] - '0';
        }
    }

    int dob = -2;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
        if (!a[i][j]) dob = -1;
    }

    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
        ans += a[i][j];
        if (i != 0 && !a[i][j] && !a[i-1][j]) dob = 0;
        if (j != 0 && !a[i][j] && !a[i][j-1]) dob = 0;
        if (i != 0 && j != 0) {
            if (!a[i-1][j] && !a[i][j-1]) dob = 0;
            if (!a[i-1][j-1] && !a[i][j]) dob = 0;
        }
    }

    cout << ans + dob << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}