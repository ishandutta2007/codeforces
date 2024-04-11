#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
 
using namespace std;
 
long long dp[4001][4001];
long long a[4001];

vector<long long> solve(int l, int r, int m) {
    if (l == r) {
        return {0, a[l] * m - a[l]};
    }
    int mid = dp[l][r];
    vector<long long> le, ri;
    if (mid == r) {
        le = solve(l, r - 1, m), ri = solve(r, r, m);
    }
    else {
        le = solve(l, mid, m), ri = solve(mid + 1, r, m);
    }
    vector<long long> ans(r - l + 2);
    for (int eval = 1; eval <= r - l + 1; eval++) {
        int mn = eval - ri.size() + 1, mx = le.size() - 1;
        mn = max(mn, 0);
        mx = min(mx, eval);
        for (int x = mn; x <= mx; x++) {
            ans[eval] = max(ans[eval], le[x] + ri[eval - x] - x * 1LL * (eval - x) * 1LL * a[mid] * 2);
        }
    }
    return ans;
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) dp[i][j] = i;
            else {
                dp[i][j] = dp[i][j - 1];
                if (a[j] < a[dp[i][j - 1]]) {
                    dp[i][j] = j;
                }
            }
        }
    }
    cout << solve(0, n - 1, m)[m] << "\n";
}