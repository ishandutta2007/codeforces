#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& i : p) {
      cin >> i;
    }
    reverse(p.begin(), p.end());
    for (auto i : p) {
      cout << i << " ";
    }
    cout << "\n";
  }
}