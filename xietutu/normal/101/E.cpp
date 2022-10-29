#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 20005, size = 50;
int n, m, p, now, K;
int X[maxn], x[maxn], y[maxn], f[110][maxn], g[405][maxn];
char s[maxn * 2];
inline int F(int a, int b) {
    return (x[a] + y[b]) % p;    
}
void calc(int st, int ed) {
    for (int i = st; i <= ed; ++i) {
        if (i % size == 0) {
            for (int j = 0; j < m; ++j)
                f[i - st][j] = g[i / size + 1][j];
        }
        else {
            for (int j = 0; j < m; ++j) {
                if (i > 0) f[i - st][j] = f[i - st - 1][j];
                if (j > 0) f[i - st][j] = max(f[i - st][j], f[i - st][j - 1]);
                f[i - st][j] = f[i - st][j] + F(i, j);
            }
        }
    }
}
void print(int x, int y) {
    int base;
    calc(X[K], x);
    base = X[K];
    int now = 0;
    while (!(x == 0 && y == 0)) {
        if (x == base && K > 1) {
            --K;
            calc(X[K], X[K] + size);
            base = X[K];    
        }
        int ret = f[x - base][y] - F(x, y);
        if (x && ret == f[x - base - 1][y]) {
            s[++now] = 'C';
            --x;  
        }
        else {
            s[++now] = 'S';
            --y;
        }
    }
    reverse(s + 1, s + now + 1);
    s[++now] = '\0';
    printf("%s\n", s + 1);
}
int main() {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; ++i)
        scanf("%d", x + i);
    for (int j = 0; j < m; ++j)
        scanf("%d", y + j);
    for (int i = 0; i < n; ++i) {
        now = 1 - now;
        for (int j = 0; j < m; ++j) {
            if (i > 0) f[now][j] = max(f[now][j], f[1 - now][j]);
            if (j > 0) f[now][j] = max(f[now][j], f[now][j - 1]);
            f[now][j] += F(i, j);
        }
        if (i % size == 0) {
            ++K;
            X[K] = i;
            for (int j = 0; j < m; ++j)
                g[K][j] = f[now][j];    
        } 
    }
    printf("%d\n", f[now][m - 1]);
    print(n - 1, m - 1);
}