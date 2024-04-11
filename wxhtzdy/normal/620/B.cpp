/**
 *    author:  milos
 *    created: 28.01.2021 17:08:36       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  int cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  auto Calc = [&](int x) {
    int sum = 0;
    while (x > 0) {
      sum += cnt[x % 10];
      x /= 10;
    }
    return sum;
  };
  int ans = 0;
  for (int i = a; i <= b; i++) {
    ans += Calc(i);
  }
  cout << ans << '\n';
  return 0;
}