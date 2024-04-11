#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;

void add(int &a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
}

void sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += M;
  }
}

int mul(int a, int b) {
  return (long long) a * b % M;
}

const int N = 2000;

map<int, int> mono;
int sum, l;

void update(int a, int x) {
  auto it = --mono.upper_bound(a);
  if (it->second <= x) {
    return;
  }

  mono[a] = it->second;
  it = mono.find(a);
  while (it->second >= x) {
    auto nxt = it;
    sub(sum, mul((++nxt)->first - it->first, it->second - x));
    mono.erase(it);
    it = nxt;
  }

  mono[a] = x;
}

array<int, 3> candy[N];
multiset<int> where[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k >> l;

  for (int i = 0; i < n; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    candy[i] = {x, y, c - 1};
  }
  sort(candy, candy + n);

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i > 0 && candy[i][0] == candy[i - 1][0]) {
      continue;
    }

    sum = mul(l, l);
    mono.clear();
    mono[l] = -1;
    mono[0] = l;

    fill(where, where + k, multiset<int>());
    for (int j = i; j < n; ++j) {
      where[candy[j][2]].insert(candy[j][1]);
    }

    for (int j = 0; j < k; ++j) {
      where[j].insert(l);
      where[j].insert(-1);
      auto it = where[j].begin();
      while (*it < l) {
        auto nxt = it;
        update(*it + 1, l - *(++nxt));
        it = nxt;
      }
    }

    for (int j = n - 1; j >= i; --j) {
      auto [x, y, c] = candy[j];
      if (j == n - 1 || x != candy[j + 1][0]) {
        int above = candy[i][0] - (i == 0 ? -1 : candy[i - 1][0]);
        int below = (j == n - 1 ? l : candy[j + 1][0]) - x;
        add(ans, mul(sum, mul(above, below)));
      }

      multiset<int> &w = where[c];
      w.erase(w.find(y));

      int prv = *(--w.upper_bound(y));
      int nxt = *w.lower_bound(y);
      update(prv + 1, l - nxt);
    }
  }

  cout << ans << "\n";
}