/**
 *    author:  wxhtzdy
 *    created: 06.08.2022 16:39:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ptr = 0;
    while (ptr < n - 1 && a[ptr + 1] >= a[ptr]) {
      ptr += 1;
    }
    while (ptr < n - 1 && a[ptr + 1] <= a[ptr]) {
      ptr += 1;
    }
    cout << (ptr == n - 1 ? "YES" : "NO") << '\n';
  }
  return 0;
}