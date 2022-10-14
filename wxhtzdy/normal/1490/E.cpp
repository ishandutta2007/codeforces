/**
 *    author:  milos
 *    created: 16.02.2021 16:23:20       
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
    vector<pair<int, int>> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      sum += a[i].first;
      a[i].second = i;    
    }
    sort(a.rbegin(), a.rend());
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (i == 0 || sum >= a[i - 1].first) {
        ans.push_back(a[i].second);  
      } else {
        break;
      }
      sum -= a[i].first;
    }
    cout << (int) ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int c : ans) {
      cout << c + 1 << " ";
    }
    cout << '\n';
  }
  return 0;
}