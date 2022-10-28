#include <bits/stdc++.h>
using namespace std;

const int M = 10000000 + 1;

bool prime[M], palindrome[M];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int p, q;
  cin >> p >> q;

  fill(prime + 2, prime + M, true);
  for (int i = 2; i < M; ++i) {
    if (prime[i]) {
      for (int j = 2 * i; j < M; j += i) {
        prime[j] = false;
      }
    }
  }

  for (int i = 1; i < M; ++i) {
    string x = to_string(i), y = x;
    reverse(y.begin(), y.end());
    palindrome[i] = (x == y);
  }

  int ans = 0, pi = 0, rub = 0;
  for (int i = 1; i < M; ++i) {
    pi += prime[i];
    rub += palindrome[i];
    if ((long long) q * pi <= (long long) p * rub) {
      ans = i;
    }
  }

  cout << ans << "\n";
}