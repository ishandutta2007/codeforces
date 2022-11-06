#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 5;
int n, it;
double a[MAXN], s1, s2, n1, n2;

int main() {
  cin >> n >> n1 >> n2;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  it = n - 1;
  for (int i = 0; i < min(n1, n2); ++i, --it) s1 += a[it];
  for (int i = 0; i < max(n2, n1); ++i, --it) s2 += a[it];
  cout << fixed << setprecision(8) << (s1 / min(n1, n2)) + (s2 / max(n2, n1)) << '\n';
  return 0;
}