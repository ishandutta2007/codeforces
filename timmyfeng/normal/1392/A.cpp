#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    set<int> s;
    for (int i = 0; i < m; ++i) {
      int a;
      cin >> a;
      s.insert(a);
    }

    cout << (s.size() == 1u ? m : 1) << "\n";
  }
}