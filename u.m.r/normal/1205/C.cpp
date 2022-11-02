#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 100 + 10;
const int MM = 1e9 + 7;

int n;
int a[MAXN][MAXN];
int __cnt;
int f[MAXN];
int __flag;

int query(int x1, int y1, int x2, int y2) {
    __cnt++;
    printf("? %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

int gao(int p, int q, int a, int b, int c, int d) {
    // pabq, pcdq
    int u, v;
    f[0] = 0; f[1] = 1; f[2] = 0; f[3] = 1;
    u = (f[p] == f[q] && f[a] == f[b]) || (f[p] == f[q] && f[c] == f[d]);
    f[0] = 0; f[1] = 1; f[2] = 1; f[3] = 0;
    v = (f[p] == f[q] && f[a] == f[b]) || (f[p] == f[q] && f[c] == f[d]);
    if (u != v) {
        __flag = u;
        return true;
    }
    return false;
}

void solve(int casi){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = -1;
        }
    }
    a[1][1] = 1;
    a[n][n] = 0;
    for (int k = 4; k < 2 * n; k += 2) {
        for (int i = 1; i <= k && i <= n; i++) {
            int j = k - i;
            if (1 <= j && j <= n) {
                int u, x, y;
                if (i <= 1) {
                    x = i, y = j - 2;
                }
                else if (j <= 1) {
                    x = i - 2, y = j;
                }
                else {
                    x = i - 1, y = j - 1;
                }
                u = query(x, y, i, j);
                a[i][j] = a[x][y] ^ u ^ 1;
            }
        }
    }
    cerr << __cnt << endl;
    a[1][2] = 2;
    int u = query(1, 2, 2, 3);
    a[2][3] = a[1][2] ^ u ^ 1;
    u = query(2, 1, 2, 3);
    a[2][1] = a[2][3] ^ u ^ 1;
    for (int k = 3; k < 2 * n; k += 2) {
        for (int i = 1; i <= k && i <= n; i++) {
            int j = k - i;
            if (1 <= j && j <= n && a[i][j] == -1) {
                int u, x, y;
                if (i <= 1) {
                    x = i, y = j - 2;
                }
                else if (j <= 1) {
                    x = i - 2, y = j;
                }
                else {
                    x = i - 1, y = j - 1;
                }
                u = query(x, y, i, j);
                a[i][j] = a[x][y] ^ u ^ 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + 2 <= n && j + 1 <= n) {
                if (gao(a[i][j], a[i+2][j+1], a[i+1][j], a[i+2][j], a[i][j+1], a[i+1][j+1])) {
                    int u = query(i, j, i + 2, j + 1);
                    __flag = (u == __flag);
                    __flag ^= 3;
                    for (int p = 0; p <= n; p++) {
                        for (int q = 0; q <= n; q++) {
                            if (a[p][q] >= 2) {
                                a[p][q] ^= __flag;
                            }
                        }
                    }
                    goto KKE;
                }
            }
            if (i + 1 <= n && j + 2 <= n) {
                if (gao(a[i][j], a[i+1][j+2], a[i][j+1], a[i][j+2], a[i+1][j], a[i+1][j+1])) {
                    int u = query(i, j, i + 1, j + 2);
                    __flag = (u == __flag);
                    __flag ^= 3;
                    for (int p = 0; p <= n; p++) {
                        for (int q = 0; q <= n; q++) {
                            if (a[p][q] >= 2) {
                                a[p][q] ^= __flag;
                            }
                        }
                    }
                    goto KKE;
                }
            }
        }
    }
    KKE:
    printf("!\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d", a[i][j]);
        }
        puts("");
    }
    fflush(stdout);
    cerr << __cnt << endl;
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}