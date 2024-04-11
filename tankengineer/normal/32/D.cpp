#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, k, mins, cnt[305];
char map[305][305];

int main() {
  scanf("%d %d %d", &n, &m, &k);
  gets(map[0]);
  for (int i = 0; i < n; ++i) gets(map[i]);
  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j < m - 1; ++j) {
      if (map[i][j] == '.') continue;
      mins = min(min(i, j), min(n - 1 - i, m - 1 - j));
      for (int l = 1; l <= mins; ++l) {
        if (map[i][j - l] == '*' && map[i][j + l] == '*' && map[i + l][j] == '*' && map[i - l][j] == '*') {
          ++cnt[l];
        }
      }
    }
  }
  for (int i = 1; i <= max(n, m); ++i) cnt[i] += cnt[i - 1];
  if (k > cnt[max(n, m)]) {
    printf("-1\n");
    return 0;
  }
  int t1 = 0;
  while (cnt[t1] < k) ++t1;
  k -= cnt[t1 - 1];
  for (int i = t1; i < n - t1; ++i) {
    for (int j = t1; j < m - t1; ++j) {
      if (map[i][j] == '.') continue;
      if (map[i][j - t1] == '*' && map[i][j + t1] == '*' && map[i + t1][j] == '*' && map[i - t1][j] == '*') --k;
      if (k == 0) {
        printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n", i + 1, j + 1, i - t1 + 1, j + 1, i + t1 + 1, j + 1, i + 1, j - t1 + 1, i + 1, j + t1 + 1);
        return 0;
      }
    }
  }
  return 0;
}