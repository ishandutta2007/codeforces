#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string table;
  cin >> table;

  bool ok = false;
  for (int i = 0; i < 5; ++i) {
    string hand;
    cin >> hand;
    for (int j = 0; j < 2; ++j) {
      ok |= (hand[j] == table[j]);
    }
  }

  cout << (ok ? "YES" : "NO") << "\n";
}