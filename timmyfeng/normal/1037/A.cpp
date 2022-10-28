#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
  return n == 1 ? 1 : 1 + solve(n / 2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  cout << solve(n) << "\n";
}