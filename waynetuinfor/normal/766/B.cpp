#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int n;
long long a[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    if (i + 3 > n) break;
    if (a[i] + a[i + 1] > a[i + 2]) return cout << "YES\n", 0;
  }
  cout << "NO\n";
  return 0;
}