#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 3;
const double eps = 0.000000001;
int n, l, a[maxn];

double bs(double, double);
bool check(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> l;
  double Max = 0;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  Max = a[0];
  for (int i = 1; i < n; ++i) Max = max(Max, (double)(a[i] - a[i - 1]) / 2);
  Max = max(Max, (double)(l - a[n - 1]));
  cout << fixed << setprecision(10) << Max << '\n';
  return 0;
}

bool check(double x) {
  if (a[0] > x) return false;
  for (int i = 1; i < n; ++i) {
    if (a[i] - a[i - 1] > 2 * x) return false;
  }
  if (l - a[n - 1] > x) return false;
  return true;
}

double bs(double l, double r) {
  if (r - l < eps) return l;
  double m = (l + r) / 2;
  if (check(m)) return bs(l, m);
  return bs(m, r);
}