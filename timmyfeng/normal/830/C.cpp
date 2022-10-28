#include <bits/stdc++.h>
using namespace std;

const int N = 100;

long long a[N];
int n;

long long calc(long long d) {
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += (d - a[i] % d) % d;
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long k;
  cin >> n >> k;

  long long mx = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }

  if (mx == 1) {
    cout << k / n +1 << "\n";
    exit(0);
  }

  int i = 1;
  long long ans = 0;
  while (i * i  <= mx) {
    if (calc(i) <= k) {
      ans = i;
    }
    ++i;
  }

  vector<long long> points;
  for (int k = 0; k < n; ++k) {
    int j = 1;
    while (true) {
      int val = (a[k] - 1) / j + 1;
      if (val < i) {
        break;
      }
      points.push_back(val);
      ++j;
    }
  }

  sort(points.begin(), points.end());
  points.erase(unique(points.begin(), points.end()), points.end());
  int m = points.size();

  for (i = 0; i < m; ++i) {
    long long res = calc(points[i]);
    if (res <= k) {
      long long cap = (i == m - 1 ? 1000'000'000'000LL : points[i + 1]); 
      if (cap != points[i] + 1) {
        long long delta = calc(points[i] + 1) - res;
        long long optimal = points[i] + (k - res) / delta;
        if (optimal >= cap) {
          optimal = cap - 1;
        }
        ans = optimal;
      } else {
        ans = points[i];
      }
    }
  }

  cout << ans << "\n";
}