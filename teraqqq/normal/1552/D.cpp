#include <bits/stdc++.h>
#include <cassert>

#define F first
#define S second

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

int n, a[13];

bool dfs(int s = 0, int flag = 0, int i = 0) {
    if (i == n) {
        if (s == 0 && flag == 1) return true;
    } else {
        if (dfs(s, flag, i+1)) return true;
        if (dfs(s+a[i], 1, i+1)) return true;
        if (dfs(s-a[i], 1, i+1)) return true;
    }
    return false;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << (dfs() ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}