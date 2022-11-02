#include <iostream>
#include <deque>

using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

int main() {
    int N, K, X;
    cin >> N >> K >> X;

    ll a[N + 1];
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    ll dp[X + 1][N + 1];
    // dp[x][i] = ixi
    fill(dp[0], dp[1], -INF);
    dp[0][0] = 0;

    for (int x = 1; x <= X; ++x) {
        dp[x][0] = -INF;

        deque<pair<int, ll>> que;
        // j in [i - K, i)dp[x - 1][j]

        que.push_back(make_pair(0, dp[x - 1][0]));
        for (int i = 1; i <= N; ++i) {
            if (!que.empty()) dp[x][i] = que.front().second + a[i];

            // deque(i, dp[x - 1][i])
            while (!que.empty() && que.back().second < dp[x - 1][i]) que.pop_back();
            que.push_back(make_pair(i, dp[x - 1][i]));

            // 
            if (que.front().first <= i - K) que.pop_front();
        }
    }

    ll ans = -1;
    for (int i = max(0, N - K + 1); i <= N; ++i) {
        ans = max(ans, dp[X][i]);
    }
    cout << (ans < 0 ? -1 : ans) << endl;
    return 0;
}