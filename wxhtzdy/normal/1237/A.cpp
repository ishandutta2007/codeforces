#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  int flag = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      b[i] = a[i] / 2;
    } else {
      b[i] = (a[i] + flag) / 2;
      flag *= -1;  
    }
  }
  for (int i = 0; i < n; i++) {
    cout << b[i] << '\n';
  }
}