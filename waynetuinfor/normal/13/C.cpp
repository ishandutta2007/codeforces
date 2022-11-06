#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;
const long long inf = 1e18;
long long dp[2][maxn], s[2][maxn];
int a[maxn], ord[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> vec;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        vec.push_back(a[i]);
    }
    sort(vec.begin(), vec.end()); vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        fill(dp[cur], dp[cur] + maxn, inf);
        for (int j = 1; j <= vec.size(); ++j) {
            dp[cur][j] = dp[cur ^ 1][j] + abs(a[i] - vec[j - 1]);
        }
        for (int j = 1; j <= vec.size(); ++j) dp[cur][j] = min(dp[cur][j], dp[cur][j - 1]);
        cur ^= 1;
    } 
    long long ans = inf;
    for (int i = 1; i <= vec.size(); ++i) ans = min(ans, dp[cur ^ 1][i]);
    cout << ans << endl;
    return 0;
}