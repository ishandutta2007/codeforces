#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (cnt[i] == 0) {
      ans++;
    }
  }
  cout << ans << '\n';
  int j = 0;
  vector<bool> was(n, false);
  for (int i = 0; i < n; i++) {
    if (cnt[i] > 0) {
      continue;
    }
    while (j < n) {
      if (a[j] == i) {
        was[a[j]] = true;
        cnt[a[j]]--;
        j++;
        break;
      }
      if (a[j] > i && (was[a[j]] || cnt[a[j]] > 1)) {
        cnt[a[j]]--;
        a[j] = i;
        was[i] = true;
        j++;
        break;
      }
      if (a[j] < i && was[a[j]]) {
        a[j] = i;
        cnt[a[j]]--;
        was[i] = true;
        j++;
        break;
      }
      if (a[j] < i) {
        was[a[j]] = true;
      }
      j++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << a[i] + 1;
  }
  cout << '\n';
  return 0;
}