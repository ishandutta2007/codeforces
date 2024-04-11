/**
 *    author:  tourist           
 *    created: 28.10.2018 18:47:36       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  scanf("%d %d", &n, &m);
  map<pair<int,int>,int> mp;
  for (int i = 0; i < m; i++) {
    int foo;
    scanf("%d", &foo);
    foo--;
    for (int j = 1; j < n; j++) {
      int bar;
      scanf("%d", &bar);
      bar--;
      mp[make_pair(foo, bar)]++;
      foo = bar;
    }
  }
  vector<int> to(n, -1), from(n, -1);
  for (auto &p : mp) {
    if (p.second == m) {
      to[p.first.first] = p.first.second;
      from[p.first.second] = p.first.first;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (from[i] == -1) {
      int len = 1;
      int x = i;
      while (to[x] != -1) {
        x = to[x];
        len++;
      }
      ans += (long long) len * (len + 1) / 2;
    }
  }
  cout << ans << '\n';
  return 0;
}