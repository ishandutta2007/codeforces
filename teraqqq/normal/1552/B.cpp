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
    int n; cin >> n;
    vector<array<int, 5>> r(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) cin >> r[i][j];
    }

    auto cmp = [&](int i, int j) {
        int score = 0;
        for (int t = 0; t < 5; ++t) 
            if (r[i][t] < r[j][t]) score += 1;
        return score >= 3;
    };

    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (cmp(i, ans)) ans = i;
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (i != ans && cmp(i, ans)) ok = false;
    }

    cout << (ok ? ans + 1 : -1) << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}