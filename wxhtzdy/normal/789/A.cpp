#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    while (a[i] > 2 * k) {
      ans++;
      a[i] -= 2 * k;
    }
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (i < n - 1 && a[i] <= k && a[i + 1] <= k) {
      i++;  
    }    
    ans++;
  }
  cout << ans;
}