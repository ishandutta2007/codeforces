#include <iostream>
using namespace std;

const int maxn = 100 + 5;
int A[maxn], n, tot;

int main() {
  cin >> n;
  int last = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    tot += A[i];
    if (tot && A[i]) last = i;
  }
  if (!last) { cout << "NO\n"; return 0; }
  if (tot) { cout << "YES\n1\n1 " << n << '\n'; return 0; }
  cout << "YES\n";
  cout << 2 << '\n';
  cout << 1 << ' ' << last << '\n' << last + 1 << ' ' << n << '\n';
  return 0;
}