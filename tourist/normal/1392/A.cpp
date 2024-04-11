/**
 *    author:  tourist
 *    created: 16.08.2020 17:34:41       
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
    cout << (*min_element(a.begin(), a.end()) == *max_element(a.begin(), a.end()) ? n : 1) << '\n';
  }
  return 0;
}