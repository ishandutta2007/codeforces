#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  auto Check = [&](long long x) {
    auto a = b;
    long long cnt = 0;
    long long carry = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] == 0) {
        continue;
      }
      long long mn = min((long long) a[i], carry);
      a[i] -= mn;
      carry -= mn;
      if (a[i] == 0) {
        continue;
      }
      if (i >= x) {
        return false;
      }
      long long need = (a[i] + x - i - 1) / (x - i);
      cnt += need;
      carry += need * (x - i) - a[i];
    }
    return cnt <= m;
  };
  long long low = 0, high = 1e15;
  while (low + 1 < high) {
    long long mid = (low + high + 1) >> 1;
    if (Check(mid)) {
      high = mid;
    } else {   
      low = mid;
    }
  }
  cout << high + 1 << '\n';                                             
  return 0;
}