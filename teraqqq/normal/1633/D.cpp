#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

const int W = 1000;
const int INF = 1e9;
const int MAX_COST = 12;

int cost[W+1];

void solve() {
    int n, k; cin >> n >> k;
    vector<int> b(n); for (int& x : b) cin >> x;
    vector<int> c(n); for (int& x : c) cin >> x;

    k = min(k, n * MAX_COST);

    vector<int> dp(k+1), ndp(k+1);
    for (int i = 0; i < n; ++i) {
        copy(dp.begin(), dp.end(), ndp.begin());
        for (int j = 0; j + cost[b[i]] <= k; ++j) {
            ckmax(ndp[j+cost[b[i]]], dp[j] + c[i]);
        }
        swap(dp, ndp);
    }

    cout << dp.back() << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    fill(cost+2, cost+W+1, INF);
    for (int n = 1; n <= W; ++n) {
        for (int k = 1; k <= W; ++k) {
            const int m = n + n / k;
            if (m <= W) ckmin(cost[m], cost[n]+1);
        }
    }

    int t = 1; 
    cin >> t;
    while (t--) solve();
}