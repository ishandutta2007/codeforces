#include <bits/stdc++.h>

using namespace std;

int m;
int c[6][6];

int main()
{
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        c[a][b] = c[b][a] = 1;
    }
    bool ok = false;
    for (int i1 = 1; i1 <= 5; i1++) {
        for (int i2 = i1 + 1; i2 <= 5; i2++) {
            for (int i3 = i2 + 1; i3 <= 5; i3++) {
                if (c[i1][i2] && c[i1][i3] && c[i2][i3]) {
                    ok = true;
                }
                if (!c[i1][i2] && !c[i1][i3] && !c[i2][i3]) {
                    ok = true;
                }
            }
        }
    }
    if (ok) {
        printf("WIN");
    } else {
        printf("FAIL");
    }
    return 0;
}