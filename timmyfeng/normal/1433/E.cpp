#include <bits/stdc++.h>
using namespace std;

const int N = 20 + 1;

long long fact[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = fact[i - 1] * i;
  }

  cout << (fact[n] / fact[n / 2] / fact[n / 2] * fact[n / 2 - 1] * fact[n / 2 - 1]) / 2 << "\n";
}