#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
const int D = 10 + 1;

int inv[D], d, p;

void add(int a, int b, int c) {
  cout << "+ " << a << " " << b << " " << c << "\n";
}

void pow(int a, int b) {
  cout << "^ " << a << " " << b << "\n";
}

void mul(int a, int b, int c) {
  while (b > 0) {
    if (b % 2 == 1) {
      add(a, c, c);
    }
    add(a, a, a);
    b /= 2;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> d >> p;

  for (int i = 1; i < (1 << d); ++i) {
    if ((i & (i - 1)) > 0) {
      add(i & (i - 1), i & -i, i);
    }
    int k = (__builtin_parity(i) == d % 2);
    pow(i, N - 2);
    add(N - 2, N - k, N - k);
  }

  mul(N, p - 1, N - 1);

  inv[1] = 1;
  for (int i = 2; i <= d; ++i) {
    inv[i] = p - (long long) (p / i) * inv[p % i] % p;
  }

  for (int i = 2; i <= d; ++i) {
    inv[i] = (long long) inv[i] * inv[i - 1] % p;
  }

  mul(N - 4, p - 1, N - 3);
  mul(N - 1, inv[d], N - 3);

  cout << "f " << N - 3 << "\n";
}