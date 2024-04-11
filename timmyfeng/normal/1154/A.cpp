#include <bits/stdc++.h>
using namespace std;

int a[4];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (auto &i : a) {
    cin >> i;
  }

  sort(a, a + 4);

  for (int i = 0; i < 3; ++i) {
    cout << a[3] - a[i] << " ";
  }
  cout << "\n";
}