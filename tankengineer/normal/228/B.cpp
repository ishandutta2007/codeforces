#include<cstdio>
#include<algorithm>
using namespace std;

int n1, m1, n2, m2, ans, tx, ty;
char map1[55][55], map2[55][55];

int getans(const int x, const int y) {
  int ret = 0;
  for (int i = 1; i <= n1; ++i) {
    if (i + x < 1 || i + x > n2) continue;
    for (int j = 1; j <= m1; ++j) {
      if (j + y < 1 || j + y > m2 || map1[i][j] == '0') continue;
      ret += int (map2[i + x][j + y] == '1');
    }
  }
  return ret;
}

int main() {
  scanf("%d %d", &n1, &m1);
  for (int i = 1; i <= n1; ++i) scanf("%s", map1[i] + 1);
  scanf("%d %d", &n2, &m2);
  for (int i = 1; i <= n2; ++i) scanf("%s", map2[i] + 1);
  ans = 0; tx = -100; ty = -100;
  for (int x = -50; x <= 50; ++x) {
    for (int y = -50; y <= 50; ++y) {
      int tmp = getans(x, y);
      if (tmp > ans) {
        ans = tmp;
        tx = x;
        ty = y;
      }
    }
  }
  printf("%d %d\n", tx, ty); 
  return 0;
}