/**
 *    author:  tourist
 *    created: 14.09.2020 20:35:13       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // p[0] < p[1] < ... < p[n - 1]
  // (suppose) we want to move all these piles into ONE point

  // if in one move we could only move one pile:
  // move everything to p[n / 2]

  // if in one move we can move ALL piles from x to x+1 or x-1:
  // we need exactly (p[n - 1] - p[0]) steps

  // finally, if we want to move all piles into TWO points:
  // we have to pick some border position, i
  // now move p[0], p[1], ..., p[i - 1] into one point
  // and p[i], p[i + 1], ..., p[n - 1] into another one
  // and we'll need (p[i - 1] - p[0]) + (p[n - 1] - p[i]) steps
  //   == (p[n - 1] - p[0]) - (p[i] - p[i - 1])

  int n, tt;
  cin >> n >> tt;
  set<int> p;
  multiset<int> d;   // the set of all differences: p[1] - p[0], p[2] - p[1], ...

  auto Add = [&](int x) {
    auto ret = p.insert(x);
    assert(ret.second);
    auto it = ret.first;
    if (next(it) != p.end() && it != p.begin()) {
      d.erase(d.find(*next(it) - *prev(it)));
    }
    if (next(it) != p.end()) {
      d.insert(*next(it) - *it);
    }
    if (it != p.begin()) {
      d.insert(*it - *prev(it));
    }
  };

  auto Remove = [&](int x) {
    auto it = p.find(x);
    assert(it != p.end());
    if (next(it) != p.end()) {
      d.erase(d.find(*next(it) - *it));
    }
    if (it != p.begin()) {
      d.erase(d.find(*it - *prev(it)));
    }
    if (next(it) != p.end() && it != p.begin()) {
      d.insert(*next(it) - *prev(it));
    }
    p.erase(it);
  };

  for (int i = 0; i < n; i++) {
    int foo;
    cin >> foo;
    Add(foo);
  }

  for (int qq = 0; qq <= tt; qq++) {
    {
      //   == (p[n - 1] - p[0]) - (p[i] - p[i - 1])
      if (d.empty()) {
        cout << 0 << '\n';
      } else {
        int max_p = *prev(p.end());
        int min_p = *p.begin();
        int max_d = *prev(d.end());
        cout << max_p - min_p - max_d << '\n';
      }
    }
    if (qq == tt) {
      break;
    }
    int t, x;
    cin >> t >> x;
    if (t == 0) {
      Remove(x);
    } else {
      Add(x);
    }
  }
  return 0;
}