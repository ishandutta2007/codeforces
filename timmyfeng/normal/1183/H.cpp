#include <bits/stdc++.h>
using namespace std;

struct huge {

  long long value;

  huge() {}

  huge(long long a) : value(a) {}

  void operator+=(huge oth) {
    if (value <= LLONG_MAX - oth.value) {
      value += oth.value;
    } else {
      value = LLONG_MAX;
    }
  }

};

const int N = 100 + 1;
const int A = 26;

huge ways[N][N];
int nxt[N][A];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  long long k;
  cin >> n >> k >> s;

  fill(nxt[n], nxt[n] + A, n);
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < A; ++j) {
      nxt[i][j] = s[i] - 'a' == j ? i : nxt[i + 1][j];
    }
  }

  ways[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < A; ++k) {
        if (nxt[i][k] < n) {
          ways[nxt[i][k] + 1][j + 1] += ways[i][j];
        }
      }
    }
  }

  long long ans = 0;
  for (int i = n; i >= 0 && k > 0; --i) {
    huge count = 0;
    for (int j = 0; j <= n; ++j) {
      count += ways[j][i];
    }
    ans += (n - i) * min(k, count.value);
    k -= count.value;
  }

  cout << (k <= 0 ? ans : -1LL) << "\n";
}