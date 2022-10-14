#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  const int MX = 1e3 + 5;
  vector<int> cnt(MX, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int diff = 0;
  for (int i = 0; i < MX; i++) {
    if (cnt[i] > 0) {
      diff++;
    }
  }
  if (diff != 2) {
    cout << "NO" << '\n';
    return 0;
  }
  for (int i = 0; i < MX; i++) {
    if (cnt[i] > 0 && cnt[i] != n / diff) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  for (int i = 0; i < MX; i++) {
    if (cnt[i] > 0) {
      cout << i << " ";
    }
  }
  return 0;
}