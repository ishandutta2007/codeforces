#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 102

int memo[N][N][2];
int n, k;
char str[N];

int pd (int i, int j, int b) {
    if (j == k)
        b = 1;
    if (j > k) return 0;
    if (i == n)
        return b;

    if (memo[i][j][b] != -1)
        return memo[i][j][b];

    int me = 0;
    if (str[i] == 'Y')
        me = pd(i+1, 0, b);
    else if (str[i] == 'N')
        me = pd(i+1, j+1, b);
    else
        me = pd(i+1, 0, b) | pd(i+1, j+1, b);

    memo[i][j][b] = me;
    return me;
}

int main () {
    scanf("%d %d", &n, &k);
    scanf(" %s", str);

    memset(memo, -1, sizeof(memo));

    if (pd(0,0,0))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}