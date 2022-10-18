#include <bits/stdc++.h>

using namespace std;

int k, a[3][3];

int main() {
    scanf("%d", &k);

    int lim = 1 << 17;

    a[0][0] = (1 << 18) - 1;
    a[0][1] = k;
    a[0][2] = 0;
    a[1][0] = 1 << 17;
    a[1][1] = a[0][1];
    a[1][2] = a[0][2];
    a[2][0] = a[0][0];
    a[2][1] = a[0][0];
    a[2][2] = a[0][1];

    puts("3 3");
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j)
            printf("%d ", a[i][j]);
        puts("");
    }


    return 0;
}