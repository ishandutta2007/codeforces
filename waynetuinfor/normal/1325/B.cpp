#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<int> s;
    while (n--) {
      int x;
      cin >> x;
      s.insert(x);
    }
    cout << s.size() << "\n";
  }
}