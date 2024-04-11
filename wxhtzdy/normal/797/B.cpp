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
  int l = 0, r = 0;
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  long long sum = 0, ans = -1e9, lst = 1e9;
  for (int i = 0; i < n; i++) {
    if (a[i] < 0) {
      break;
    }
    sum += a[i];
    if (abs(a[i]) % 2 == 1) {
      lst = a[i];
    }                         
    if (abs(sum) % 2 == 1) {
      ans = max(ans, sum);
    } else {
      ans = max(ans, sum - lst);
    }
  }
  if (sum % 2 == 0) {
    long long r = -1e9;
    for (int i = 0; i < n; i++) {
      if (a[i] < 0 && abs(a[i]) % 2 == 1) {
        r = max(r, (long long)a[i]);
      }
    }
    ans = max(ans, sum + r);
  }
  cout << (ans == (long long) -1e9 ? (long long) 0 : ans);
  return 0;   
}