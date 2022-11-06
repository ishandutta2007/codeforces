#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> bit(30);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      for (int j = 0; j < 30; ++j) {
        if (A[i] >> j & 1) {
          bit[j]++;
        }
      }
    }
    vector<int> ans;
    for (int k = 1; k <= N; ++k) {
      bool ok = true;
      for (int i = 0; i < 30; ++i) {
        ok &= bit[i] % k == 0;
      }
      if (ok) ans.push_back(k);
    }
    for (int k : ans) cout << k << " ";
    cout << "\n";
  }
}