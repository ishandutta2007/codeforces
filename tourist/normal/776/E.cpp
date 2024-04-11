#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

vector <int> primes;

long long phi(long long n) {
  long long res = n;
  for (int it = 0; it < (int) primes.size(); it++) {
    long long p = primes[it];
    if (p * p > n) {
      break;
    }
    if (n % p == 0) {
      res = res / p * (p - 1);
      while (n % p == 0) {
        n /= p;
      }
    }
  }
  if (n > 1) {
    res = res / n * (n - 1);
  }
  return res;
}

const int md = 1000000007;

bool prime[N];

int main() {
  for (int i = 2; i < N; i++) {
    prime[i] = true;
  }
  for (int i = 2; i < N; i++) {
    if (prime[i]) {
      for (int j = i + i; j < N; j += i) {
        prime[j] = false;
      }
    }
  }
  primes.clear();
  for (int i = 2; i < N; i++) {
    if (prime[i]) {
      primes.push_back(i);
    }
  }
  long long n, k;
  cin >> n >> k;
  k = (k + 1) / 2;
  while (n > 1 && k > 0) {
    n = phi(n);
    k--;
  }
  cout << (n % md) << endl;
  return 0;
}