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
    int cnt = (n - 1) / 4 + 1;
    cout << string(n - cnt, '9') << string(cnt, '8') << "\n";
  }
}