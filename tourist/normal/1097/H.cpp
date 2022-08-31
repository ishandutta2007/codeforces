/**
 *    author:  tourist
 *    created: 04.01.2019 20:26:25       
**/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 30010;

struct State {
  bitset<MAX> left;
  bitset<MAX> right;
  long long len = 0;
  long long res = 0;
};

int n;
bitset<MAX> all;

State Unite(const State& a, const State& b) {
  State c;
  c.len = a.len + b.len;
  c.res = a.res + b.res;
  c.left = a.left;
  c.right = b.right;
  if (a.len < n - 1) {
    c.left &= (b.left >> a.len) | (all << (n - 1 - a.len));
  }
  if (b.len < n - 1) {
    c.right &= (a.right << b.len) | (all >> (n - 1 - b.len));
  }
  if (a.len + b.len >= n) {
    bitset<MAX> d = a.right & b.left;
    if (a.len < n - 1) {
      d &= (all >> (n - 1 - a.len));
    }
    if (b.len < n - 1) {
      d &= (all << (n - 1 - b.len));
    }
    c.res += d.count();
  }
  return c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int d, m;
  cin >> d >> m;
  vector<int> gen(d);
  for (int i = 0; i < d; i++) {
    cin >> gen[i];
  }
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  long long L, R;
  cin >> L >> R;
  for (int i = 1; i < n; i++) {
    all.set(i);
  }
  vector<vector<State>> states(1, vector<State>(m));
  for (int i = 0; i < m; i++) {
    states[0][i].len = 1;
    if (n == 1) {
      states[0][i].res = b[0] >= i;
    } else {
      for (int j = 1; j < n; j++) {
        if (b[j] >= i) {
          states[0][i].left.set(j);
        }
      }
      for (int j = 1; j < n; j++) {
        if (b[j - 1] >= i) {
          states[0][i].right.set(j);
        }
      }
    }
  }
  long long z = 1;
  while (z <= R / d) {
    int sz = (int) states.size();
    states.resize(sz + 1);
    states[sz].resize(m);
    for (int i = 0; i < m; i++) {
      State cur = states[sz - 1][i];
      for (int j = 1; j < d; j++) {
        cur = Unite(cur, states[sz - 1][(i + gen[j]) % m]);
      }
      states[sz][i] = cur;
    }
    z *= d;
  }
  auto calc = [&](long long up) -> long long {
    State res;
    int shift = 0;
    for (int i = (int) states.size() - 1; i >= 0; i--) {
      z = 1;
      for (int j = 0; j < i; j++) {
        z *= d;
      }
      for (int j = 0; j < d; j++) {
        if (up >= z) {
          res = Unite(res, states[i][(shift + gen[j]) % m]);
          up -= z;
        } else {
          shift = (shift + gen[j]) % m;
          break;
        }
      }
    }
    return res.res;
  };
  cout << calc(R) - calc(L + n - 2) << '\n';
  return 0;
}