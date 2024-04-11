#include <bits/stdc++.h>

using namespace std;

int main() { 
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> v;
  while (n > 1) {
    for (int j = 2; j <= n; j++) {
      if (n % j == 0) {
        v.push_back(j);
        n /= j;
        break;
      }
    }  
  }
  if ((int) v.size() < k) {
    cout << -1;
    return 0;
  }
  int pos = 1;
  while ((int) v.size() - pos + 1 > k) {
    v[0] *= v[pos];
    v[pos] = 0;
    pos++;
  }
  for (int i = 0; i < (int) v.size(); i++) {
    if (v[i] != 0) {
      cout << v[i] << " ";
    } 
  }
  return 0;
}