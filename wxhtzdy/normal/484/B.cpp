#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int N = 2e6 + 5;
int mx[N];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;

  vector<int> a(n);
  for (int& i : a) cin >> i;

  sort(a.begin(), a.end());
  for (int i : a) mx[i] = i;
  for (int i = 1; i < N; i++) mx[i] = max(mx[i - 1], mx[i]);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && a[i] == a[i - 1]) continue;
    for (int j = 2 * a[i]; j < N; j += a[i]) {
      ans = max(ans, mx[j - 1] % a[i]);
    }
  }
  cout << ans << '\n';
}