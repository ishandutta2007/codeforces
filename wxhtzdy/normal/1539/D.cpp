#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  long long s = accumulate(a.begin(), a.end(), 0LL);
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return b[i] > b[j];
  });
  auto Can = [&](long long x) {
    if (x == s) return true;
    vector<pair<long long, long long>> v;
    long long curr = 0;
    for (int id = 0; id < n; id++) {
      int i = order[id];
      long long take = min(a[i], x - curr);
      if (take != a[i]) {
        v.emplace_back(a[i] - take, b[i]);
      }
      curr += take;
    }
    sort(v.begin(), v.end(), [&](pair<long long, long long> x, pair<long long, long long> y) {
      return x.second < y.second;
    });
    curr = x;
    for (int i = 0; i < v.size(); i++) {
      if (curr < v[i].second) {
        return false;
      }
      curr += v[i].first;
    }
    return true;
  };
  long long bot = 0, top = s, ans = s;
  while (bot <= top) {
    long long mid = bot + top >> 1;
    if (Can(mid)) {
      ans = mid;
      top = mid - 1;
    } else {
      bot = mid + 1;
    }
  }
  cout << ans * 2 + s - ans << '\n';
  return 0;
}