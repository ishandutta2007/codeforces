/**
 *  author: milos
 *  created: 02.01.2021 21:12:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l = 0, r = n - 1, last = 0;
  vector<char> moves;
  while (l <= r) {
    if (a[l] <= a[r]) {
      if (a[l] >= last) {
        moves.push_back('L');
        last = a[l];
        l++;   
      } else {
        if (a[r] >= last) {
          moves.push_back('R');
          last = a[r];
          r--;  
        } else {
          break;
        }
      }
    } else {
      if (a[r] >= last) {
        moves.push_back('R');
        last = a[r];
        r--;
      } else {
        if (a[l] >= last) {
          moves.push_back('L');
          last = a[l];
          l++;
        } else {
          break;
        }
      }
    }
  }       
  cout << moves.size() << '\n';
  for (int i = 0; i < (int) moves.size(); i++) {
    cout << moves[i];
  }
  return 0;
}