/**
 *    author:  milos
 *    created: 07.06.2021 20:57:07       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, k;
  cin >> m >> k;
  vector<int> a(k);
  vector<bool> was(m + 1, false);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    was[a[i]] = true;
  }
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int d;
    cin >> d;     
    int znm = 0, nzm = 0;
    for (int j = 0; j < d; j++) {
      int c;
      cin >> c;
      if (was[c] == true) {
        ++x[i], ++y[i], ++znm;  
      } 
      if (c == 0) ++nzm;
    }
    int ost = d - znm - nzm;
    x[i] = x[i] + max(nzm - m + k + ost, 0);
    y[i] = y[i] + min(nzm, k - znm);
  }
  for (int i = 0; i < n; i++) {
    bool q = true;
    for (int j = 0; j < n; j++) {
      if (i != j && y[i] < x[j]) {
        q = false;
      }
    }
    bool w = true;
    for (int j = 0; j < n; j++) {
      if (i != j && x[i] < y[j]) {
        w = false;
      }
    }
    if (q == true && w == false) {
      cout << 2 << '\n'; 
    } else { 
      if (w == false) {
        cout << 1 << '\n';
      } else {
        cout << 0 << '\n';
      }
    }
  }
  return 0;
}