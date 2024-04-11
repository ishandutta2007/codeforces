#include <bits/stdc++.h>
using namespace std;

const int A = 101;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  bitset<A> lines;
  lines.flip();

  for (int i = 0; i < n; ++i) {
    int r;
    cin >> r;
    bitset<A> mask;
    for (int j = 0; j < r; ++j) {
      int a;
      cin >> a;
      mask[a] = 1;
    }
    lines &= mask;
  }

  for (int i = 1; i < A; ++i) {
    if (lines[i]) {
      cout << i << " ";
    }
  }
  cout << "\n";
}