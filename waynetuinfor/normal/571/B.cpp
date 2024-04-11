#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10, maxk = 5000 + 10;
const long long inf = 1e15 + 1;
long long dp[maxk][maxk];
int a[maxn], n, k;
bool v[maxk][maxk];

long long go(int b, int s) {
    if (b == 0 && s == 0) return 0;
    if (v[b][s]) return dp[b][s];
    int last = b * (n / k + 1) + s * (n / k);
    dp[b][s] = inf;
    if (last - n / k >= 1 && b > 0) dp[b][s] = min(dp[b][s], go(b - 1, s) + a[last] - a[last - n / k]);
    if (last - n / k + 1 >= 1 && s > 0) dp[b][s] = min(dp[b][s], go(b, s - 1) + a[last] - a[last - n / k + 1]);
    v[b][s] = true;
    return dp[b][s];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    int big = n % k, sml = k - big;
    cout << go(big, sml) << endl;
    return 0;
}