#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, k, t1, mins1[26], mins2[26], f[26], g[26], ans, cho[500005][26];
char s[500005];

int main() {
  scanf("%d %d", &n, &k);
  gets(s); gets(s);
  int l = strlen(s);
  memset(f, 0, sizeof(f));
  for (int i = 0; i < l; ++i) {
    t1 = s[i] - 'A';
    mins1[0] = 0;
    mins2[k - 1] = k - 1;
    for (int j = 1; j < k; ++j) {
      mins1[j] = f[j] < f[mins1[j - 1]] ? j : mins1[j - 1];
      mins2[k - 1 - j] = f[k - 1 - j] < f[mins2[k - j]] ? k - 1 - j : mins2[k - j];
    }
    for (int j = 0; j < k; ++j) {
      g[j] = f[j];
    }
    for (int j = 0; j < k; ++j) {
      cho[i][j] = (j > 0 ? g[mins1[j - 1]] : i + 2) < (j < k - 1 ? g[mins2[j + 1]] : i + 2) ? mins1[j - 1] : mins2[j + 1];  
      f[j] = g[cho[i][j]] + (t1 == j ? 0 : 1);
    }
  }
  ans = 0;
  for (int j = 0; j < k; ++j) {
    if (f[j] < f[ans]) {
      ans = j;
    }
  }
  printf("%d\n", f[ans]);
  for (int i = l - 1; i >= 0; --i) {
    s[i] = ans + 'A';
    ans = cho[i][ans];
  }
  puts(s);
  
  return 0;
}