#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m;
char a[666][666], b[666][666];

int main() {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    scanf("%d%d\n", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) a[i][j] = getchar();
        scanf("\n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) b[j][n - i - 1] = a[i][j];
    }
    swap(n, m);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = b[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m / 2; j++) swap(a[i][j], a[i][m - 1 - j]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    b[i * 2 + x][j * 2 + y] = a[i][j];
                }
            }
        }
    }
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * m; j++) putchar(b[i][j]);
        puts("");
    }
}