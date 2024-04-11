//CF 7B
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, p, col[105], cnt, p1, p2; 
char s[50], ch;
bool flag;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", &s);
    if (s[0] == 'a') {
      flag = false;
      scanf("%d", &p); ch = getchar();
      for (int i = 1; i <= m - p + 1; i++) {
        if (col[i] == 0) {
          flag = true;
          for (int j = 0; j < p; j++) {
            if (col[i + j]) {
              flag = false;
              break;
            }
          }
          if (flag) {
            cnt++;
            printf("%d\n", cnt);
            for (int j = 0; j < p; j++) {
              col[i + j] = cnt; 
            }
            break;
          }
        }
      }
      if (!flag) puts("NULL");
      flag = false;
    } else if (s[0] == 'e') {
      scanf("%d", &p); ch = getchar();
      flag = false;
      for (int i = 1; i <= m; i++) {
        if (col[i] == p) {
          flag = true;
          col[i] = 0;
        }
      }
      if (!flag || p <= 0) puts("ILLEGAL_ERASE_ARGUMENT");
      flag = false;
    } else {
      p1 = 1; p2 = 1;
      while (p2 <= m) {
        if (col[p2]) {
          while (p1 < p2 && col[p1]) p1++;
          swap(col[p1], col[p2]);
        }
        p2++;
      }
    }
  }
  return 0;
}