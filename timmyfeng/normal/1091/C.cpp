#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  set<long long> fun;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      for (auto j : {i, n / i}) {
        fun.insert((long long) (n / j) * (n / j - 1) / 2 * j + (n / j));
      }
    }
  }

  for (auto i : fun) {
    cout << i << " ";
  }
  cout << "\n";
}