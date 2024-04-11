#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10, inf = 1e9 + 1;
long long x[maxn], h;
long double p, dp[maxn][maxn][2][2];
bool v[maxn][maxn][2][2];

double go(int l, int r, int dl, int dr) {
    if (l > r) return 0.0;
    if (v[l][r][dl][dr]) return dp[l][r][dl][dr];
    v[l][r][dl][dr] = true;
    if (l == r) {
        dp[l][r][dl][dr] = 0.0;
        if (dl == 0 && x[l] - x[l - 1] < h) {
            if (dr == 0) return dp[l][r][dl][dr] = min(h, x[r + 1] - x[r]);
            else return dp[l][r][dl][dr] = min(max(0ll, x[r + 1] - x[r] - h), h);
        }
        if (dr == 1 && x[r + 1] - x[r] < h) {
            if (dl == 1) return dp[l][r][dl][dr] = min(h, x[l] - x[l - 1]);
            else return dp[l][r][dl][dr] = min(max(0ll, x[l] - x[l - 1] - h), h);
        }
        if (dl == 1) dp[l][r][dl][dr] += p * min(x[l] - x[l - 1], h);
        else dp[l][r][dl][dr] += p * min(max(0ll, x[l] - x[l - 1] - h), h);
        if (dr == 0) dp[l][r][dl][dr] += (1 - p) * min(x[r + 1] - x[r], h);
        else dp[l][r][dl][dr] += (1 - p) * min(max(0ll, x[r + 1] - x[r] - h), h);
        return dp[l][r][dl][dr];
    }
    if (dl == 0 && x[l] - x[l - 1] < h) {
        return dp[l][r][dl][dr] = go(l + 1, r, 0, dr) + min(h, x[l + 1] - x[l]);
    }
    if (dr == 1 && x[r + 1] - x[r] < h) {
        return dp[l][r][dl][dr] = go(l, r - 1, dl, 1) + min(h, x[r] - x[r - 1]);
    }
    dp[l][r][dl][dr] = 0.0;
    if (dl == 1) dp[l][r][dl][dr] += 0.5 * p * (go(l + 1, r, 1, dr) + min(x[l] - x[l - 1], h));
    else dp[l][r][dl][dr] += 0.5 * p * (go(l + 1, r, 1, dr) + min(max(0ll, x[l] - x[l - 1] - h), h));
    dp[l][r][dl][dr] += 0.5 * (1 - p) * (go(l + 1, r, 0, dr) + min(x[l + 1] - x[l], h));
    if (dr == 0) dp[l][r][dl][dr] += 0.5 * (1 - p) * (go(l, r - 1, dl, 0) + min(x[r + 1] - x[r], h));
    else dp[l][r][dl][dr] += 0.5 * (1 - p) * (go(l, r - 1, dl, 0) + min(max(0ll, x[r + 1] - x[r] - h), h));
    dp[l][r][dl][dr] += 0.5 * p * (go(l, r - 1, dl, 1) + min(x[r] - x[r - 1], h));
    return dp[l][r][dl][dr];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    memset(v, false, sizeof(v));
    int n; cin >> n >> h >> p;
    x[0] = -inf; x[n + 1] = inf;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    sort(x, x + n + 2);
    cout << fixed << setprecision(20) << go(1, n, 1, 0) << endl;
    return 0;
}