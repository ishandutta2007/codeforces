#include <bits/stdc++.h>
using namespace std;

bool IsPrime(int x) {
  for (int p = 2; p * p <= x; ++p) {
    if (x % p == 0) return false;
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> A(N);
    int s = 0;
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      s += A[i];
    }
    if (!IsPrime(s)) {
      cout << N << "\n";
      for (int i = 0; i < N; ++i) {
        cout << i + 1 << " ";
      }
      cout << "\n";
      continue;
    }
    for (int i = 0; i < N; ++i) {
      if (!IsPrime(s - A[i])) {
        cout << N - 1 << "\n";
        for (int j = 0; j < N; ++j) {
          if (i != j) cout << j + 1 << " ";
        }
        cout << "\n";
        break;
      }
    }
  }
}