#include<cstdio>
#include<algorithm>
using namespace std;

int col[5], ans, tmp;
bool used[5];

void go(const int i) {
  if (i == 5) {
    ans = min(ans, 4 - tmp);
    return ;
  }
  bool flag = false;
  for (int j = 1; j < i; ++j) {
    if (used[j] && col[j] == col[i]) {
      flag = true;
      break;
    }
  }
  go(i + 1);
  if (!flag) {
    ++tmp;
    used[i] = true;
    go(i + 1);
    used[i] = false;
    --tmp;
  }
}

int main() {
  for (int i = 1; i <= 4; ++i) scanf("%d", &col[i]);
  ans = 4; tmp = 0;
  go(1);
  printf("%d\n", ans);
  return 0;
}