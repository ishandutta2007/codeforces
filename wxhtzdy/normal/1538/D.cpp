#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int calc(int x) {
  int cnt = 0;
  for (int i = 2; i * i <= x; i++) {
    while (x % i == 0) {
      x /= i;
      cnt++;
    }
  }
  return cnt + (x > 1);
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, k;
    cin >> a >> b >> k;
    if (a == b && k == 1) {
      cout << "NO" << '\n';
      continue;
    }
    int cnt = calc(a) + calc(b);
    int need = 2;
    if (a % b == 0) need--;
    if (b % a == 0) need--;
    cout << (need <= k && k <= cnt ? "YES" : "NO") << '\n';
  }
}