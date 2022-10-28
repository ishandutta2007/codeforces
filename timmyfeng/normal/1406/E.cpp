#include <bits/stdc++.h>
using namespace std;

const int N = 100'000 + 1;
const int B = 100;

int sieve[N];
int n;

int size() {
  cout << "A 1" << endl;
  int res;
  cin >> res;
  return res;
}

int remove(int a) {
  if (a > n) {
    return 0;
  }

  cout << "B " << a << endl;
  int res;
  cin >> res;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  vector<int> primes;
  for (int i = 2; i <= n; ++i) {
    if (sieve[i] == 0) {
      primes.push_back(i);
      for (int j = i; j <= n; j += i) {
        sieve[j] = i;
      }
    }
  }

  int ans = 1;
  for (auto p : primes) {
    if (p * p <= n) {
      remove(p);
      while (remove(ans * p) > 0) {
        ans *= p;
      }
    } else {
      break;
    }
  }

  int prv = size();
  for (int i = 0; i < int(primes.size()); ++i) {
    int p = primes[i];
    if (1LL * p * p > n) {
      if (remove(p) == 2) {
        ans *= p;
        break;
      }
      --prv;
    }

    if (i % B == B - 1 || i == int(primes.size()) - 1) {
      int cur = size();
      if (cur != prv) {
        for (int j = i - i % B; j <= i; ++j) {
          if (remove(primes[j]) > 0) {
            ans *= primes[j];
            break;
          }
        }
        break;
      }
    }
  }

  cout << "C " << ans << endl;
}