#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

const int INF = 1 << 25;
const int way[2] = {2, 5};
const int dx[2] = {0, 1};
const int dy[2] = {1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int a[N][N];
    int zx = -1, zy = -1;
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            cin >> a[x][y];
            if (a[x][y] == 0) zx = x, zy = y;
        }
    }

    int rev[3][N][N];
    int ans[3];
    string pat = "";

    for (int i = 0; i < 2; ++i) {
        int c[N][N];
        int v = way[i];
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                if (a[x][y] == 0) {
                    c[x][y] = INF;
                    continue;
                }
                c[x][y] = 0;
                while (a[x][y] % v == 0) {
                    a[x][y] /= v;
                    ++c[x][y];
                }
            }
        }

        int dist[N][N];
        fill(dist[0], dist[N], INF);
        dist[0][0] = c[0][0];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> que;
        que.push(make_pair(c[0][0], make_pair(0, 0)));

        while (!que.empty()) {
            int d = que.top().first;
            int x, y;
            tie(x, y) = que.top().second;
            que.pop();
            if (d > dist[x][y]) continue;

            for (int j = 0; j < 2; ++j) {
                int nx = x + dx[j], ny = y + dy[j];
                if (nx < 0 || N <= nx || ny < 0 || N <= ny || dist[nx][ny] <= d + c[nx][ny]) continue;
                rev[i][nx][ny] = j;
                dist[nx][ny] = d + c[nx][ny];
                que.push(make_pair(dist[nx][ny], make_pair(nx, ny)));
            }
        }

        ans[i] = dist[N - 1][N - 1];
    }

    ans[2] = INF;
    if (zx >= 0) {
        ans[2] = 1;
        int x = 0, y = 0;
        while (x < zx) {
            ++x;
            rev[2][x][y] = 1;
        }
        while (y < N - 1) {
            ++y;
            rev[2][x][y] = 0;
        }
        while (x < N - 1) {
            ++x;
            rev[2][x][y] = 1;
        }
    }

    int i = min_element(ans, ans + 3) - ans;
    int x = N - 1, y = N - 1;
    while (x > 0 || y > 0) {
        int j = rev[i][x][y];
        pat.push_back("RD"[j]);
        x -= dx[j], y -= dy[j];
    }
    reverse(pat.begin(), pat.end());

    cout << ans[i] << endl
         << pat << endl;
    return 0;
}