#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
  cin >> n;
  if (n <= 1) { cout << -1 << '\n'; return 0; }
  if ((long long)n * (long long)(n + 1) > 1e9) cout << -1 << '\n';
  else cout << n << ' ' << n + 1 << ' ' << n * (n + 1) << '\n';
  return 0;
}