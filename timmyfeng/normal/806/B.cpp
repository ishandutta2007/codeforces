#include <bits/stdc++.h>
using namespace std;

const int N = 120;
const int K = 5;

int a[N][K];
int cnt[K];
int n;

int value(int p, int q) {
  if (32LL * p <= q) {
    return 3000;
  } else if (16LL * p <= q) {
    return 2500;
  } else if (8LL * p <= q) {
    return 2000;
  } else if (4LL * p <= q) {
    return 1500;
  } else if (2LL * p <= q) {
    return 1000;
  } else {
    return 500;
  }
}

int check(int mid) {
  int balance = 0;
  for (int i = 0; i < K; ++i) {
    int val = (a[0][i] < a[1][i]) ? value(cnt[i], n + mid) : value(cnt[i] + (a[0][i] == 250 ? 0 : mid), n + mid);
    balance += val / 250 * (a[1][i] - a[0][i]);
  }
  return balance;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < K; ++j) {
      cin >> a[i][j];
      if (a[i][j] != -1) {
        ++cnt[j];
      } else {
        a[i][j] = 250;
      }
    }
  }

  for (int i = 0; i <= 32 * n; ++i) {
    if (check(i) > 0) {
      cout << i << "\n";
      exit(0);
    }
  }

  int lo = 32 * n;
  int hi = 1'000'000'007 + 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (check(mid) > 0) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  cout << (lo > 1'000'000'007 ? -1 : lo) << "\n";
}