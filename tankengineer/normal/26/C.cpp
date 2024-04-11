//26C
#include<cstdio>
#include<cstring>

int n, m, a, b, c;
char map[105][105], ch;
bool flag;

void fill(const int n, const int m, int a, int b, int c) {
    int x = 1, y = 1;
    if (a < 0 || b < 0 || c < 0) flag = false;
    if (n == 0 || m == 0) return;
    while (a > 0) {
      if ((x + y) / 2 % 2) ch = 'a'; else ch = 'b';
        map[x][y] = map[x + 1][y] = map[x][y + 1] = map[x + 1][y + 1] = ch;
        y += 2;
        if (y == m + 1) {
            x += 2;
            y = 1;
        }
        a--;
        if (x > n) return;
    }
    while (b > 1) {
    if ((x + y) / 2 % 2) ch = 'c'; else ch = 'g';
        map[x][y] = map[x][y + 1] = ch;
        map[x + 1][y] = map[x + 1][y + 1] = ch + 1;
        y += 2;
        if (y == m + 1) {
            x += 2;
            y = 1;
        }
        b -= 2;
        if (x > n) return;
    }
    while (c > 1) {
    if ((x + y) / 2 % 2) ch = 'i'; else ch = 'k';
        map[x][y] = map[x + 1][y] = ch;
        map[x][y + 1] = map[x + 1][y + 1] = ch + 1;
        y += 2;
        if (y == m + 1) {
            x += 2;
            y = 1;
        }
        c -= 2;
        if (x > n) return;
    }
    flag = false;
}

int main() {
    scanf("%d %d %d %d %d", &n, &m, &b, &c, &a);
    if (n % 2 && m % 2) {
        puts("IMPOSSIBLE");
        return 0;
    }
    flag = true;
    if (n % 2) {
        ch = 'e';
        for (int i = 1; i <= m; i += 2) {
      b--;
            map[n][i] = ch;
            map[n][i + 1] = ch;
            if (ch == 'e') ch = 'f'; else ch = 'e';
        }
        fill(n - 1, m, a, b, c);
    } else if (m % 2) {
        ch = 'e';
        for (int i = 1; i <= n; i += 2) {
            c--;
            map[i][m] = ch;
            map[i + 1][m] = ch;
          if (ch == 'e') ch = 'f'; else ch = 'e';
        }
        fill(n, m - 1, a, b, c);
    } else {
        fill(n, m, a, b, c);
    }
    if (!flag) {
        puts("IMPOSSIBLE");
      return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}