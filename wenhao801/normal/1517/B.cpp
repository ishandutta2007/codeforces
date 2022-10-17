#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int b[110][110], n, m, tmp[110], ans[110][110], orz[110];
struct qwq { int x, y; bool operator < (const qwq &tmp) const { return b[x][y] > b[tmp.x][tmp.y]; } };
priority_queue <qwq> pq; deque <int> dq[110];

int main () {
    int T = read();
    while (T--) {
        n = read(), m = read(); int i, j;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                b[i][j] = read();
                tmp[j] = b[i][j];
                pq.push(qwq{i, j});
            }
            sort(tmp + 1, tmp + m + 1);
            for (j = 1; j <= m; j++) dq[i].push_back(tmp[j]);
        }
        for (i = 1; i <= m; i++) {
            int x = pq.top().x, y = pq.top().y; pq.pop();
            // printf("%d %d\n", x, y);
            ans[x][i] = b[x][y]; orz[i] = x;
            dq[x].pop_front();
        }
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) if (orz[i] != j) {
                ans[j][i] = dq[j].back(); dq[j].pop_back();
            }
        }
        for (i = 1; i <= n; i++) { for (j = 1; j <= m; j++) cout << ans[i][j] << ' '; cout << endl; }
        for (i = 1; i <= n; i++) dq[i].clear(); while (!pq.empty()) pq.pop();
    }
    return 0;
}