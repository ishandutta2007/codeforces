#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int t1, t2, l, g[205], f[205];
char s[205];
bool ans[205];

char geto(const int t1, const int l, const int t2) {
  if (t1 + l > t2) return '\0'; else return s[t1 + l];
}

bool cmp(const int t1, const int t2, const int t3, const int t4) {
  if (t3 == -1) return true;
  int l = 0;
  char ch1, ch2;
  while (true) {
    ch1 = geto(t1, l, t2);
    ch2 = geto(t3, l, t4);
    if (ch1 == '\0' && ch2 == '\0') return true;
    if (ch1 < ch2) return true;
    if (ch1 > ch2) return false;
    ++l;
  }
}

int main() {
  gets(s);
  t1 = t2 = 0; l = strlen(s);
  if ((s[l - 1] < 'a' || s[l - 1] > 'z') && s[l - 1] != '@') --l;
  if (s[0] == '@' || s[l - 1] == '@') {
    puts("No solution");
    return 0;
  }
  g[0] = -2;
  for (int i = 0; i < l; ++i) {
    if (s[i] == '@') {
      g[++t1] = i;
      if (g[t1] - g[t1 - 1] < 3) {
        puts("No solution");
        return 0;
      }
    }
  }
  if (t1 == 0) {
    puts("No solution");
    return 0;
  }
  for (int i = 2; i <= t1; ++i) {
    ans[g[i] - 2] = true;
  }
  for (int i = 0; i < l; ++i) {
    printf("%c", s[i]);
    if (ans[i]) printf(",");
  }
  printf("\n");
  return 0;
}