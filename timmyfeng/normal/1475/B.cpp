#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  set<int> ok;
  for (int i = 0; i * 2020 <= N; ++i) {
    for (int j = 0; i * 2020 + j * 2021 <= N; ++j) {
      ok.insert(i * 2020 + j * 2021);
    }
  }

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    cout << (ok.count(n) > 0 ? "YES" : "NO") << "\n";
  }
}