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
  }
  sort(a.begin(), a.end());
  int q;
  cin >> q;          
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    int low = 0, high = n - 1, ans = 0;
    while (low <= high) {
      int mid = (low + high) >> 1;
      if (a[mid] <= x) {
        ans = mid + 1;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}