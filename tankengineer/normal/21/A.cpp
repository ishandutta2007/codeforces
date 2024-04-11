//21A
#include<cstdio>
#include<cstring>

bool inline isok(char a) {return (a >= '0' && a <= '9') || (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || a == '_';}

int t1, t2;
char s[105];
bool flag;

int main() {
  gets(s);
  t1 = 0; flag = true;
  while (s[t1] != '@') {
    flag = flag && isok(s[t1]);
    t1++;
  }
  if (t1 == 0 || t1 > 16) flag = false;
  t1++; t2 = t1;
  while (s[t1] != '/' && s[t1] != '\0') {
    flag = flag && (isok(s[t1]) || s[t1] == '.' && isok(s[t1 - 1]));
    t1++;
  }
  if (t1 == t2 || t1 - t2 > 32 || s[t1 - 1] == '.') flag = false;
  if (s[t1] == '/') {
    t1++; t2 = t1;
    while (s[t1]) {
      flag = flag && (isok(s[t1]));
      t1++;
    }
    if (t1 == t2 || t1 - t2 > 16) flag = false;
  }
  puts(flag ? "YES" : "NO");
  return 0;
}