#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int l1, l2, g[200005], f[200005];
char s1[200005], s2[200005];
int apr[200005][26];

int main() {
  gets(s1); l1 = strlen(s1);
  gets(s2); l2 = strlen(s2);
  for (int i = 0; i < l2; ++i) {
    for (int j = 0; j < 26; ++j) {
      apr[i + 1][j] = (s2[i] != 'a' + j) ? apr[i][j] : i + 1;
    }
  }
  f[0] = 0;
  for (int i = 0; i < l1; ++i) {
    f[i + 1] = f[i];
    if (s1[i] == s2[f[i + 1]]) ++f[i + 1];
  }
  g[l1] = l2;
  for (int i = l1 - 1; i >= 0; --i) {
    g[i] = g[i + 1];
    if (g[i] > 0 && s1[i] == s2[g[i] - 1]) --g[i];
  }
  for (int i = 0; i < l1; ++i) {
    if (!(apr[f[i + 1]][s1[i] - 'a'] && g[i] <= apr[f[i + 1]][s1[i] - 'a'] - 1)) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}