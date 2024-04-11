#include <bits/stdc++.h>

using namespace std;

int f[666][666][2], n1, n2, k1, k2;

int main() {
    scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            for (int e = 0; e < 2; e++) {
                f[i][j][e] = false;
                if (e == 0) {
                    for (int it = 1; it <= min(i, k1); it++) {
                        f[i][j][e] |= !f[i - it][j][1 - e];
                    }
                } else {
                    for (int it = 1; it <= min(j, k2); it++) {
                        f[i][j][e] |= !f[i][j - it][1 - e];
                    }
                }
            }
        }
    }
    puts(f[n1][n2][0] ? "First" : "Second");
}