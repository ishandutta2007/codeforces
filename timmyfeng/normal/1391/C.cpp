#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int ans = 1;
  for (int i = 2; i <= n; ++i) {
    ans = 1LL * ans * i % M;
  }

  int two = 1;
  for (int i = 1; i < n; ++i) {
    two = (two + two) % M;
  }

  cout << (ans - two + M) % M << "\n";
}