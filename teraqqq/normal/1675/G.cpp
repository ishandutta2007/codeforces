#include <bits/stdc++.h>

using namespace std;

const int N = 300;
const int INF = 1e9;

int dp[N][N][N], ps[N];

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }

int main() {
    for (int i = N; i--; )
    for (int j = N; j--; ) {
        fill(dp[i][j], dp[i][j]+N, INF);
    }
    
    dp[0][0][0] = 0;

    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; ++i) ps[i+1] = ps[i] + a[i];

    for (int i = 0; i < n; ++i) {
        for (int s0 = 0; s0 <= m; ++s0) {
            vector<int> b = a;

            if (ps[i] < s0) {
                int t = s0 - ps[i];
                for (int j = i; j < n; ++j) {
                    while (t > 0 && b[j] > 0) --b[j], --t;
                }
            } else {
                b[i] += ps[i] - s0;
            }

            int u = INF, cost = 0;
            for (int k = 0, j = i+1; s0 + k <= m; ++k) {
                ckmin(u, dp[i][s0][k]);

                if (k <= b[i]) {
                    ckmin(dp[i+1][s0+k][k], u + b[i] - k);
                } else {
                    assert(b[i] + 1 == k);
                    b[i]++;
                    while (b[j] == 0) ++j;
                    b[j]--;
                    cost += j - i;
                    ckmin(dp[i+1][s0+k][k], u + cost);
                }
            }
        }
    }

    const int ans = *min_element(dp[n][m], dp[n][m] + N);
    cout << ans  << endl;
}