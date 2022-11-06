#include <bits/stdc++.h>
using namespace std;

int64_t Count(vector<int64_t> a, vector<int64_t> b) {
  if (a[0] > a[1]) swap(a[0], a[1]);
  int64_t res = 0;
  while (true) {
    if (b[0] > b[1]) {
      swap(b[0], b[1]);
    }
    if (b[0] == a[0]) {
      if (b[1] < a[1]) return -1;
      if ((b[1] - a[1]) % b[0] == 0) return res + (b[1] - a[1]) / b[0];
      return -1;
    }
    if (b[0] == 0) break;
    int64_t cnt = b[1] / b[0];
    res += cnt;
    b[1] -= cnt * b[0];
  }
  if (a == b) return res;
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int64_t> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  if (n == 1) {
    if (a == b) {
      cout << "SMALL\n0\n";
    } else {
      cout << "IMPOSSIBLE\n";
    }
    return 0;
  }
  if (n == 2) {
    int64_t x = Count(a, b);
    if (x == -1) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    if (x > 200'000) {
      cout << "BIG\n";
      cout << x << "\n";
      return 0;
    }
  }
  vector<int64_t> rev(a.rbegin(), a.rend());
  vector<char> res;
  while (true) {
    if (b == a || b == rev) break;
    if (!is_sorted(b.begin(), b.end())) {
      if (!is_sorted(b.rbegin(), b.rend())) break;
      res.push_back('R');
      reverse(b.begin(), b.end());
    }
    res.push_back('P');
    for (int i = n - 1; i > 0; --i) {
      b[i] -= b[i - 1];
    }
    if (all_of(b.begin(), b.end() - 1, [](int v) { return v == 0; })) break;
  }
  if (a != b) {
    reverse(a.begin(), a.end());
    res.push_back('R');
  }
  if (a != b) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  int cnt = count(res.begin(), res.end(), 'P');
  if (cnt > 200'000) {
    cout << "BIG\n";
    cout << cnt << "\n";
    return 0;
  }
  cout << "SMALL\n";
  cout << res.size() << "\n";
  while (!res.empty()) {
    cout << res.back();
    res.pop_back();
  }
  cout << "\n";
  return 0;
}