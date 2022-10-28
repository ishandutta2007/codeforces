#include <bits/stdc++.h>
using namespace std;

int a[3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int& i : a) {
    cin >> i;
  }
  sort(a, a + 3);
  cout << max(0, a[2] - a[1] - a[0] + 1) << "\n";
}