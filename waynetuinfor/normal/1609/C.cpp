#include <bits/stdc++.h>
using namespace std;

int64_t Solve(const vector<bool>& is_prime) {
  int N, E;
  cin >> N >> E;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  vector<int> fp(E, -1), fb(E, -1);
  vector<int> cnt(E);
  vector<int> dp(N);
  int64_t ans = 0;
  for (int i = N - 1; i >= 0; --i) {
    if (A[i] == 1) {
      if (fb[i % E] == -1) {
        if (fp[i % E] != -1) {
          ans += dp[fp[i % E]] + 1;
        }
      } else {
        if (fp[i % E] != -1) {
          if (fp[i % E] < fb[i % E]) {
            ans += dp[fp[i % E]] + 1;
          }
        }
      }
    } else if (is_prime[A[i]]) {
      if (fb[i % E] == -1) {
        if (fp[i % E] == -1) {
          dp[i] = cnt[i % E];
        } else {
          dp[i] = (fp[i % E] - i) / E - 1; 
        }
      } else {
        if (fp[i % E] != -1) {
          dp[i] = (min(fp[i % E], fb[i % E]) - i) / E - 1; 
        } else {
          dp[i] = (fb[i % E] - i) / E - 1; 
        }
      }
      ans += dp[i];
      fp[i % E] = i;
    } else {
      fb[i % E] = i;
    }
    cnt[i % E]++;
  }
  return ans;
}

int main() {
  vector<bool> is_prime(1'000'000 + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int p = 2; p <= 1'000'000; ++p) {
    for (int q = p + p; q <= 1'000'000; q += p) {
      is_prime[q] = false;
    }
  }
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    cout << Solve(is_prime) << "\n";
  }
}