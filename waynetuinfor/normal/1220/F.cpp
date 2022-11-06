#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int iter = 0; iter < 1; ++iter) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    random_shuffle(p.begin(), p.end());
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
      p[i]--;
    }
    auto it = min_element(p.begin(), p.end());
    int sh = it - p.begin();
    rotate(p.begin(), it, p.end());

    auto Solve = [&](const auto &p) {
      vector<vector<int>> sp;
      sp.emplace_back(n);
      for (int i = 0; i < n; ++i) sp[0][i] = p[i];
      for (int i = 1; (1 << i) <= n; ++i) {
        sp.emplace_back(n);
        for (int j = 0; j + (1 << i) <= n; ++j) {
          sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
        }
      }
      vector<int> pos(n);
      for (int i = 0; i < n; ++i) pos[p[i]] = i;

      auto Query = [&](int l, int r) {
        int p = 31 - __builtin_clz(r - l);
        int k = min(sp[p][l], sp[p][r - (1 << p)]);
        return pos[k];
      };

      function<int(int, int)> Dfs = [&](int l, int r) {
        if (l == r) return 0;
        if (r - l == 1) return 1;
        int k = Query(l, r);
        return 1 + max(Dfs(l, k), Dfs(k + 1, r));
      };

      return Dfs(0, n);
    };

    int l = 0, r = n, dep = n + 1, ans = -1;
    while (r - l >= 10) {
      int ml = l + (r - l) / 3;
      int mr = r - (r - l) / 3;
      vector<int> a(p.begin(), p.end());
      vector<int> b(p.begin(), p.end());
      rotate(a.begin(), a.begin() + ml, a.end());
      rotate(b.begin(), b.begin() + mr, b.end());
      int x = Solve(a), y = Solve(b);
      if (x < dep) {
        dep = x;
        ans = ml;
      }
      if (y < dep) {
        dep = y;
        ans = mr;
      }
      if (x < y) r = mr;
      else l = ml;
    };
    for (int i = l; i < r; ++i) {
      vector<int> a(p.begin(), p.end());
      rotate(a.begin(), a.begin() + i, a.end());
      int x = Solve(a);
      if (x < dep) {
        dep = x;
        ans = i;
      }
    }

    cout << dep << ' ' << (ans + sh) % n << "\n";
    // vector<int> v;
    // for (int i = 0; i < n; ++i) {
      // v.push_back(Solve(p));
      // cout << v.back() << " ";
      // rotate(p.begin(), p.begin() + 1, p.end());
    // }
    // cout << endl;
    // int k = min_element(v.begin(), v.end()) - v.begin();
    // int g = count(v.begin(), v.end(), v[k]);
    // for (int i = k - 1; i >= 0; --i) assert(v[i + 1] <= v[i]);
    // for (int i = k + 1; i < n; ++i) assert(v[i - 1] <= v[i]);
    // cout << "g = " << g << endl;
  }
}