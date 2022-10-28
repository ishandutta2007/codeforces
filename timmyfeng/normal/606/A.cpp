#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a[3], b[3];
  for (auto &i : a) {
    cin >> i;
  }

  for (auto &i : b) {
    cin >> i;
  }

  int extra = 0, lack = 0;
  for (int i = 0; i < 3; ++i) {
    if (a[i] > b[i]) {
      extra += (a[i] - b[i]) / 2;
    } else {
      lack += b[i] - a[i];
    }
  }

  cout << (extra >= lack ? "Yes" : "No") << "\n";
}