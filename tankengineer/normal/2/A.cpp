//CF 2A
#include<stdio.h>
#include<cstring>

int n, t1, t2, top, ans, c[1005][1005], t[1005][1005];
char s1[35], s[1005][35];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s %d", &s1, &t1);
    t2 = 0;
    for (int j = 1; j <= top; j++) {
      if (!strcmp(s[j], s1)) {
        t2 = j;
        break;
      }
    }
    if (!t2) {
      top++;
      for (int j = 0; j <= strlen(s1); j++) s[top][j] = s1[j];
      c[top][0] = 1;
      c[top][1] = t1;
      t[top][1] = i;
    } else {
      c[t2][0]++;
      c[t2][c[t2][0]] = c[t2][c[t2][0] - 1] + t1;
      t[t2][c[t2][0]] = i;
    }
  }
  
  ans = 1;
  for (int i = 1; i <= top; i++) {
    if (c[ans][c[ans][0]] < c[i][c[i][0]]) ans = i;
  }
  t1 = c[ans][c[ans][0]];
  for (int i = 1; i <= top; i++) {
    if (c[i][c[i][0]] < t1) continue;
    for (int j = 1; j <= c[i][0]; j++) {
      if (c[i][j] >= t1) {
        c[i][0] = -t[i][j];
        break;
      }
    }
  }
  
  for (int i = 1; i <= top ; i++) {
    if (c[i][0] < 0 && c[i][0] > c[ans][0]) ans = i;
  }
  
  printf("%s\n", s[ans]);
  
  return 0;
}