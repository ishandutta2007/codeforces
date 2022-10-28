#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;

int where[N], a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    where[a[i]] = i;
  }

  string ans(n, 'B');
  for (int i = n; i > 0; --i) {
    for (int j = where[i] % i; j < n; j += i) {
      if (a[j] > i && ans[j] == 'B') {
        ans[where[i]] = 'A';
      }
    }
  }

  cout << ans << "\n";
}