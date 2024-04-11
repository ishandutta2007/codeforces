/**
 *    author:  milos
 *    created: 23.03.2021 20:31:42       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  auto Mask = [&](int c) {
    int x = c;
    vector<int> d;      
    while (x > 0) {
      d.push_back(x % 10);
      x /= 10;
    }
    reverse(d.begin(), d.end());
    int ans = 0;
    for (int i = 0; i < (int) d.size(); i++) {
      if (d[i] == 4 || d[i] == 7) {
        ans = ans * 10 + d[i];
      }
    }
    return ans;
  };
  int c = a + 1;
  while (Mask(c) != b) {
    c++;
  }
  cout << c << '\n';
  return 0;
}