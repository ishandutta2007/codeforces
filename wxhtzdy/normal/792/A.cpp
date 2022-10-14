#include <bits/stdc++.H>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int mini = a[n - 1] - a[0];
  for (int i = 1; i < n; i++) {
    mini = min(mini, a[i] - a[i - 1]);  
  }
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] - a[i - 1] == mini) {
      cnt++;
    }
  }
  cout << mini << " " << cnt;
}