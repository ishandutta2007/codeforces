/**
 *  author: milos
 *  created: 07.01.2021 22:42:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  if (a > b) {
    swap(a, b);
  }
  if (a == b) {
    cout << 0 << '\n';
    return 0;
  }
  long long c = b - a;
  pair<int, long long> ans;
  ans.first = 0;
  ans.second = a * b / __gcd(a, b);
  vector<int> v;
  for (int i = 2; i <= sqrt(c); i++) {
    if (c % i != 0) {
      continue;
    }
    v.push_back(i);
    if (i * i != c) {
      v.push_back(c / i);
    }
  }              
  v.push_back(c);
  for (int i = 0; i < (int) v.size(); i++) {
    if (a % v[i] == 0) {
      long long l = a * b / __gcd(a, b);
      if (l < ans.second) {
        ans.second = l;
        ans.first = 0;
      }
    } else {
      long long k = v[i] - a % v[i];
      long long l = (a + k) * (b + k) / __gcd(a + k, b + k);
      if (l < ans.second) {
        ans.first = k;
        ans.second = l;
      }
    }
  }
  cout << ans.first << '\n';  
  return 0;
}