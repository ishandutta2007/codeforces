#include <bits/stdc++.h>
using namespace std;

const int M = 998'244'353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int ans = 1;
  int factorial = 1;
  for (int i = 2; i <= n; ++i) {
    ans = ((long long) i * (ans + factorial - 1)) % M;
    factorial = (long long) factorial * i % M;
  }

  cout << ans << "\n";
}