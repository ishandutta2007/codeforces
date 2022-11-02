//CF 6B
#include<cstdio>
#include<cstring>

int n, m, ans;
bool col[257], flag;
char cp, ch, map[105][105];

int main() {
  scanf("%d %d", &n, &m);
  scanf(" %c", &cp);
  col[cp] = true;
  ch = getchar();
  for (int i = 1; i <= n; i++) {
    gets(map[i]);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == '.') continue;
      flag = map[i - 1][j] == cp || map[i + 1][j] == cp || map[i][j + 1] == cp;
      if (j > 0) flag = flag || map[i][j - 1] == cp;
      if (flag && !col[map[i][j]]) {
        col[map[i][j]] = true;
        ans++;
        //printf("%d %d", i, j);
      }
    }
  }
  
  printf("%d\n", ans);
    
  return 0;
}