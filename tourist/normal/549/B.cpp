#include <bits/stdc++.h>

using namespace std;

const int N = 777;

char a[N][N];
int cnt[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", cnt + i);
  }
  vector <int> ret;
  for (int it = 0; it < n; it++) {
    for (int i = 0; i < n; i++) {
      if (cnt[i] == 0) {
        for (int j = 0; j < n; j++) {
          cnt[j] -= (a[i][j] == '1');
        }
        ret.push_back(i);
      }
    }
  }
  sort(ret.begin(), ret.end());
  int sz = ret.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) {
    if (i > 0) putchar(' ');
    printf("%d", ret[i] + 1);
  }
  printf("\n");
  return 0;
}