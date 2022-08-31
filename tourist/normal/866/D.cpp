/**
 *    author:  tourist
 *    created: 05.10.2017 21:52:46       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  multiset<int> s;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    s.insert(x);
    if (*s.begin() < x) {
      ans += x - *s.begin();
      s.erase(s.begin());
      s.insert(x);
    }
  }
  cout << ans << endl;
  return 0;
}