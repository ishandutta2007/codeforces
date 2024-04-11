/**
 *    author:  tourist
 *    created: 30.08.2020 17:42:50       
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
    int mx = *max_element(a.begin(), a.end());
    int sum = accumulate(a.begin(), a.end(), 0);
    if (mx > sum - mx || sum % 2 == 1) {
      cout << "T" << '\n';
    } else {
      cout << "HL" << '\n';
    }
  }
  return 0;
}