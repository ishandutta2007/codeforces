#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

const int N = (int)1e3 + 10;
char table[N][N];
char tmp[N][N];
int n, m;

void rotate() {
    for (int i = 0; i < n; i++) {
        for (int s = 0; s < m; s++) {
            tmp[s][i] = table[i][s];
        }
    }
    swap(n, m);
    for (int i = 0; i < n; i++) {
        for (int s = 0; s < m; s++) {
            table[i][s] = tmp[i][s];
        }
    }
}

int cntColumn[N], cntRow[N];
bool check() {
    for (int i = 0; i < n; i++) {
        int segments = 0;
        for (int s = 0; s < m; s++) {
            if (table[i][s] == '#' && (s == 0 || table[i][s - 1] == '.')) {
                segments++;
            }
        }
        if (segments > 1) {
            return false;
        }
    }
    fill(cntColumn, cntColumn + m, 0);
    fill(cntRow, cntRow + n, 0);
    for (int i = 0; i < n; i++) {
        for (int s = 0; s < m; s++) {
            cntColumn[s] += (table[i][s] == '#' ? 1 : 0);
            cntRow[i] += (table[i][s] == '#' ? 1 : 0);
        }
    }
    for (int i = 0; i < n; i++) {
        if (cntRow[i] == 0) {
            bool ok = false;
            for (int s = 0; s < m; s++) {
                ok |= (cntColumn[s] == 0);
            }
            if (!ok) {
                return false;
            }
        }
    }
    return true;
}

const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, -1, 0, 1};
bool used[N][N];
void dfs(int x, int y) {
    used[x][y] = true;
    for (int d = 0; d < 4; d++) {
        int nx = x + DX[d];
        int ny = y + DY[d];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && !used[nx][ny] && table[nx][ny] == '#') {
            dfs(nx, ny);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %s", table[i]);
    }
    if (!check()) {
        puts("-1");
        return 0;
    }
    rotate();
    if (!check()) {
        puts("-1");
        return 0;
    }
    rotate();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int s = 0; s < m; s++) {
            if (!used[i][s] && table[i][s] == '#') {
                cnt++;
                dfs(i, s);
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}