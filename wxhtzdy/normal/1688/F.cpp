#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<int> l(m);
    vector<int> r(m);
    for (int i = 0; i < m; i++) {
      cin >> l[i] >> r[i];
    }
    long long sa = accumulate(a.begin(), a.end(), 0LL);
    long long sb = accumulate(b.begin(), b.end(), 0LL);
    if (sa != sb) {
      cout << "NO\n";
      continue;
    }
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i] - b[i];
    }
    vector<pair<int, int>> segs;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int ptr = i + 1;
      while (ptr + 1 <= n && pref[ptr] != pref[i]) {
        ptr += 1;
      }
      if (pref[ptr] != pref[i]) {
        ok = false;
      }
      segs.emplace_back(i + 1, ptr);
      i = ptr - 1;
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    vector<int> id(n + 2, -1);
    for (int j = 0; j < (int) segs.size(); j++) {
      auto s = segs[j];
      for (int i = s.first; i <= s.second; i++) {
        id[i] = j;
      }
    }
    vector<int> que;
    vector<int> cnt(m);
    vector<vector<int>> dec(n + 1);
    for (int i = 0; i < m; i++) {
      int cc = 0;
      if (id[l[i]] == id[l[i] - 1]) {
        cc += 1;
      }
      if (id[r[i]] == id[r[i] + 1]) {
        cc += 1;
      }
      cnt[i] = cc;
      if (cc == 0) {
        que.push_back(i);
        continue;
      }
      if (id[l[i]] == id[l[i] - 1]) {
        dec[id[l[i]]].push_back(i);
      }
      if (id[r[i]] == id[r[i] + 1]) {
        dec[id[r[i]]].push_back(i);
      }
    }
    set<int> ids;
    for (int i = id[1]; i <= id[n]; i++) {
      ids.insert(i);
    }
    vector<int> order;
    while (!que.empty()) {
      int x = que.back();
      order.push_back(x);
      que.pop_back();
      while (!ids.empty() && ids.lower_bound(id[l[x]]) != ids.end()) {
        auto it = ids.lower_bound(id[l[x]]);
        int v = *it;
        if (v > id[r[x]]) {
          break;
        }
        ids.erase(it);
        for (int j : dec[v]) {
          cnt[j]--;
          if (cnt[j] == 0) {
            que.push_back(j);
          }
        }
      }
    }
    vector<long long> fenw(n + 1);
    function<void(int, int)> add = [&](int i, int v) {
      for (; i <= n; i += i & -i) {
        fenw[i] += v;
      }
    };
    auto get = [&](int i) {
      long long r = 0;
      for (; i >= 1; i -= i & -i) {
        r += fenw[i];
      }
      return r;
    };
    set<int> alive;
    for (int i = 1; i <= n; i++) {
      alive.insert(i);
      add(i, a[i - 1] - b[i - 1]);
    }
    for (int i : order) {
      long long s = get(r[i]) - get(l[i] - 1);
      if (s == 0) {
        while (!alive.empty()) {
          auto it = alive.lower_bound(l[i]);
          if (it == alive.end() || *it > r[i]) {
            break;
          }
          int j = *it;
          alive.erase(it);
          add(j, b[j - 1] - a[j - 1]);
        }
      } else {
        continue;
      }
    }
    ok = true;
    for (int i = 1; i <= n; i++) {
      ok &= (get(i) == 0);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}