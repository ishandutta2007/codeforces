#include <bits/stdc++.h>

#define F first
#define S second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;
using ll = long long;

template<class T> bool ckmin(T&a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T&a, const T& b) { return a < b ? a = b, true : false; }

template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;
template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;

const int INF = 1e9+7;

void solve() {
    int n; cin >> n;
    map<int, int> cnt;

    for (int i = n; i--; ) {
        int x; cin >> x;
        cnt[x]++;
    }

    int c = 0, x = -1;
    for (auto [y, k] : cnt) {
        if (ckmax(c, k)) x = y;
    }

    int ans = 0;

    while (c < n) {
        ++ans;
        ans += min(n-c, c);
        c += min(n-c, c);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}