#include <stdio.h>
#include <memory.h>
#include <algorithm>

#define err(...) fprintf(stderr, __VA_ARGS__)

const int N = 1e3 + 2;
const int K = 50;
const int BASE = 1e9 + 7;

int tt;
int g[N][K], f[N][K], ff[N][K], fact[N];

void add(int &x, int y) {
    x += y;
    if (x >= BASE) x -= BASE;
}

int main() {
    // freopen("input.txt", "r", stdin);
    f[0][0] = 1;
    for (int len = 1; len < N; len++) {
        memcpy(g,f,sizeof(f));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                //len + 1, i, j
                add(ff[i][j], f[i][j]);
                //len,i + 1, j
                if (i + 1 < N) add(g[i+1][j],g[i][j]);
                // len+1,i+len,j+1
                // if (&f[i+len][j+1]==&f[0][0]) err("f[0][0] += %d\n", f[i][j]);
                if ((j + 1 < K) && (i + len < N)) add(ff[i+len][j+1],g[i][j]);
            }
        }
        // err("[before memset] ff[1][1] = %d\n", ff[1][1]);
        memcpy(f,ff,sizeof(ff));
        // err("                 f[1][1] = %d\n", f[1][1]);
        memset(ff,0,sizeof(ff));
        // err("[after memset]  ff[1][1] = %d\n", ff[1][1]);
        // err("\n");
    }
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = (fact[i-1]*1LL*i) % BASE;
    for (int i = 0; i < N; i++) {
        for (int j =  0; j < K; j++) {
            f[i][j] = (f[i][j] * 1LL * fact[j]) % BASE;
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < K; j++) {
            add(f[i][j], f[i-1][j]);
        }
    }

    scanf("%d", &tt);
    while (tt--) {
        int n, m;
        scanf("%d%d", &n, &m);
        if (m*(m-1)/2 > n) {
            puts("0");
            continue;
        }
        printf("%d\n", f[n][m]);
    }
}