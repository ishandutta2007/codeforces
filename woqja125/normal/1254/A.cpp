
#include <cstdio>

char map[110][110];
char out[110][110];

const char p[] = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void solve() {
    int n, m, k;
    int all = 0;
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0; i<n; i++) {
        scanf("%s", map[i]);
        for(int j=0; j<m; j++) if(map[i][j] == 'R') all++;
    }
    int now = 0, nc = 0;
    int x, y, u, v;
    u = all / k;
    v = u + 1;
    y = all % k;
    x = k - y;
    for(int i=0; i<n; i++) {
        for(int _j=0; _j<m; _j++) {
            int j;
            if(i%2 == 0) j = _j;
            else j = m-1-_j;
            if(x+y == 0) now = k-1;
            out[i][j] = p[now];
            if(map[i][j] == 'R') {
                nc++;
                if(nc == u && x > 0) {
                    nc = 0;
                    x--;
                    now++;
                }
                else if(nc == v) {
                    nc = 0;
                    y--;
                    now++;
                }
            }
        }
        out[i][m] = '\0';
    }
    for(int i=0; i<n; i++) printf("%s\n", out[i]);
}
int main() {
    int T;
    scanf("%d", &T);
    for(int tt=0; tt<T; tt++) {
        solve();
    }
    return 0;
}