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
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      ++cnt[a];
    }

    int max_c = 0;
    int cnt_c = 0;
    for (auto [a, c] : cnt) {
      if (c > max_c) {
        max_c = c;
        cnt_c = 0;
      }
      if (c == max_c) {
        ++cnt_c;
      }
    }

    cout << (n - cnt_c) / (max_c - 1) - 1 << "\n";
  }
}