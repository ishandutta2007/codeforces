/**
 *  author: milos
 *  created: 14.01.2021 23:48:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = sqrt((int) 1.5 * 1e7);
  vector<bool> prime(N, true);
  prime[0] = prime[1] = false;
  vector<int> p;
  for (int i = 2; i <= N; i++) {
    if (!prime[i]) {
      continue;  
    }
    p.push_back(i);
    for (int j = i + i; j <= N; j += i) {
      prime[j] = false;
    }
  }
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int g = 0;
  for (int i = 0; i < n; i++) {
    g = __gcd(g, a[i]);
  }
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    a[i] /= g;
    for (int j : p) {
      if (a[i] % j == 0) {
        cnt[j] += 1;
        while (a[i] % j == 0) {
          a[i] /= j;
        }
      }
    }
    if (a[i] > 1) {
      cnt[a[i]] += 1;
    }
  }
  int ans = n;
  for (auto c : cnt) {
    ans = min(ans, n - c.second);  
  }
  cout << (ans == n ? -1 : ans) << '\n';
  return 0;
}