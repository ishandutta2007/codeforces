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
    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }

    vector<bool> win(n + 1);
    for (int i = n - 1; i >= 0; --i) {
      win[i] = ((win[i + 1] && a[i] > 1) || !win[i + 1]);
    }

    cout << (win[0] ? "First" : "Second") << "\n";
  }
}