#include <bits/stdc++.h>
using namespace std;

const int A = 1000 * 1000 / 4 + 1;

int partition(vector<int> &a) {
  int n = a.size();

  int sum = accumulate(a.begin(), a.end(), 0);
  if (sum % 2 == 1) {
    return -1;
  }
  sum /= 2;

  vector<bitset<A>> possible(n + 1);
  possible[0][0] = true;

  for (int i = 0; i < n; ++i) {
    possible[i + 1] = possible[i] | possible[i] << a[i];
  }

  if (!possible[n][sum]) {
    return -1;
  }

  int divide = n;
  for (int i = n - 1, j = sum; i >= 0; --i) {
    if (j >= a[i] && possible[i][j - a[i]]) {
      j -= a[i];
    } else {
      swap(a[i], a[--divide]);
    }
  }

  return divide;
}

void solve() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (auto &i : h) {
    cin >> i;
  }

  cin >> n;
  vector<int> v(n);
  for (auto &i : v) {
    cin >> i;
  }

  if (h.size() != v.size()) {
    cout << "No\n";
    return;
  }

  int dh = partition(h);
  int dv = partition(v);

  if (min(dh, dv) < 0) {
    cout << "No\n";
    return;
  }

  cout << "Yes\n";

  bool flip = dh < dv;
  if (flip) {
    swap(dh, dv);
    swap(h, v);
  }

  sort(h.begin() + dh, h.end());
  sort(h.begin(), h.begin() + dh);
  sort(v.begin() + dv, v.end(), greater<int>());
  sort(v.begin(), v.begin() + dv, greater<int>());

  vector<array<int, 2>> points;
  int x = 0;
  int y = 0;

  for (int i = 0; i < n; ++i) {
    y += i < dv ? v[i] : -v[i];
    points.push_back({x, y});
    x += i < dh ? h[i] : -h[i];
    points.push_back({x, y});
  }

  for (auto [a, b] : points) {
    if (flip) {
      cout << b << " " << a << "\n";
    } else {
      cout << a << " " << b << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}