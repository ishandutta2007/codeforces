#include <bits/stdc++.h>
using namespace std;

map<int, long long> best_new[2];
map<int, long long> best[2];

void check_min(map<int, long long> &mp, int key, long long value) {
  if (mp.count(key) == 0) {
    mp[key] = value;
  } else {
    mp[key] = min(mp[key], value);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  best[0][0] = 0;
  int prv = 0;

  for (int i = 0; i < n; ++i) {
    int l, r, a;
    cin >> l >> r >> a;

    if (prv != l) {
      for (auto i : best[1]) {
        best[0].insert(i);
      }
      best[1].clear();
    }
    prv = r;

    for (auto j : {0, 1}) {
      best_new[j].clear();
    }

    for (auto j : {0, 1}) {
      for (auto [magazine, spent] : best[j]) {
        if (j == 0) {
          check_min(best[1], m, spent + magazine);
        }

        int remain = (m - (a - magazine) % m) % m;

        if (0 >= a - magazine) {
          check_min(best_new[(l == r)], magazine - a, spent + a);
        } else if ((long long) (r - l - 1) * m >= a - magazine) {
          check_min(best_new[0], remain, spent + a);
        } else if ((long long) (r - l) * m >= a - magazine) {
          check_min(best_new[1], remain, spent + a);
        }
      }
    }

    swap(best_new, best);
  }

  long long ans = LLONG_MAX;
  for (auto i : {0, 1}) {
    for (auto [magazine, spent] : best[i]) {
      ans = min(ans, spent);
    }
  }

  if (ans == LLONG_MAX) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
}