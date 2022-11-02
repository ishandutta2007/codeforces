#include<cstdio>
#include<algorithm>
using namespace std;

int n, t1, ans[1005], cnt;
bool used[1005];
char ch;

int main() {
  scanf("%d%c", &t1, &ch);
  while (ch == ',') {
    used[t1] = true;
    scanf("%d%c", &t1, &ch);
  }
  used[t1] = true;
  for (int i = 1; i <= 1000; ++i) {
    if (used[i]) {
      for (int j = i; used[j]; ++j) {
        ans[i] = j;
        used[j] = false;
      }
    }
  }
  cnt = 0;
  for (int i = 1; i <= 1000; ++i) {
    if (ans[i]) {
      ++cnt;
      if (cnt != 1) printf(",");
      if (ans[i] == i) printf("%d", i); else printf("%d-%d", i, ans[i]);
    }
  }
  printf("\n");
  return 0;
}