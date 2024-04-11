#include <bits/stdc++.h>
using namespace std;

const int N = 100;

bool sign[N];
int n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    ++m;
    char a, b;
    cin >> a >> b;

    if (b == '=') {
      break;
    } else if (b == '-') {
      sign[m] = true;
    }
  }

  int n;
  cin >> n;

  int minus = count(sign, sign + m, true);
  int plus = m - minus;

  if (n < plus - minus * n || n > plus * n - minus) {
    cout << "Impossible\n";
    exit(0);
  }
  cout << "Possible\n";

  int x = n;
  for (int i = 0; i < m; ++i) {
    if (i > 0) {
      cout << (sign[i] ? "- " : "+ ");
    }

    --(sign[i] ? minus : plus);
    for (int j = 1; j <= n; ++j) {
      x -= (sign[i] ? -j : j);
      if (x >= plus - minus * n && x <= plus * n - minus) {
        cout << j << " ";
        break;
      }
      x += (sign[i] ? -j : j);
    }
  }

  cout << "= " << n << "\n";
}