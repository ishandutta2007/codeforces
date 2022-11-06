#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, D;
  cin >> N >> D;
  vector<pair<int, int>> p;
  int got = 0;
  for (int i = 0; i < N; ++i) {
    int s, a;
    cin >> s >> a;
    if (s < D) continue;
    if (a <= D) {
      got++;
      continue;
    }
    p.emplace_back(s, a);
  }

  N = p.size();
  if (N == 0) {
    cout << got << "\n";
    return 0;
  }

  auto Type = [&](pair<int, int> p) { return p.first > p.second; };
  auto Get = [&](pair<int, int> p) { return min(p.first, p.second); };

  sort(p.begin(), p.end(),
       [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
         if (Get(lhs) != Get(rhs)) {
           return Get(lhs) < Get(rhs);
         }
         if (Type(lhs) != Type(rhs)) {
           return Type(lhs) > Type(rhs);
         }
         return lhs < rhs;
       });

  vector<int> ds(N + N);
  for (int i = 0; i < N; ++i) {
    ds[i] = p[i].second;
    ds[i + N] = p[i].first;
  }
  sort(ds.begin(), ds.end());
  ds.resize(unique(ds.begin(), ds.end()) - ds.begin());

  vector<int> up, down;
  for (int i = 0; i < N; ++i) {
    if (p[i].first <= p[i].second) {
      up.push_back(i);
    } else {
      down.push_back(i);
    }
  }

  sort(up.begin(), up.end(),
       [&](int i, int j) { return p[i].second > p[j].second; });
  sort(down.begin(), down.end(),
       [&](int i, int j) { return p[i].first > p[j].first; });

  vector<int> extra(N);
  int K = ds.size();
  {
    vector<int> fw(K + 1);

    auto Update = [&](int p, int v) {
      for (int i = p + 1; i <= K; i += i & -i) {
        fw[i] += v;
      }
    };

    auto Query = [&](int p) {
      int res = 0;
      for (int i = p + 1; i > 0; i -= i & -i) {
        res += fw[i];
      }
      return res;
    };

    for (int i = 0, j = 0; i < up.size(); ++i) {
      while (j < down.size() && p[down[j]].first >= p[up[i]].second) {
        int x = lower_bound(ds.begin(), ds.end(), p[down[j]].second) - ds.begin();
        Update(x, 1);
        j++;
      }
      int l = lower_bound(ds.begin(), ds.end(), p[up[i]].first) - ds.begin();
      int r = lower_bound(ds.begin(), ds.end(), p[up[i]].second) - ds.begin();
      extra[up[i]] = max(0, Query(r - 1) - Query(l));
    }
  }

  vector<int> dp(N);
  vector<int> fw(K + 1);

  auto Update = [&](int p, int v) {
    for (int i = p + 1; i <= K; i += i & -i) {
      fw[i] = max(fw[i], v);
    }
  };

  auto Query = [&](int p) {
    int res = 0;
    for (int i = p + 1; i > 0; i -= i & -i) {
      res = max(res, fw[i]);
    }
    return res;
  };

  // cout << "extra: ";
  // for (int i = 0; i < N; ++i) {
  //   cout << extra[i] << " ";
  // }
  // cout << "\n";

  for (int i = 0; i < N; ++i) {
    // cout << p[i].first << " " << p[i].second << endl;
    if (p[i].first <= p[i].second) {
      int t = lower_bound(ds.begin(), ds.end(), p[i].first) - ds.begin();
      dp[i] = Query(t) + 1 + extra[i];
    } else {
      int t = lower_bound(ds.begin(), ds.end(), p[i].second) - ds.begin();
      dp[i] = Query(t) + 1;
    }
    int t = lower_bound(ds.begin(), ds.end(), p[i].second) - ds.begin();
    Update(t, dp[i]);
    // cout << "dp = " << dp[i] << endl;
  }
  cout << got + *max_element(dp.begin(), dp.end()) << "\n";
  return 0;
}