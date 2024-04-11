#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    multiset<int> piles;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      piles.insert(a);
    }

    int turn = 0;
    int hand = 0;
    while (!piles.empty()) {
      int take = *(--piles.end());
      piles.erase(--piles.end());
      if (hand > 0) {
        piles.insert(hand);
      }
      hand = take - 1;
      ++turn;
    }

    cout << (turn % 2 == 0 ? "HL" : "T") << "\n";
  }
}