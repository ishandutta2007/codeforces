#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
const long long A = 1e18;

long long a[N];
long long b[N];
int x[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  long long t;
  cin >> n >> t;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> x[i];
    if (x[i] != n) {
      b[x[i] - 1] = a[x[i]] + t - 1;
    }
  }

  b[n - 1] = 3 * A;
  for (int i = n - 1; i >= 0; --i) {
    if (b[i] == 0) {
      b[i] = b[i + 1] - 1;
    }
  }

  int ptr = 1;
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    while (ptr < n && (ptr < i + 1 || a[ptr] + t <= b[ptr - 1])) {
      ++ptr;
    }
    ok &= (ptr == x[i]);
  }

  if (ok) {
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
      cout << b[i] << " ";
    }
    cout << "\n";
  } else {
    cout << "No\n";
  }
}