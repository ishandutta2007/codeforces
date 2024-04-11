#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
const int INF = 1 << 30;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int main() {
    int N, M, sx, sy, l, r;
    cin >> N >> M >> sx >> sy >> l >> r;
    --sx, --sy;

    string S[N];
    for (int x = 0; x < N; ++x) cin >> S[x];

    int dp[N][M];
    fill(dp[0], dp[N], INF);

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> que;
    que.push(make_pair(0, make_pair(sx, sy)));
    dp[sx][sy] = 0;

    while (!que.empty()) {
        int d = que.top().first;
        int x, y;
        tie(x, y) = que.top().second;
        que.pop();
        if (dp[x][y] > d) continue;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            int cost = d + max(0, dy[i]);
            if (nx < 0 || N <= nx || ny < 0 || M <= ny || S[nx][ny] == '*' || dp[nx][ny] <= cost) continue;
            dp[nx][ny] = cost;
            que.push(make_pair(cost, make_pair(nx, ny)));
        }
    }

    int ans = 0;
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < M; ++y) {
            if (dp[x][y] <= r && sy + dp[x][y] - y <= l) ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}