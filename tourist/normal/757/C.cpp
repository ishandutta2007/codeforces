#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

const int N = 1234567;

vector <int> a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int foo;
    scanf("%d", &foo);
    while (foo--) {
      int bar;
      scanf("%d", &bar);
      a[bar].push_back(i);
    }
  }
  sort(a + 1, a + m + 1);
  int ans = 1;
  int t = 1;
  for (int i = 2; i <= m; i++) {
    if (a[i] == a[i - 1]) {
      t++;
      ans = (long long) ans * t % md;
    } else {
      t = 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}