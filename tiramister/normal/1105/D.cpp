#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

const int INF = 1 << 30;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

template <typename T>
T iceil(T n, T d) {
    return (n + d - 1) / d;
}

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    int s[N];
    for (int i = 0; i < N; ++i) cin >> s[i];

    string S[H];
    for (int x = 0; x < H; ++x) cin >> S[x];

    int d[N][H][W];
    fill(d[0][0], d[N][0], INF);

    int whose[H][W];
    queue<pair<int, int>> que[N];
    for (int x = 0; x < H; ++x) {
        for (int y = 0; y < W; ++y) {
            if (S[x][y] == '.') {
                whose[x][y] = -1;
            } else if (S[x][y] == '#') {
                whose[x][y] = N;
            } else {
                int id = S[x][y] - '1';
                que[id].push(make_pair(x, y));
                whose[x][y] = id;
                d[id][x][y] = 0;
            }
        }
    }

    for (int t = 1; t <= 1000000; ++t) {
        for (int i = 0; i < N; ++i) {
            while (!que[i].empty()) {
                int x, y;
                tie(x, y) = que[i].front();
                if (d[i][x][y] == t * s[i]) break;
                que[i].pop();

                for (int j = 0; j < 4; ++j) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if (nx < 0 || H <= nx || ny < 0 || W <= ny || whose[nx][ny] >= 0) continue;

                    d[i][nx][ny] = d[i][x][y] + 1;
                    whose[nx][ny] = i;
                    que[i].push(make_pair(nx, ny));
                }
            }
        }

        if (all_of(que, que + N, [](queue<pair<int, int>> que) { return que.empty(); })) break;
    }

    int ans[N + 1];
    fill(ans, ans + N + 1, 0);
    for (int x = 0; x < H; ++x) {
        for (int y = 0; y < W; ++y) {
            if (whose[x][y] >= 0) ++ans[whose[x][y]];
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}