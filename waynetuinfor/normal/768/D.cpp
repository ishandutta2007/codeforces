#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
const double eps = 1e-7;
double dp[(int)(1e4 + 10)][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int k, q; cin >> k >> q;
    dp[0][0] = 1.0;
    for (int day = 1; day < 1e4 + 10; ++day) {
        for (int orb = 1; orb <= k; ++orb) {
            dp[day][orb] = (double)(k - orb + 1) / (double)k * dp[day - 1][orb - 1] + (double)(orb) / (double)k * dp[day - 1][orb];
        }
    }
    while (q--) {
        int p; cin >> p;
        for (int i = 1; i < 1e4 + 10; ++i) {
            if (dp[i][k] >= ((double)p - eps) / (double)2000) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}