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

    int layer;
    cin >> layer;

    int cur = 1;
    int nxt = 0;
    int prv = 0;

    for (int i = 0; i < n - 1; ++i) {
      int a;
      cin >> a;
      if (a < prv) {
        if (--cur == 0) {
          cur = nxt;
          nxt = 0;
          ++layer;
        }
      }
      ++nxt;
      prv = a;
    }

    cout << layer << "\n";
  }
}