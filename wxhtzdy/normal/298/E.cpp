/**
 *    author:  milos
 *    created: 24.03.2021 11:27:30       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n; 
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  if (n == 1) {
    cout << "YES" << '\n';
    cout << s[0] << '\n' << 0 << '\n';
    return 0; 
  }
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) {
    return s[i] < s[j];  
  });                  
  for (int i = 1; i < n; i++) {
    assert(s[i] != s[i - 1]);
  }
  vector<int> a(n), b(n);
  int BLOCK = (n + 2) / 3;
  for (int i = 0; i < BLOCK; i++) {
    a[id[i]] = i;
    b[id[i]] = s[id[i]] - a[id[i]]; 
  }
  for (int i = BLOCK; i < 2 * BLOCK; i++) {
    b[id[i]] = i;
    a[id[i]] = s[id[i]] - b[id[i]];
  }
  for (int i = 2 * BLOCK; i < n; i++) {
    b[id[i]] = n - i - 1;
    a[id[i]] = s[id[i]] - b[id[i]];
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << '\n';
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << b[i];
  }
  cout << '\n';
  for (int i = 0; i < n; i++) {
    assert(a[i] + b[i] == s[i]);
  }
  return 0;
}