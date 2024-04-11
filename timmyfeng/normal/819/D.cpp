#include <bits/stdc++.h>
using namespace std;

const int N = 200'000;

int ans[N];
int a[N];

int euclid(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int xx, yy;
  int gcd = euclid(b, a % b, xx, yy);
  x = yy;
  y = xx - (a / b) * yy;
  return gcd;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, n;
  cin >> t >> n;

  int sum_a = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum_a = (sum_a + a[i]) % t;
    if (i == 0) {
      a[i] = 0;
    } else {
      a[i] = (a[i] + a[i - 1]) % t;
    }
  }

  int x, y;
  int count = euclid(sum_a, t, x, y);
  int period = t / count;
  x %= period;
  if (x < 0) {
    x += period;
  }

  map<int, vector<array<int, 2>>> cycles;
  for (int i = 0; i < n; ++i) {
    int dist = (a[i] / count == 0) ? 0 : period - a[i] / count;
    dist = (long long) x * dist % period;
    cycles[a[i] % count].push_back({dist, i});
  }

  for (auto &[id, points] : cycles) {
    sort(points.begin(), points.end());
    int prv = points.back()[0] - period;
    for (auto [z, i] : points) {
      ans[i] = z - prv;
      prv = z;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}