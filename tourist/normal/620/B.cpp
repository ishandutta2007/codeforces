#include <bits/stdc++.h>

using namespace std;

const int cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int ans = 0;
  for (int i = a; i <= b; i++) {
    int x = i;
    while (x > 0) {
      ans += cnt[x % 10];
      x /= 10;
    }
  }
  cout << ans << endl;
  return 0;
}