#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;
const int L = 30;

long long sum[N];
int nxt[N][L];
int a[N];
int n;

bool check(int i, int j) {
  if (j == n || i + 1 > j - 1) {
    return false;
  }
  return (a[i] ^ a[j]) == sum[j - 1] - sum[i];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  fill(nxt[n], nxt[n] + L, n);
  int ans = 0;

  for (int z = 0; z < 2; ++z) {
    for (int i = n - 1; i >= 0; --i) {
      copy(nxt[i + 1], nxt[i + 1] + L, nxt[i]);
      nxt[i][__lg(a[i])] = i;
    }

    for (int i = 0; i < n; ++i) {
      sum[i] = (i == 0 ? 0 : sum[i - 1]) + a[i];
    }

    for (int i = 0; i < n; ++i) {
      if (z == 0) {
        ans += check(i, nxt[i + 1][__lg(a[i])]);
      }

      for (int j = __lg(a[i]) + 1; j < L; ++j) {
        int ptr = i;
        for (int k = 0; k < 2 && ptr < n; ++k) {
          ptr = nxt[ptr + 1][j];
          ans += check(i, ptr);
        }
      }
    }

    reverse(a, a + n);
  }

  cout << ans << "\n";
}