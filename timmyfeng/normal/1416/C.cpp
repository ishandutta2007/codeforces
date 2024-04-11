#include <bits/stdc++.h>
using namespace std;

const int N = 300'000;
const int L = 30;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> a(1, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    cin >> a[0][i];
  }

  int ans = 0;
  long long inv = 0;

  for (int i = L - 1; i >= 0; --i) {
    vector<vector<int>> a_new;
    long long inv0 = 0;
    long long inv1 = 0;

    for (auto &j : a) {
      vector<int> zeroes;
      vector<int> ones;

      for (auto k : j) {
        if ((k & (1 << i)) > 0) {
          inv1 += zeroes.size();
          ones.push_back(k);
        } else {
          inv0 += ones.size();
          zeroes.push_back(k);
        }
      }

      if (!zeroes.empty()) {
        a_new.push_back(zeroes);
      }
      if (!ones.empty()) {
        a_new.push_back(ones);
      }
    }

    if (inv0 > inv1) {
      ans ^= 1 << i;
    }
    inv += min(inv0, inv1);
    swap(a, a_new);
  }

  cout << inv << " " << ans << "\n";
}