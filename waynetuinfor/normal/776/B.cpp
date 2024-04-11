#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int n, c;
bool prime[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  memset(prime, true, sizeof(prime));
  for (int i = 2; i <= sqrt(n + 1); ++i) {
    if (prime[i]) {
      for (int j = i * i; j <= n + 1; j += i) prime[j] = false;
    }
  }
  if (n <= 2) cout << 1 << '\n';
  else cout << 2 << '\n';
  for (int i = 2; i <= n + 1; ++i) {
    if (prime[i]) cout << 1 << ' ';
    else cout << 2 << ' ';
  }
  return 0;
}