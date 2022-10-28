#include <bits/stdc++.h>
using namespace std;

const int N = 1000000 + 1;

int sieve[N];
int ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ans[1] = 1;
  for (int i = 2; i < N; ++i) {
    if (sieve[i] == 0) {
      for (int j = i; j < N; j += i) {
        if (sieve[j] == 0) {
          sieve[j] = i;
        }
      }
    }
    if (2 * i / sieve[i] - 1 <= sieve[i]) {
      long long j = (long long) sieve[i] * (sieve[i] + 1 - i / sieve[i]);
      ++ans[i];
      if (j < N) {
        --ans[j];
      }
    }
    ans[i] += ans[i - 1];
  }

  int t;
  cin >> t;
  
  while (t--) {
    int n;
    cin >> n;
    cout << ans[n] << "\n";
  }
}