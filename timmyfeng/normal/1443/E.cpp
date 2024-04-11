#include <bits/stdc++.h>
using namespace std;

vector<long long> fact;

vector<int> kth_perm(int n, long long k) {
  vector<int> values;
  for (int i = 1; i <= n; ++i) {
    values.push_back(i);
  }

  vector<int> perm;
  for (int i = n - 1; i >= 0; --i) {
    int index = k / fact[i];
    perm.push_back(values[index]);
    values.erase(values.begin() + index);
    k %= fact[i];
  }

  return perm;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  fact.assign(16 + 1, 1);
  for (int i = 1; i <= 16; ++i) {
    fact[i] = fact[i - 1] * i;
  }

  int n, q;
  cin >> n >> q;

  long long k = 0;
  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int l, r;
      cin >> l >> r;
      long long sum = 0;
      vector<int> perm = kth_perm(min(16, n), k);

      if (n <= 16) {
        for (int i = l - 1; i < r; ++i) {
          sum += perm[i];
        }
      } else {
        for (int i = max(0, l - n + 16 - 1); i < r - n + 16; ++i) {
          sum += perm[i] + n - 16;
        }
        l = min(l - 1, n - 16);
        r = min(r, n - 16);
        sum -= (long long) l * (l + 1) / 2;
        sum += (long long) r * (r + 1) / 2;
      }

      cout << sum << "\n";
    } else {
      int x;
      cin >> x;
      k += x;
    }
  }
}