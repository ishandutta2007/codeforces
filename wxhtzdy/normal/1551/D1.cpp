#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

bool check(int n, int m, int k) {
  if (n % 2 == 1 && k < m / 2) return false;
  if (n % 2 == 1) k -= m / 2;
  if (n % 2 == 1 && k % 2 == 1) return false;
  if (n % 2 == 0 && (k % 2 == 1 || (m % 2 == 1 && 2 * k > n * (m - 1)))) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    cout << (check(n, m, k) ? "YES\n" : "NO\n");
  }
}