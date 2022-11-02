#include <bits/stdc++.h>
using namespace std;

char dig[1003][1003];
int main() {
    int n, i, j;
    scanf(" %d", &n);
    for(i = 0; i < n; i++)
        scanf(" %c", &dig[0][i]);
    for(i = 0; i < n; i++) {
        int d = dig[i][0] - '0';
        for(j = 0; j < n; j++)
            dig[i][j] = (((dig[i][j] - '0') - d + 10) % 10) + '0';
        for(j = 1; j < n; j++)
            dig[i + 1][j - 1] = dig[i][j];
        dig[i + 1][n - 1] = dig[i][0];
    }

    int mi = 0;
    for(i = 1; i < n; i++)
        if(strcmp(dig[i], dig[mi]) < 0)
            mi = i;
    printf("%s\n", dig[mi]);
    return 0;
}