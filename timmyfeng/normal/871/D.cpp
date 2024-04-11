#include <bits/stdc++.h>
using namespace std;

const int N = 10000000 + 1;

int prime[N];
int phi[N];

int pre_prime[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int total = 0;
  iota(phi, phi + n + 1, 0);
  for (int i = 2; i <= n; ++i) {
    if (prime[i] == 0) {
      for (int j = i; j <= n; j += i) {
        if (prime[j] == 0) {
          ++pre_prime[i];
          prime[j] = i;
        }
        phi[j] /= i;
        phi[j] *= i - 1;
      }
    }
    total += (prime[i] * 2 <= n);
  }

  int64_t one = 0;
  int64_t two = 0;

  for (int i = 2; i <= n; ++i) {
    one += i - 1 - phi[i];
  }

  int cnt_prime = 0;
  for (int i = 2; i <= n; ++i) {
    if (prime[i] == i) {
      ++cnt_prime;
    } else {
      int j = i;
      int cnt = 0;
      while (j > 1) {
        int k = prime[j];
        while (j % k == 0) {
          j /= k;
        }
        ++cnt;
      }
      two += phi[i] - 1 - cnt_prime + cnt;
    }
  }

  for (int i = 2; i <= n; ++i) {
    pre_prime[i] += pre_prime[i - 1];
  }

  for (int i = 2; i <= n; ++i) {
    if (prime[i] == i) {
      two += pre_prime[n / i];
      for (int j = i; j <= n; j += i) {
        two -= (prime[j] <= n / i);
      }
    }
  }

  for (int i = 2; i <= n; ++i) {
    int p = i / prime[i];
    two -= (p > 1 && prime[p] == p && p != prime[i]);
  }

  int64_t three = total * (total - 1LL) / 2 - one - two;
  cout << one + 2 * two + 3 * three << "\n";
}