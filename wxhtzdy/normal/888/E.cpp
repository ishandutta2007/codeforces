/**
 *    author:  milos
 *    created: 08.02.2021 14:49:01       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }                      
  int block = n / 2;
  vector<int> b, c;
  for (int i = 0; i < block; i++) {
    b.push_back(a[i]);
  }
  for (int i = block; i < n; i++) {
    c.push_back(a[i]);
  }
  vector<long long> all;
  long long ans = 0;
  for (int i = 0; i < (1 << (int) b.size()); i++) {
    long long sum = 0;
    for (int j = 0; j < (int) b.size(); j++) {
      if (i & (1 << j)) {
        sum += b[j];  
      }
    }
    sum %= m;
    ans = max(ans, sum);
    all.push_back(sum);
  }
  sort(all.begin(), all.end());
  auto Solve = [&](long long x) {
    auto it = lower_bound(all.begin(), all.end(), m - x);
    return *prev(it);   
  };
  for (int i = 0; i < (1 << (int) c.size()); i++) {
    long long sum = 0;
    for (int j = 0; j < (int) c.size(); j++) {
      if (i & (1 << j)) {
        sum += c[j];
      }
    } 
    sum %= m;
    ans = max(ans, sum);
    ans = max(ans, sum + Solve(sum));
  }
  cout << ans << '\n';
  return 0;
}