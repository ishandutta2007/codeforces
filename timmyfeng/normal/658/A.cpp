#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, c;
  cin >> n >> c;

  vector<int> p(n), t(n);
  for (auto &i : p) {
    cin >> i;
  }
  for (auto &i : t) {
    cin >> i;
  }

  int l = 0, r = 0;
  for (int z = 0; z < 2; ++z) {
    int x = 0;
    for (int i = 0; i < n; ++i) {
      x += t[i];
      l += max(0, p[i] - c * x);
    }
    reverse(p.begin(), p.end());
    reverse(t.begin(), t.end());
    swap(l, r);
  }

  if (l > r) {
    cout << "Limak\n";
  } else if (r > l) {
    cout << "Radewoosh\n";
  } else {
    cout << "Tie\n";
  }
}