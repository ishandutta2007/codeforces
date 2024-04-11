#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

const int dx[4] = {+1, -1, +1, -1};
const int dy[4] = {+1, -1, -1, +1};

constexpr int N = 4000;
int cnt[2 * N + 1][2 * N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    cnt[N][N] = n;
    queue<array<int, 2>> q;

    if (n >= 4) {
        cnt[N][N] -= 4;
        q.push({N, N});
    }

    while (not empty(q)) {
        queue<array<int, 2>> qnxt;
        while (not empty(q)) {
            auto [x, y] = q.front();
            q.pop();
            for (int t = 0; t < 4; ++t) {
                int nx = x + dx[t], ny = y + dy[t];
                cnt[nx][ny] += 1;
                if (cnt[nx][ny] >= 4 && (nx != N || ny != N)) {
                    cnt[nx][ny] -= 4;
                    qnxt.push({nx, ny});
                }
            }
        }
        if (cnt[N][N] >= 4) {
            cnt[N][N] -= 4;
            qnxt.push({N, N});
        }
        swap(q, qnxt);
    }

    for (int i = 0; i < t; ++i) {
        int x, y;
        cin >> x >> y;
        x = abs(x), y = abs(y);
        int nx = x + y + N, ny = x - y + N;
        if (min(nx, ny) < 0 || max(nx, ny) > 2 * N) {
            cout << 0 << endl;
        }
        else cout << cnt[nx][ny] << endl;
    }

    exit(0);
}