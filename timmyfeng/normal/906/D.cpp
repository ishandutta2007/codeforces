#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int K = 42;

struct mint {
  int val;
  bool big;
};

mint mul(mint a, mint b, int m) {
  int64_t val = 1LL * a.val * b.val;
  return {int(val % m), a.big || b.big || val >= m};
}

mint mod_pow(mint a, int b, int m) {
  mint res = {1, false};
  while (b > 0) {
    if (b % 2 == 1) {
      res = mul(res, a, m);
    }
    a = mul(a, a, m);
    b /= 2;
  }
  return res;
}

int ans[N][K];
int mods[K];
int a[N];

int phi(int n) {
  int res = n;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      res = res / i * (i - 1);
    }
  }
  if (n > 1) {
    res = res / n * (n - 1);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n >> mods[0];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int cnt = 1;
  while (mods[cnt - 1] != 1) {
    mods[cnt] = phi(mods[cnt - 1]);
    ++cnt;
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;

    mint ans = {1, false};
    for (int k = min(cnt, r - l) - 1; k >= 0; --k) {
      ans = mod_pow({a[l + k], false}, ans.val + (ans.big ? mods[k + 1] : 0), mods[k]);
    }
    cout << ans.val << "\n";
  }
}