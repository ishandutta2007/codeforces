#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long res = 0;
  long long add = 2 * (n - 2) + 1;
  while (k > 0 && add > 0) {
    res += add;
    add -= 4;
    k--;
  }
  cout << res << endl;
  return 0;
}