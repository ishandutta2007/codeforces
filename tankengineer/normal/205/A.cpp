#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
  int n, tmp, mins = 2000000000, cnt;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &tmp);
    if (tmp < mins) {
      mins = tmp;
      cnt = i;
    } else if (mins == tmp) {
      cnt = -1;
    }
  }
  if (cnt < 0) puts("Still Rozdil"); else printf("%d\n", cnt);
  return 0;
}