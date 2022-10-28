#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;

  map<int, int> buy, sell;
  for (int i = 0; i < n; ++i) {
    char d;
    int p, q;
    cin >> d >> p >> q;
    (d == 'B' ? buy : sell)[p] += q;
  }

  while ((int) sell.size() > s) {
    sell.erase(prev(sell.end()));
  }
  while ((int) buy.size() > s) {
    buy.erase(buy.begin());
  }

  for (auto it = sell.rbegin(); it != sell.rend(); ++it) {
    cout << "S " << it->first << " " << it->second << "\n";
  }
  for (auto it = buy.rbegin(); it != buy.rend(); ++it) {
    cout << "B " << it->first << " " << it->second << "\n";
  }
}