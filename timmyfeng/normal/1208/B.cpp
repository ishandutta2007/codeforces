#include <bits/stdc++.h>
using namespace std;

const int N = 2'000;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int pairs = 0;
  map<int, int> count;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pairs += (count[a[i]]++ == 1);
  }

  if (pairs == 0) {
    cout << 0 << "\n";
    exit(0);
  }

  int ans = n;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      pairs -= (--count[a[j]] == 1);
      if (pairs == 0) {
        ans = min(ans, j - i + 1);
      }
    }
    for (int j = i; j < n; ++j) {
      pairs += (count[a[j]]++ == 1);
    }
  }

  cout << ans << "\n";
}