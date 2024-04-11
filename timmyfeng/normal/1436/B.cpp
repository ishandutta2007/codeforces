#include <bits/stdc++.h>
using namespace std;

mt19937 rng((unsigned long long) new char);

int rand_int(int a, int b) {
  return uniform_int_distribution<int>(a, b)(rng);
}

const int R = 100000 + 1;
const int N = 100;

int sieve[R * N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 2; i < R * N; ++i) {
    if (sieve[i] == 0) {
      for (int j = i; j < R * N; j += i) {
        sieve[j] = i;
      }
    }
  }

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int sum = 0;
    do {
      sum = 0;
      for (int i = 0; i < n; ++i) {
        do {
          a[i] = rand_int(1, R - 1);
        } while (sieve[a[i]] == a[i]);
        sum += a[i];
      }
    } while (sieve[sum] != sum);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << a[(i + j) % n] << " ";
      }
      cout << "\n";
    }
  }
}