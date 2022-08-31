/**
 *    author:  tourist
 *    created: 25.08.2019 18:01:53       
**/
#include <bits/stdc++.h>

using namespace std;

const int BITS = 21;
const int MAX = (1 << BITS);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> bests(MAX, make_pair(-1, -1));
  auto Update = [&](pair<int, int>& p, int v) {
    if (v > p.first) {
      p.second = p.first;
      p.first = v;
    } else {
      p.second = max(p.second, v);
    }
  };
  for (int i = 0; i < n; i++) {
    Update(bests[a[i]], i);
  }
  for (int j = 0; j < BITS; j++) {
    for (int i = 0; i < MAX; i++) {
      if (i & (1 << j)) {
        Update(bests[i ^ (1 << j)], bests[i].first);
        Update(bests[i ^ (1 << j)], bests[i].second);
      }
    }
  }
  auto Can = [&](int num, int high) {
    for (int i = 0; i < n; i++) {
      int x = (a[i] ^ num) & high;
      if (bests[x].second > i) {
        return true;
      }
    }
    return false;
  };
  int ans = 0;
  int high = 0;
  for (int j = BITS - 1; j >= 0; j--) {
    high += (1 << j);
    if (Can(ans + (1 << j), high)) {
      ans += (1 << j);
    }
  }
  cout << ans << '\n';
  return 0;
}