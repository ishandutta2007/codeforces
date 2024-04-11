#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, k, op, tx, ty;
char item[31][31][11], name[11];
bool used[31][31];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= k; ++i) {
    scanf("%d", &op);
    if (op > 0) {
      scanf("%d %d %s", &tx, &ty, &name);
      bool flag = false;
      for (int i = tx; i <= n; ++i) {
        for (int j = (i == tx) ? ty : 1; j <= m; ++j) {
          if (!used[i][j]) {
            used[i][j] = true;
            memcpy(item[i][j], name, sizeof(name));
            flag = true;
            break;
          }
        }
        if (flag) break;
      }
    } else {
      scanf("%s", &name);
      bool flag = false;
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          if (strcmp(item[i][j], name) == 0) {
            used[i][j] = false;
            memset(item[i][j], 0, sizeof(item[i][j]));
            printf("%d %d\n", i, j);
            flag = true;
            break;
          }
        }
        if (flag) break;
      }
      if (!flag) printf("-1 -1\n");
    }
  }
  return 0;
}