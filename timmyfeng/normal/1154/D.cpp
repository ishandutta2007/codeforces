#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, b, a;
  cin >> n >> b >> a;

  int cur_b = b, cur_a = a;
  for (int i = 0; i < n; ++i) {
    int s;
    cin >> s;

    if (cur_b + cur_a == 0) {
      cout << i << "\n";
      exit(0);
    }

    if (s == 0) {
      if (cur_a > 0) {
        --cur_a;
      } else {
        --cur_b;
      }
    } else {
      if (cur_b > 0 && cur_a < a) {
        --cur_b, ++cur_a;
      } else {
        --cur_a;
      }
    }
  }

  cout << n << "\n";
}