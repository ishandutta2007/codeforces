#include <bits/stdc++.h>
using namespace std;

const long long U = 69696969696969LL;
const int N = 4000 + 1;
const int D = 65;
const int K = 90;

long long first[N][D][K];
long long second[N][D][K];

long long prefix[N];
long long suffix[N];

int a[N];
int n;

long long solve(int l, int r, int k) {
  if (l <= r) {
    if (first[l][r - l][k] == U) {
      if (l + r + k > n) {
        first[l][r - l][k] = prefix[l] - suffix[r];
      } else if (l + r + k == n) {
        first[l][r - l][k] = solve(l + k, r, k);
      } else {
        first[l][r - l][k] = max(
            solve(l + k, r, k),
            solve(l + k + 1, r, k + 1)
        );
      }
    }
    return first[l][r - l][k];
  } else {
    if (second[r][l - r][k] == U) {
      if (l + r + k > n) {
        second[r][l - r][k] = prefix[l] - suffix[r];
      } else if (l + r + k == n) {
        second[r][l - r][k] = solve(l, r + k, k);
      } else {
        second[r][l - r][k] = min(
            solve(l, r + k, k),
            solve(l, r + k + 1, k + 1)
        );
      }
    }
    return second[r][l - r][k];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
    prefix[i] = prefix[i - 1] + a[i - 1];
    suffix[i] = suffix[i - 1] + a[n - i];
  }

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < D; ++j) {
      for (int k = 0; k < K; ++k) {
        first[i][j][k] = U;
        second[i][j][k] = U;
      }
    }
  }

  cout << solve(0, 0, 1) << "\n";
}