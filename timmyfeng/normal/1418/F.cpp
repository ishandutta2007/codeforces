#include <bits/stdc++.h>
using namespace std;

const int N = 200'000 + 1;

vector<int> divisors[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      divisors[j].push_back(i);
    }
  }

  int n, m;
  long long l, r;
  cin >> n >> m >> l >> r;

  set<array<int, 2>> candidates;
  int ptr_l = m + 1;
  int ptr_r = m;

  for (int x1 = 1; x1 <= n; ++x1) {
    while (x1 * (ptr_l - 1LL) >= l) {
      --ptr_l;
      for (auto i : divisors[ptr_l]) {
        candidates.insert({i, ptr_l});
      }
    }

    while (1LL * x1 * ptr_r > r) {
      for (auto i : divisors[ptr_r]) {
        candidates.erase({i, ptr_r});
      }
      --ptr_r;
    }

    bool ok = false;
    for (auto i : divisors[x1]) {
      auto it = candidates.lower_bound({i + 1, 0});
      if (it == candidates.end()) {
        break;
      }

      auto [j, y1] = *it;
      if (1LL * x1 / i * j <= n) {
        ok = true;
        cout << x1 << " " << y1 << " " << x1 / i * j << " " << y1 / j * i << "\n";
        break;
      }
    }

    if (!ok) {
      cout << -1 << "\n";
    }
  }
}