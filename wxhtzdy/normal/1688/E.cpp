/**
 *    author:  wxhtzdy
 *    created: 05.06.2022 10:31:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  auto Ask = [&](string s) {
    cout << "? " << s << endl;
    int x;
    cin >> x;
    return x;
  };
  vector<int> l(m);
  for (int i = 0; i < m; i++) {
    string s = string(m, '0');
    s[i] = '1';
    l[i] = Ask(s);
  }    
  vector<int> order(m);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return l[i] < l[j];
  });           
  int ans = 0;
  string s = string(m, '0');
  for (int i : order) {
    s[i] = '1';
    if (Ask(s) == ans + l[i]) {
      ans += l[i];
    } else {
      s[i] = '0';
    }
  }
  cout << "! " << ans << '\n';
  return 0;
}