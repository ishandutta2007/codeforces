#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, maxm = 20;
const long long inf = 1e15;
int s[maxn], m;
pair<int, int> op[maxn];
long long dp[1 << maxm];
bool v[1 << maxm];

long long go(int mask) {
    if (__builtin_popcount(mask) == 0) return 0;
    if (v[mask]) return dp[mask];
    int t = m - __builtin_popcount(mask);
    dp[mask] = (op[t].first == 1 ? -inf : inf);
    for (int i = 0; i < m; ++i) if ((1 << i) & mask) {
        if (op[t].first == 1 && op[t].second == 1) dp[mask] = max(dp[mask], go(mask ^ (1 << i)));
        if (op[t].first == 1 && op[t].second == 2) dp[mask] = max(dp[mask], s[i] + go(mask ^ (1 << i)));
        if (op[t].first == 2 && op[t].second == 1) dp[mask] = min(dp[mask], go(mask ^ (1 << i)));
        if (op[t].first == 2 && op[t].second == 2) dp[mask] = min(dp[mask], -s[i] + go(mask ^ (1 << i)));
    }
    v[mask] = true;
    return dp[mask];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    sort(s, s + n); reverse(s, s + n);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        char bp; int t; cin >> bp >> t;
        op[i] = (bp == 'b' ? make_pair(t, 1) : make_pair(t, 2));
    }
    cout << go((1 << m) - 1) << endl;
    return 0;
}