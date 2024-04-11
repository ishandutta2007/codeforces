/**
 *    author:  milos
 *    created: 29.03.2021 18:04:00       
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
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) {
    return a[i] < a[j];  
  });
  auto Ask = [&](int i, int j) {
    cout << "? " << i + 1 << " " <<  j + 1 << endl;
    string foo;
    cin >> foo;
    return foo;  
  };
  vector<pair<int, pair<int, int>>> b;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      b.push_back(make_pair(a[id[j]] - a[id[i]], make_pair(id[j], id[i])));
    }
  }
  sort(b.rbegin(), b.rend());
  for (auto& c : b) {
    string x = Ask(c.second.first, c.second.second);
    if (x == "Yes") {
      cout << "! " << c.second.first + 1 << " " << c.second.second + 1 << endl;
      return 0;
    }
  }
  cout << "! 0 0" << endl;
  return 0;
}