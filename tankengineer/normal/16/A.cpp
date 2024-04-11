//16A
#include<cstdio>
#include<cstring>

int n, m;
char f[105][105], ch;
bool flag;


int main() {
  scanf("%d %d", &n, &m);
  ch = getchar();
  flag = true;
  for (int i = 0; i < n; i++) {
    gets(f[i]);
    for (int j = 0; j < m; j++) {
      if (f[i][j] != f[i][0]) {
        flag = false;
        break;
      }
    }
    if (i > 0 && f[i][0] == f[i - 1][0]) flag = false;
  }
  if (flag) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}