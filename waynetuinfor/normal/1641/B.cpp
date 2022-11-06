#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
      cin >> a[i];
    }

    set<int> s;
    for (int x : a) {
      if (s.count(x)) {
        s.erase(x);
      } else {
        s.insert(x);
      }
    }

    if (!s.empty()) {
      cout << "-1\n";
      continue;
    }

    auto Solve =
        [&](auto self,
            vector<int> a) -> pair<vector<pair<int, int>>, vector<int>> {
      if (a.empty()) {
        return {{}, {}};
      }
      // cerr << "solve a = ";
      // for (int x : a) cerr << x << " ";
      // cerr << "\n";
      int i = find(a.begin() + 1, a.end(), a[0]) - a.begin();
      assert(i < a.size());
      vector<int> b(a.begin() + i + 1, a.end());
      vector<pair<int, int>> ops;
      for (int j = 1; j < i; ++j) {
        ops.emplace_back(i + j, a[j]);
        b.insert(b.begin(), a[j]);
      }
      auto [rop, rdv] = self(self, b);
      rdv.insert(rdv.begin(), i);
      for (auto& [p, c] : rop) {
        p += 2 * i;
      }
      ops.insert(ops.end(), rop.begin(), rop.end());
      return {ops, rdv};
    };

    auto [ops, dv] = Solve(Solve, a);
    cout << ops.size() << "\n";
    for (auto [p, c] : ops) {
      cout << p << " " << c << "\n";
    }
    cout << dv.size() << "\n";
    for (int d : dv) {
      cout << d * 2 << " ";
    }
    cout << "\n";
  }
}