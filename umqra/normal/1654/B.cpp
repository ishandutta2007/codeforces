#include <bits/stdc++.h>

using namespace std;

const int N = (int)2e5 + 10;
const int A = 26;
char str[N];
int cnt[A];

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf(" %s", str);
    memset(cnt, 0, sizeof(cnt));
    int len = strlen(str);
    for (int s = 0; s < len; s++) {
      cnt[str[s] - 'a']++;
    }
    int cut = 0;
    while (cut < len) {
      if (cnt[str[cut] - 'a'] == 1) {
        break;
      }
      cnt[str[cut] - 'a']--;
      cut++;
    }
    printf("%s\n", str + cut);
  }
  return 0;
}