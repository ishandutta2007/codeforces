//23A
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, cnt;
char s[105];

int main() {
  gets(s);
  for (int i = 0; i < strlen(s); i++) {
    for (int j = i + 1; j < strlen(s); j++) {
      cnt = 0;
      while (s[i + cnt] == s[j + cnt]) cnt++;
      ans = max(ans, cnt);
    }
  }
  printf("%d\n", ans);
  return 0;
}