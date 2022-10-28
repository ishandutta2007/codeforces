#include <bits/stdc++.h>
using namespace std;

const int N = 100'000;

long long x[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int prv = 0;

  for (int i = 1; i < n; i += 2) {
    cin >> x[i];

    int nxt = INT_MAX;
    int cur = INT_MAX;

    for (int j = 1; j * j <= x[i]; ++j) {
      if (x[i] % j == 0 && j % 2 == x[i] / j % 2) {
        if ((x[i] / j - j) / 2 <= prv) {
          break;
        }
        nxt = (x[i] / j + j) / 2;
        cur = (x[i] / j - j) / 2;
      }
    }

    if (cur == INT_MAX) {
      cout << "No\n";
      exit(0);
    }

    x[i - 1] = (long long) (cur - prv) * (cur + prv);
    prv = nxt;
  }

  cout << "Yes\n";
  for (int i = 0; i < n; ++i) {
    cout << x[i] << " ";
  }
  cout << "\n";
}