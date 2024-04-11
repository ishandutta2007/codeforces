//20A
#include<cstdio>
#include<cstring>

int t1, t2, t3, t4;
char s[105];

int main() {
  gets(s);
  t1 = 0; t2 = 0;
  for (int i = 0; i < strlen(s); i++) {
    if (!(s[t1] == '/' && s[i] == '/')) {
      s[++t1] = s[i];
    }
  }
  if (t1 > 0 && s[t1] == '/') s[t1] = 0 ; else s[t1 + 1] = 0;
  puts(s);
  return 0;
}