#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int grundy[2 * N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    fill(grundy, grundy + n + m, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int a;
        cin >> a;
        grundy[i + j] ^= a;
      }
    }

    cout << (count(grundy, grundy + n + m, 0) == n + m ? "Jeel" : "Ashish") << "\n";
  }
}