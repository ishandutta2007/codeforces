#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int na, nb, k, m;
  cin >> na >> nb >> k >> m;

  vector<int> a(na), b(nb);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }

  cout << (a[k - 1] < b[nb - m] ? "YES" : "NO") << "\n";
}