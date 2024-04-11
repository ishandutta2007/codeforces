#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

const int INF = 1 << 25;

template <typename T>
inline T sq(T a) { return a * a; }

template <typename T>
inline bool inrange(T l, T r, T x) { return l <= x && x <= r; }

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int main() {
    int N, sx, sy, gx, gy;
    cin >> N >> sx >> sy >> gx >> gy;
    --sx, --sy, --gx, --gy;

    if (sx == gx && sy == gy) {
        cout << 0 << endl;
        return 0;
    }

    vector<string> S(N);
    for (auto& s : S) cin >> s;

    queue<pair<int, int>> que;
    que.push(make_pair(sx, sy));
    S[sx][sy] = '*';
    while (!que.empty()) {
        int x, y;
        tie(x, y) = que.front();
        que.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (inrange(0, N - 1, nx) && inrange(0, N - 1, ny) && S[nx][ny] == '0') {
                S[nx][ny] = '*';
                que.push(make_pair(nx, ny));
            }
        }
    }

    que.push(make_pair(gx, gy));
    S[gx][gy] = '#';
    while (!que.empty()) {
        int x, y;
        tie(x, y) = que.front();
        que.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (inrange(0, N - 1, nx) && inrange(0, N - 1, ny)) {
                if (S[nx][ny] == '*') {
                    cout << 0 << endl;
                    return 0;
                } else if (S[nx][ny] == '0') {
                    S[nx][ny] = '#';
                    que.push(make_pair(nx, ny));
                }
            }
        }
    }

    int ans = INF;
    for (sx = 0; sx < N; ++sx) {
        for (sy = 0; sy < N; ++sy) {
            if (S[sx][sy] != '*') continue;

            for (gx = 0; gx < N; ++gx) {
                for (gy = 0; gy < N; ++gy) {
                    if (S[gx][gy] == '#') {
                        ans = min(ans, sq(gx - sx) + sq(gy - sy));
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}