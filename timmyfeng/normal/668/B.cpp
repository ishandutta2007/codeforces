#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;

int ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  int offset = 1, shift = 0;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      cin >> x;
      shift = (shift + x + n) % n;
    } else {
      if (shift % 2 == 1) {
        offset = (offset + n - 2) % n;
      } else {
        offset = (offset + 2) % n;
      }
      shift ^= 1;
    }
  }

  for (int i = 0; i < n; i += 2) {
    ans[i] = i;
    ans[i + 1] = (i + offset) % n;
  }

  shift = (n - shift) % n;
  rotate(ans, ans + shift, ans + n);
  for (int i = 0; i < n; ++i) {
    cout << ans[i] + 1 << " ";
  }
  cout << "\n";
}