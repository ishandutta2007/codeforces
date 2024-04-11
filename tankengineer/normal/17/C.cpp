//17C
#include<cstdio>
#include<algorithm>
using namespace std;

const int p = 51123987;
int n, m, next[155][3], f[155][52][52][52], ans, t1;
char s[155];

int main () {
  scanf("%d", &n); getchar(); gets(s);
  next[n][0] = next[n][1] = next[n][2] = n;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= 2; j++) next[i][j] = next[i + 1][j];
    next[i][s[i] - 'a'] = i;
  }
  
  f[0][0][0][0] = 1;
  m = (n + 2) / 3 + 1;
  for (int i = 0; i < n; i++) {
    for (int x = 0; x < m; x++) {
      for (int y = 0; y < m; y++) {
        for (int z = 0; z < m; z++) {
          t1 = f[i][x][y][z];
          if (x + y + z == n && (abs(x - y) < 2 && abs(y - z) < 2 && abs(x - z) < 2)) ans = (ans + t1) % p;
          f[next[i][0]][x + 1][y][z] = (f[next[i][0]][x + 1][y][z] + t1) % p;
          f[next[i][1]][x][y + 1][z] = (f[next[i][1]][x][y + 1][z] + t1) % p;
          f[next[i][2]][x][y][z + 1] = (f[next[i][2]][x][y][z + 1] + t1) % p;
        }
      }
    }
  }
  
  printf("%d\n", ans);
  
  return 0;
}