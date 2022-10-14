#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> left(n, -n);
  vector<int> right(n, 2 * n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      left[i] = i;  
    } else {
      if (i != 0) {
        left[i] = left[i - 1];
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 0) {
      right[i] = i;
    } else {
      if (i != n - 1) {
        right[i] = right[i + 1];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << min(i - left[i], right[i] - i) << " ";
  }
  return 0;   
}