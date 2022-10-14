#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll s = accumulate(a.begin(), a.end(), 0LL);
  if (s % 2 == 1) {
    cout << "NO\n";
    return 0;
  }
  sort(a.begin(), a.end());
  if (a[n - 1] > (s - a[n - 1])) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  return 0;
}