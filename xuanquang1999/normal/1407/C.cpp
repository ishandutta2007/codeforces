#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;

int ask(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

int n, p[MAXN];

int main() {
    scanf("%d", &n);

    int maxInd = 1;
    for(int i = 2; i <= n; ++i) {
        int res1 = ask(maxInd, i);
        int res2 = ask(i, maxInd);
        if (res1 < res2) {
            p[i] = res2;
        } else {
            p[maxInd] = res1;
            maxInd = i;
        }
    }

    p[maxInd] = n;

    printf("!");
    for(int i = 1; i <= n; ++i)
        printf(" %d", p[i]);
    puts("");
    fflush(stdout);

    return 0;
}