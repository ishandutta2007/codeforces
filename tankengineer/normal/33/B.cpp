#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int INF = 1000000000;

int l1, l2, n, g[27][27], c[27][27], cost, ans;
char s[100005], t[100005], ch1, ch2, ch[27][27];

int main() {
  gets(s); gets(t);
  l1 = strlen(s);
  l2 = strlen(t);
  if (l1 != l2) {
    printf("-1\n");
    return 0;
  }
  scanf("%d", &n);
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      g[i][j] = (i == j) ? 0 : INF;
    }
  }
  for (int i = 1; i <= n; ++i) {
    getchar();
    scanf("%c %c %d", &ch1, &ch2, &cost);
    //printf("%c %c %d %d\n", ch1, ch2, g[ch1 - 'a'][ch2 - 'a'], cost);
    g[ch1 - 'a'][ch2 - 'a'] = min(cost, g[ch1 - 'a'][ch2 - 'a']);
    //printf("%c %c %d %d\n", ch1, ch2, g[ch1 - 'a'][ch2 - 'a'], cost);
  }
  for (int k = 0; k < 26; ++k) {
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      c[i][j] = INF;
      for (int k = 0; k < 26; ++k) {
        c[i][j] = min(c[i][j], g[i][k] + g[j][k]);
        if (c[i][j] != INF && c[i][j] == g[i][k] + g[j][k]) {
          ch[i][j] = (char)(k + 'a');
          //printf("%c %c %c %d %d %d\n", i + 'a', j + 'a', ch[i][j], g[i][k], g[j][k], c[i][j]); 
        }
      }
    }
  }
  for (int i = 0; i < l1; ++i) {
    if (c[s[i] - 'a'][t[i] - 'a'] == INF) {
      printf("-1\n");
      return 0;
    }
    ans += c[s[i] - 'a'][t[i] - 'a'];
    ch1 = ch[s[i] - 'a'][t[i] - 'a'];
    s[i] = ch1;
  }
  printf("%d\n", ans);
  puts(s);
  return 0;
}