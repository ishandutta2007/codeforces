#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;
const long long inf = 1e18 + 1;
int t[4][maxn];
long long s[maxn], dp[4][maxn];

long long sum(int l, int r) {
    return s[r] - s[l - 1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        s[i] = s[i - 1] + a;
    }
    for (int i = 1; i <= n; ++i) {
        dp[0][i] = sum(1, i);
        dp[1][i] = dp[2][i] = dp[3][i] = -inf;
        for (int j = 0; j <= i; ++j) {
            if (dp[0][j] - sum(j + 1, i) > dp[1][i]) t[1][i] = j;
            if (dp[1][j] + sum(j + 1, i) > dp[2][i]) t[2][i] = j;
            if (dp[2][j] - sum(j + 1, i) > dp[3][i]) t[3][i] = j;
            dp[1][i] = max(dp[1][i], dp[0][j] - sum(j + 1, i));
            dp[2][i] = max(dp[2][i], dp[1][j] + sum(j + 1, i));
            dp[3][i] = max(dp[3][i], dp[2][j] - sum(j + 1, i));
        }
        // cout << dp[0][i] << ' ' << dp[1][i] << ' ' << dp[2][i] << ' ' << dp[3][i] << endl;
        // cout << t[0][i] << ' ' << t[1][i] << ' ' << t[2][i] << ' ' << t[3][i] << endl;
    }
    int now = t[3][n];
    int k = 2;
    stack<int> st;
    while (k >= 0) {
        st.push(now);
        now = t[k][now];
        --k;
    }
    while (st.size()) cout << st.top() << ' ', st.pop(); cout << endl;
    return 0;
}