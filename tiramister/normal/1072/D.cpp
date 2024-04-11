#include <iostream>
#include <queue>
#include <string>
#include <tuple>

using namespace std;
const int INF = 1 << 25;

int main() {
    int N, K;
    cin >> N >> K;

    string S[N];
    for (int i = 0; i < N; ++i) cin >> S[i];

    int dist[N][N];
    fill(dist[0], dist[N], INF);
    dist[0][0] = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> que;
    que.push(make_pair(0, make_pair(0, 0)));

    while (!que.empty()) {
        int d, x, y;
        d = que.top().first;
        tie(x, y) = que.top().second;
        que.pop();
        if (dist[x][y] < d) continue;
        if (S[x][y] != 'a') ++d;

        for (int i = 1; i <= 2; ++i) {
            int nx = x + (i & 1), ny = y + (i >> 1);
            if (nx >= N || ny >= N || dist[nx][ny] <= d) continue;
            dist[nx][ny] = d;
            que.push(make_pair(d, make_pair(nx, ny)));
        }
    }

    if (dist[N - 1][N - 1] + (S[N - 1][N - 1] == 'a' ? 0 : 1) <= K) {
        cout << string(N * 2 - 1, 'a') << endl;
        return 0;
    }

    int d = -1;
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            if (dist[x][y] <= K) d = max(d, x + y);
        }
    }

    queue<pair<int, int>> q;
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            if (dist[x][y] <= K && x + y == d) q.push(make_pair(x, y));
        }
    }

    string ans = string(d, 'a');

    bool visited[N][N];
    fill(visited[0], visited[N], false);

    while (!q.empty()) {
        char c = 'z';
        int s = q.size();
        for (int i = 0; i < s; ++i) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            c = min(c, S[x][y]);
            q.push(make_pair(x, y));
        }

        queue<pair<int, int>> nq;
        while (!q.empty()) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            if (S[x][y] > c) continue;

            for (int i = 1; i <= 2; ++i) {
                int nx = x + (i & 1), ny = y + (i >> 1);
                if (nx >= N || ny >= N || visited[nx][ny]) continue;
                nq.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
        ans.push_back(c);
        swap(q, nq);
    }

    cout << ans << endl;
    return 0;
}