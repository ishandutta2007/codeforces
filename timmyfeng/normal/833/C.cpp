#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string l, r;
  cin >> l >> r;
  int n = min(18u, r.size());

  if (l == r) {
    cout << 1 << "\n";
    exit(0);
  }

  bool ext = false;
  if (int(r.size()) > n) {
    r = string(n, '9');
    ext = true;
  }

  auto norm = [&](string &s) -> void {
    s = string(n - int(s.size()), '0') + s;
    for (auto &i : s) {
      i -= '0';
    }
  };
  norm(l);
  norm(r);

  int ans = 0;
  vector<int> cnt(10);
  vector<int> used(10);

  auto dfs = [&](auto self, int i, bool less, bool great) -> bool {
    if (i == n || (less && great)) {
      return true;
    }

    int low = great ? 0 : l[i];
    for (int j = less ? 9 : r[i]; j >= low; --j) {
      if (used[j] < cnt[j]) {
        ++used[j];
        if ((great || j >= l[i]) && self(self, i + 1, less || j < r[i], great || j > l[i])) {
          --used[j];
          return true;
        }
        --used[j];
      }
    }
    return false;
  };

  if (ext) {
    cnt[1] = 1;
    cnt[0] = n - 1;
    ans += !dfs(dfs, 0, false, false);
    fill(cnt.begin(), cnt.end(), 0);
  }

  auto solve = [&](auto self, int cur, int left) -> void {
    if (cur == 9) {
      cnt[cur] += left;
      ans += dfs(dfs, 0, false, false);
      cnt[cur] -= left;
    } else {
      for (int i = 0; i <= left; ++i) {
        cnt[cur] += i;
        self(self, cur + 1, left - i);
        cnt[cur] -= i;
      }
    }
  };
  solve(solve, 0, n);

  cout << ans << "\n";
}