#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;     
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (n >= i) {
      v.push_back(i);
      n -= i;
    }
  }                   
  v[(int) v.size() - 1] += n;
  cout << v.size() << '\n';
  for (int i = 0; i < (int) v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}