#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n, m, k, l;
  cin >> n >> m >> k >> l;
  long long ans = (k + l - 1) / m + 1;
  cout << (ans * m > n ? -1 : ans) << "\n";
}