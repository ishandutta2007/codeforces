#include <bits/stdc++.h>
using namespace std;

const int A = 200;

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

    vector<string> ans(n);
    for (int i = 0; i < A; ++i) {
      int cur = 0;
      for (int j = 0; j < n; ++j) {
        if (i >= a[j]) {
          cur ^= 1;
        }
        ans[j] += 'a' + cur;
      }
    }

    cout << string(A, 'a') << "\n";
    for (auto& i : ans) {
      cout << i << "\n";
    }
  }
}