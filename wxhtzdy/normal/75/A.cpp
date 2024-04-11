/**
 *    author:  milos
 *    created: 04.02.2021 01:42:25       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  auto Get = [&](int x) {
    vector<int> d;
    while (x > 0) {
      if (x % 10 != 0) {
        d.push_back(x % 10);
      }
      x /= 10;
    }       
    reverse(d.begin(), d.end());
    int ans = 0;
    for (int i : d) {
      ans = ans * 10 + i;
    }
    return ans;
  };
  if (Get(a) + Get(b) == Get(a + b)) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }                             
  return 0;
}