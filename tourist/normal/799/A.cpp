#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, t, k, d;
  scanf("%d %d %d %d", &n, &t, &k, &d);
  int steps = (n + k - 1) / k;
  int if_no = steps * t;
  int get = (if_no - 1) / t * k;
  if (if_no - 1 > d) {
    get += (if_no - 1 - d) / t * k;
  }
  puts(get >= n ? "YES" : "NO");
  return 0;
}