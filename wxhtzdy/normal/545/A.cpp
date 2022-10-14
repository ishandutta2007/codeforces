#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<int> ids;
  for (int i = 0; i < n; i++) {
    bool ok = true;
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      if (x == 1 || x == 3) {
        ok = false;
      }
    }
    if (ok) {
      ids.push_back(i);
    }
  } 
  cout << ids.size() << '\n';
  for (int i = 0; i < ids.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ids[i] + 1;
  }
  return 0;
}