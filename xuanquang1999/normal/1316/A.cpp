#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int nTest, n, m, a[MAXN];

int main() {
  scanf("%d", &nTest);
  while (nTest--) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i)
      scanf("%d", &a[i]);

    int sum = accumulate(a+1, a+n, 0);
    a[0] = min(m, a[0] + sum);

    printf("%d\n", a[0]);
  }

  return 0;
}