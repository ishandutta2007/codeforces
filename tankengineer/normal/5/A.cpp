//CF 5A
#include<cstdio>
#include<cstring>

int t1, top, sum, ans;
bool online[105];
char name[105][105], s[105];

int main() {
  while (fgets(s, 104, stdin) != NULL) {
    if (s[0] == '+') {
      t1 = 0;
      for (int j = 1; j <= top; j++) {
        if (!strcmp(name[j], s + 1)) {
          t1 = j;
          break;
        }   
      }
      if (!t1) {
        top ++;
        t1 = top;
      }
      online[t1] = true;
      sum++;
    } else if (s[0] == '-') {
      for (int j = 1; j <= top; j++) {
        if (!strcmp(name[j], s + 1)) {
          t1 = j;
          break;
        }
      }
      online[t1] = false;
      sum--;
    } else {
      t1 = strlen(strpbrk(s, ":"));
      ans += sum * (t1 - 2);
    }
  }
  printf("%d\n", ans);
  return 0;
}