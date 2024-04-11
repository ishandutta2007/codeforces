#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cout << 1 << " ";
  if ((n - 2) % 3 != 0) {
    cout << 1 << " " << n - 2 << "\n";
  } else {
    cout << 2 << " " << n - 3 << "\n";
  }
}