#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 }, dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };
bool v[maxn][maxn];

int main() {
    int n; scanf("%d", &n);
    int ax, ay, bx, by, cx, cy;
    scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
    --ax, --ay, --bx, --by, --cx, --cy;
    queue<pair<int, int>> q;
    q.emplace(bx, by);
    v[bx][by] = true;
    function<bool(int, int)> valid = [&](int x, int y) {
        if (x < 0 || x >= n) return false;
        if (y < 0 || y >= n) return false;
        if (v[x][y]) return false;
        if (x == ax || y == ay) return false;
        if (x + y == ax + ay || x - y == ax - ay) return false;
        return true;
    };
    while (q.size()) {
        int x, y; tie(x, y) = q.front(); q.pop();
        for (int i = 0; i < 8; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (!valid(tx, ty)) continue;
            v[tx][ty] = true;
            q.emplace(tx, ty);
        }
    }
    v[cx][cy] ? puts("YES") : puts("NO");
    return 0;
}