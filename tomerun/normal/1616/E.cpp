#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
#include <array>
#include <numeric>
#include <memory>
#include <random>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;
using vi = vector<int>;

constexpr int64_t INF = 1ll << 60;
int N;
array<int, 100000> s;
array<int, 100000> t;

struct BIT {
  vector<int64_t> v;

  BIT(int size) {
    int len = 1;
    while (len < size) {
      len *= 2;
    }
    v.resize(len + 1);
  }

  int64_t cumulativeSum(int index) {
    int64_t ret = 0;
    while (index > 0) {
      ret += v[index];
      index &= index - 1;
    }
    return ret;
  }

  // inclusive, 1-indexed
  int64_t sum(int l, int r) {
    int64_t ret = cumulativeSum(r) - cumulativeSum(l - 1);
    return ret;
  }

  void add(int index, int64_t val) {
    while (index < v.size()) {
      v[index] += val;
      index += (index & -index);
    }
  }

  void set(int index, int64_t val) {
    int64_t old = sum(index, index);
    add(index, val - old);
  }
};


int64_t solve() {
  cin >> N;
  string str;
  cin >> str;
  for (int i = 0; i < N; ++i) {
    s[i] = str[i] - 'a';
  }
  cin >> str;
  for (int i = 0; i < N; ++i) {
    t[i] = str[i] - 'a';
  }
  vector<vi> pos(26, vi());
  for (int i = N - 1; i >= 0; --i) {
    pos[s[i]].push_back(i);
  }
  BIT bit(N);
  int64_t ans = INF;
  int64_t sum = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < t[i]; ++j) {
      if (pos[j].empty()) continue;
      int from = pos[j].back();
      int move = from + bit.sum(from + 1, N) - i;
      ans = min(ans, sum + move);
    }
    if (pos[t[i]].empty()) break;
    int from = pos[t[i]].back();
    sum += from + bit.sum(from + 1, N) - i;
    bit.add(from + 1, 1);
    pos[t[i]].pop_back();
  }
  return ans == INF ? -1 : ans;
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    auto ans = solve();
    cout << ans << endl;
  }
}