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

void solve() {
    int n, k; cin >> n >> k;

    vector<int> used(2*n);
    vector<vi> v(n);

    for (int i = 0; i < k; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        if (a > b) swap(a, b);
        v[i] = vi { a , b };
        used[a]++;
        used[b]++;
    }

    int x = 0;
    for (int u = 0; u < 2; ++u)
    for (int i = k; i < n; ++i) {
        while (used[x] != 0) ++x;
        used[x]++;
        v[i].push_back(x++);
    }

    for (int i = 0; i < n; ++i) {
        if (v[i].size() != 2 || v[i][0] >= v[i][1]) exit(0);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < i; ++j) {
        if (v[i][0] <= v[j][0] && v[j][1] <= v[i][1]) continue;
        if (v[j][0] <= v[i][0] && v[i][1] <= v[j][1]) continue;
        if (v[j][1] <= v[i][0] || v[i][1] <= v[j][0]) continue;
        ++ans;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}