/**
 *    author:  tourist
 *    created: 15.04.2020 19:30:27       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long X, Y;
  cin >> X >> Y;
  vector<int> qs(n);
  auto Ask = [&](int i) {
    qs[i] += 1;
    cout << "+ " << i + 1 << endl;
    long long x, y;
    cin >> x >> y;
    auto p = make_pair(x - X, y - Y);
    X = x;
    Y = y;
    return p;
  };
  long long a, b, c, d;
  long long e = -1;
  auto p0 = Ask(1);
  if (p0.second != 0) {
    auto p1 = Ask(0);
    auto p2 = Ask(1);
    auto p3 = Ask(0);
    c = p2.second - p0.second;
    b = p1.second / c - 1;
    a = 0;
    while (a * (a + 1) / 2 != p3.first) {
      ++a;
    }
    d = p0.second / c - a;
  } else {
    auto p1 = Ask(2);
    if (p1.second != 0) {
      auto p2 = Ask(0);
      auto p3 = Ask(0);
      a = 0;
      while (a * (a + 1) / 2 != p3.first) {
        ++a;
      }
      c = 0;
      b = p2.second - 1;
      long long x = p1.second - (b + 1) * a;
      if (x == 0) {
        d = 0;
      } else {
        if (n == 4) {
          d = x / (b + 1);
        } else {
          auto p4 = Ask(1);
          d = p4.second / (c + 1) - (a + 2);
          e = x / d - (b + 1);
        }
      }
    } else {
      auto p2 = Ask(1);
      auto p3 = Ask(2);
      b = 0;
      while (b * (b + 1) / 2 != p2.first) {
        ++b;
      }
      c = 0;
      while (c * (c + 1) / 2 != p3.first) {
        ++c;
      }
      a = 0;
      d = 0;
    }
  }
  vector<long long> res(n);
  res[0] = a;
  res[1] = b;
  res[2] = c;
  res[3] = d;
  int j = 4;
  if (e != -1) {
    res[4] = e;
    j = 5;
  }
  while (j < n) {
    assert(res[j - 2] + qs[j - 2] != 0);
    if (res[j - 1] + qs[j - 1] != 0) {
      auto p = Ask(j - 2);
      long long u = p.second;
      u -= (res[j - 4] + qs[j - 4]) * (res[j - 3] + qs[j - 3]);
      u -= (res[j - 3] + qs[j - 3]) * (res[j - 1] + qs[j - 1]);
      u /= res[j - 1] + qs[j - 1];
      res[j] = u;
      ++j;
    } else {
        auto p = Ask(j - 1);
        long long u = p.second;
        u -= (res[j - 3] + qs[j - 3]) * (res[j - 2] + qs[j - 2]);
        if (j == n - 1 || u == 0) {
          res[j] = u / (res[j - 2] + qs[j - 2]);
          ++j;
        } else {
          auto q = Ask(j - 2);
          long long v = q.second;
          v -= (res[j - 4] + qs[j - 4]) * (res[j - 3] + qs[j - 3]);
          v -= (res[j - 3] + qs[j - 3]) * (res[j - 1] + qs[j - 1]);
          res[j] = v;
          res[j + 1] = u / v - (res[j - 2] + qs[j - 2] - 1);
          j += 2;
        }
    }
  }
  cout << "!";
  for (int i = 0; i < n; i++) {
    cout << " " << res[i];
  }
  cout << endl;
  return 0;
}