#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n;
  cin >> n;

  long long a = 1;
  long long b = 2;
  int ans = 0;

  while (b <= n) {
    long long c = b;
    b += a;
    a = c;
    ++ans;
  }

  cout << ans << "\n";
}