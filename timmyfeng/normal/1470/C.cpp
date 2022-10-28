#include <bits/stdc++.h>
using namespace std;

mt19937 rng((unsigned long long) new char);

int query(int x) {
  cout << "? " << x + 1 << endl;
  int y;
  cin >> y;
  return y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  while (true) {
    int x = uniform_int_distribution<int>(0, n - 1)(rng);
    if (query(x) < k) {
      for (int i = __lg(n) - 1; i >= 0; --i) {
        if (query((x + (1 << i)) % n) < k) {
          x += 1 << i;
        }
      }
      cout << "! " << (x + 1) % n + 1 << endl;
      exit(0);
    }
  }
}