#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<bool> was(n + 1, false);
  a[0] = a[1] = 1;
  was[1] = true;
  for (int i = 2; i <= n; i++) {
    a[i] = a[i - 1] + a[i - 2];
    if (a[i] <= n) {
      was[a[i]] = true;
    } else break;
  }
  for (int i = 1; i <= n; i++) {
    if (was[i]) {
      cout << "O";
    } else {
      cout << "o";
    }
  }
}