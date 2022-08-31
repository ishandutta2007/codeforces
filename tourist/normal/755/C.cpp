#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  set <int> s;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int foo;
    scanf("%d", &foo);
    if (foo == i) {
      ans++;
    } else {
      s.insert(foo);
    }
  }
  printf("%d\n", ans + (int) s.size() / 2);
  return 0;
}