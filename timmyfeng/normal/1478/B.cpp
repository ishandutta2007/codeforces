#include <bits/stdc++.h>
using namespace std;

const int K = 100;

bool lucky[K];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int q, d;
    cin >> q >> d;

    fill(lucky, lucky + K, false);
    for (int i = 1; i < K; ++i) {
      lucky[i] |= (i % 10 == d || i / 10 == d);
      if (lucky[i]) {
        for (int j = 1; j <= i; ++j) {
          lucky[i + j] |= lucky[j];
        }
      }
    }

    while (q--) {
      int x;
      cin >> x;
      cout << (x >= K || lucky[x] ? "YES" : "NO") << "\n";
    }
  }
}