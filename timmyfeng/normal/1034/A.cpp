#include <bits/stdc++.h>
using namespace std;

const int A = 1.5e7 + 1;

int sieve[A];
int cnt[A];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 2; i < A; ++i) {
    if (!sieve[i]) {
      for (int j = i; j < A; j += i) {
        sieve[j] = i;
      }
    }
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    int cur = 1;
    while (a != 1) {
      if (cur % sieve[a] != 0) {
        cur = 1;
      }
      cur *= sieve[a];
      a /= sieve[a];
      ++cnt[cur];
    }
  }

  int ans = 0;
  for (int i = 1; i < A; ++i) {
    if (cnt[i] != n) {
      ans = max(ans, cnt[i]);
    }
  }
  cout << (ans == 0 ? -1 : n - ans) << "\n";
}