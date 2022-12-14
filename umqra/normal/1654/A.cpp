#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 10;
int a[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int n;
    scanf("%d", &n);
    for (int s = 0; s < n; s++) {
      scanf("%d", &a[s]);
    }
    sort(a, a + n);
    printf("%d\n", a[n - 1] + a[n - 2]);
  }
  return 0;
}