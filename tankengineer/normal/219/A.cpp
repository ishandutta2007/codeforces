#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int k, cnt[55];
char s[1005];

int main() {
  scanf("%d", &k);
  gets(s); gets(s);
  int l = strlen(s);
  for (int i = 0; i < l; ++i) cnt[s[i] - 'a']++;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] % k != 0) {
      printf("-1\n");
      return 0;
    }
    cnt[i] /= k;
  }
  int t1 = 0;
  for (int i = 0; i < 26; ++i) {
    while (cnt[i]--) {
      s[t1++] = i + 'a';
    }
  }
  s[t1] = '\0';
  for (int i = 0; i < k; ++i) {
    printf("%s", s);
  }
  printf("\n");
  return 0;
}