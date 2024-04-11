#include <bits/stdc++.h>
using namespace std;

const int N = 1000000 + 1;

map<int, int> memo;
int prefix[N][10];

int solve(int a) {
  if (memo.count(a) == 0) {
    if (a < 10) {
      memo[a] = a;
    } else {
      int b = a, p = 1;
      while (b > 0) {
        if (b % 10 > 0) {
          p *= b % 10;
        }
        b /= 10;
      }
      memo[a] = solve(p);
    }
  }
  return memo[a];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i < N; ++i) {
    copy(prefix[i - 1], prefix[i - 1] + 10, prefix[i]);
    ++prefix[i][solve(i)];
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << prefix[r][k] - prefix[l - 1][k] << "\n";
  }
}