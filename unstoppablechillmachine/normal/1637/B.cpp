#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S secondond
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int N = 110;
int a[N], dp[N][N];
int used[1010];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int answer = 0;
        for (int i = 0; i < 1010; i++) {
            used[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] = min(a[i], 1000ll);
            dp[i][i] = 1 + (a[i] == 0);
            answer += dp[i][i];
        }
        int timer = 0;
        for (int len = 2; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                timer++;
                for (int i = l; i <= r; i++) {
                    used[a[i]] = timer;
                }
                int kek = 0;
                while (used[kek] == timer) {
                    kek++;
                }
                dp[l][r] = 1 + kek;
                for (int k = l; k < r; k++) {
                    dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
                }
                answer += dp[l][r];
            }
        }
        cout << answer << '\n';
    }
}