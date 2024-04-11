//11C
#include<cstdio>
#include<cstring>

int t, n, m, u[255][255], ans, t1, t2;
char ch, map[255][255];
bool flag;

int main() {
  scanf("%d", &t);
  for (; t; t--) {
    scanf("%d %d", &n, &m);
    ch = getchar();
    memset(u, 0, sizeof(u));
    for (int i = 0; i < n; i++) {
      gets(map[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (map[i][j] == '0')                                     u[i][j] += 1;
        if (i == 0 || map[i - 1][j] == '0')                       u[i][j] += 2;
        if (i == 0 || j == m - 1 || map[i - 1][j + 1] == '0')     u[i][j] += 4;
        if (j == m - 1 || map[i][j + 1] == '0')                   u[i][j] += 8;
        if (i == n - 1 || j == m - 1 || map[i + 1][j + 1] == '0') u[i][j] += 16;
        if (i == n - 1 || map[i + 1][j] == '0')                   u[i][j] += 32;
        if (i == n - 1 || j == 0 || map[i + 1][j - 1] == '0')     u[i][j] += 64;
        if (j == 0 || map[i][j - 1] == '0')                       u[i][j] += 128;
        if (i == 0 || j == 0 || map[i - 1][j - 1] == '0')         u[i][j] += 256;
        u[i][j] = u[i][j] ^ ((1 << 9) - 1);
      }
    }
    ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        flag = false;
        //Con 4 Con 1 - 3
        if (u[i][j] == 41 && u[i][j + 1] == 217 && u[i][j + 2] == 161 && u[i + 1][j] ==55 & u[i + 1][j + 2] == 355 &&
            u[i + 2][j] == 11 && u[i + 2][j + 1] == 397 && u[i + 2][j + 2] == 131) {
           ans++;
           continue;
        }
        //Con 1 left-up corner 
        if (u[i][j] == 41) {
          t1 = t2 = 0;
          if (u[i][j + 1] != 201 || u[i + 1][j] != 39) continue;
          while (u[i][j + t1 + 2] == 137) t1++;
          while (u[i + t2 + 2][j] == 35) t2++;
          if (u[i][j + 2 + t1] != 153 || u[i + 2 + t2][j] != 51) continue;
          if (t1 != t2 || u[i][j + t1 + 3] != 161 || u[i + t2 + 3][j] != 11 || u[i + t2 + 3][j + t1 + 3] != 131) continue;
          if (u[i + 1][j + 3 + t1] != 291 || u[i + 2 + t2][j + 3 + t1] != 99) continue;
          if (u[i + 3 + t1][j + 2 + t1] != 141 || u[i + 3 + t2][j + 1] != 393) continue;
          for (int k = 1; k < t1; k++) {
            if (u[i + t1 + 3][j + k + 2] != 137 || u[i + k + 2][j + t1 + 3] != 35) {
              flag = true;
              break;
            }
          }
          if (flag) continue;
          ans++;
        }
        //Con 2 up corner
        if (u[i][j] == 81) {
          t1 = t2 = 0;
          while (u[i + t1 + 1][j + t1 + 1] == 273) t1++;
          while (u[i + t2 + 1][j - t2 - 1] == 69) t2++;
          if (t1 != t2 || u[i + t1 + 1][j + t1 + 1] != 321 || u[i + t2 + 1][j - t2 - 1] != 21 || u[i + t2 + t1 + 2][j] != 261) continue;
          for (int k = 1; k <= t1; k++) {
            if (u[i + t1 + k + 1][j + t1 + 1 - k] != 69 || u[i + t1 + k + 1][j - t1 - 1 + k] != 273) {
              flag = true;
              break;
            }
          }
          if (flag) continue;
          ans++;
        }
        //Con 3 Con 1 - 2
        if (u[i][j] == 57 && u[i][j + 1] == 225 && u[i + 1][j + 1] ==387 && u[i + 1][j] == 15) {
          ans++;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}