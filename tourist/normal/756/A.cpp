#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

bool was[N];
int p[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", p + i);
    p[i]--;
    was[i] = false;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (was[i]) {
      continue;
    }
    ans++;
    int x = i;
    while (!was[x]) {
      was[x] = true;
      x = p[x];
    }
  }
  if (ans == 1) {
    ans = 0;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int foo;
    scanf("%d", &foo);
    sum += foo;
  }
  if (sum % 2 == 0) {
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}