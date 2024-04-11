//14A
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, minx, miny, maxx, maxy;
char map[55][55], ch;

int main() {
  scanf("%d %d", &n, &m);
  ch = getchar();
  minx = n - 1; miny = m - 1;
  maxx = 0; maxy = 0;
  for (int i = 0; i < n; i++) {
    gets(map[i]);
    for (int j = 0 ; j < m; j++) {
      if (map[i][j] == '*') {
        minx = min(minx, i);
        miny = min(miny, j);
        maxx = max(maxx, i);
        maxy = max(maxy, j);
      }
    }
  }
  for (int i = minx; i <= maxx; i++) {
    for (int j = miny; j <= maxy; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
  return 0;
}