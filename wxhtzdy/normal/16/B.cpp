/**           
 *    author:  milos
 *    created: 28.01.2021 07:44:47       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
  }
  vector<int> order(m);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return b[i] > b[j];  
  });
  long long ans = 0;
  for (int i : order) {
    int take = min(n, a[i]);
    ans += take * b[i];
    n -= take;  
  }
  cout << ans << '\n';
  return 0;
}