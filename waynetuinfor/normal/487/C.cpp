#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int n, pre[maxn], inv_pre[maxn];

bool prime(int);
int inv(int);
tuple<int, int, int> extgcd(int, int);

int main() {
  // freopen("in0.txt", "r", stdin); freopen("out0.txt", "w", stdout);
  cin >> n;
  if (n == 1) return cout << "YES\n1\n", 0;
  if (n == 4) return cout << "YES\n1\n3\n2\n4\n", 0;
  if (!prime(n)) return cout << "NO\n", 0;
  cout << "YES\n";
  for (int i = 1; i <= n; ++i) inv_pre[i] = inv(i);
  cout << 1 << '\n';
  for (int i = 2; i < n; ++i) cout << (((long long)i * (long long)inv_pre[i - 1]) % n + n) % n << '\n';
  cout << n << '\n';
  return 0;
}

bool prime(int n) {
  for (int i = 2; i <= (int)sqrt(n); ++i) if (n % i == 0) return false;
  return true;
}

int inv(int x) {
  int p = n - 2, ret = 1;
  for (; p; p >>= 1) {
    if (p & 1) ret = ((long long)ret * (long long)x) % n;
    x = ((long long)x * (long long)x) % n;
  }
  return ret;
}