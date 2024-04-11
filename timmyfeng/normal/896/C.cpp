#include <bits/stdc++.h>
using namespace std;

int seed;

int rand_int(int a) {
  int res = seed;
  seed = (seed * 7LL + 13) % int(1e9 + 7);
  return res % a + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, mx;
  map<int, int64_t> mp;
  cin >> n >> m >> seed >> mx;

  for (int i = 1; i <= n; ++i) {
    int a = rand_int(mx);
    if (mp.empty() || (--mp.end())->second != a) {
      mp[i] = a;
    }
  }
  mp[n + 1] = 0;

  for (int i = 1; i <= m; ++i) {
    int type = rand_int(4);
    int l = rand_int(n);
    int r = rand_int(n);
    if (l > r) {
      swap(l, r);
    }

    auto it_l = --mp.upper_bound(l);
    if (it_l->first != l) {
      mp[l] = it_l->second;
      ++it_l;
    }

    auto it_r = --mp.upper_bound(r + 1);
    if (it_r->first != r + 1) {
      mp[r + 1] = it_r->second;
      ++it_r;
    }

    if (type == 1) {
      int x = rand_int(mx);
      for (auto it = it_l; it != it_r; ++it) {
        it->second += x;
      }
    } else if (type == 2) {
      int x = rand_int(mx);
      it_l->second = x;
      mp.erase(++it_l, it_r);
    } else {
      vector<array<int64_t, 2>> vals;
      for (auto it = it_l; it != it_r; ++it) {
        auto nxt = it;
        ++nxt;
        vals.push_back({it->second, nxt->first - it->first});
      }

      int64_t ans = 0;
      if (type == 3) {
        int x = rand_int(r - l + 1) - 1;
        sort(vals.begin(), vals.end());
        for (auto [b, c] : vals) {
          if (x < c) {
            ans = b;
            break;
          }
          x -= c;
        }
      } else {
        int x = rand_int(mx);
        int y = rand_int(mx);
        for (auto [b, c] : vals) {
          int val = 1;
          int e = x;
          b %= y;
          while (e > 0) {
            if (e % 2 == 1) {
              val = val * b % y;
            }
            b = b * b % y;
            e /= 2;
          }
          ans = (ans + val * c) % y;
        }
      }
      cout << ans << "\n";
    }
  }
}