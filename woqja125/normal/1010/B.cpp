#include <cstdio>
#include <cstdlib>
int ask(int y) {
    printf("%d\n", y);
    fflush(stdout);
    int r;
    scanf("%d", &r);
    if(r == 0 || r == -2) {
        exit(0);
    }
    return r;
}
int pre[30];
int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for(int i=0; i<n; i++) pre[i] = ask(1);
    int f = 2, r = m, c = 0;
    while(f<r) {
        int M = (0ll + f + r) / 2;
        if(ask(M) * pre[c] == 1) f = M + 1;
        else r = M - 1;
        (++c)%=n;
    }
    ask(f);
    return 0;
}