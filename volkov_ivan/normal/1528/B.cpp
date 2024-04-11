#include <bits/stdc++.h>
#define int long long

using namespace std;

const int M = 998244353, N = 1e6 + 7;
int pow2[N];

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    pow2[0] = pow2[1] = 1;
    for (int i = 2; i < N; i++)
        pow2[i] = (pow2[i - 1] * 2) % M;

    int ans = 0;
    for (int len = 1; len <= n; len++) {
        for (int t = len; t <= n; t += len) {
            ans = ans + pow2[n - t];
        }
        ans %= M;
    }
    cout << ans << endl;
    return 0;
}