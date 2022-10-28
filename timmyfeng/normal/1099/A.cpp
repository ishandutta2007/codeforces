#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int w, h;
  cin >> w >> h;
  vector<int> stone(h + 1);
  for (int i = 0; i < 2; ++i) {
    int u, d;
    cin >> u >> d;
    if (d <= h) {
      stone[d] = u;
    }
  }

  while (h > 0) {
    w = max(0, w + h - stone[h]);
    --h;
  }
  cout << w << "\n";
}