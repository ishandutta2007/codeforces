#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
const int K = 20;

pair<int, int> elf[N];
int dp_right[1 << K];
int dp_left[1 << K];
int identity[K];
int perm[N][K];
int k;

int apply(int* a, bitset<K> b) {
  bitset<K> res;
  for (int i = 0; i < k; ++i) {
    res[i] = b[a[i]];
  }
  return res.to_ulong();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  bitset<K> s, t;
  cin >> n >> m >> k >> s >> t;

  for (int i = 1; i <= n; ++i) {
    cin >> elf[i].first >> elf[i].second;
    elf[i].second = k - elf[i].second;
    elf[i].first = k - elf[i].first;
  }

  iota(perm[0], perm[0] + k, 0);
  for (int i = 1; i <= n; ++i) {
    iota(identity, identity + k, 0);
    swap(identity[elf[i].first], identity[elf[i].second]);
    for (int j = 0; j < k; ++j) {
      perm[i][j] = identity[perm[i - 1][j]];
    }
  }

  fill(dp_left, dp_left + (1 << k), n + 1);
  fill(dp_right, dp_right + (1 << k), -1);
  for (int i = 0; i <= n; ++i) {
    dp_left[apply(perm[n - i], s)] = n - i;
    dp_right[apply(perm[i], t)] = i;
  }

  int best = 0;
  int ans_l = 0;
  int ans_r = n;

  for (int mask = (1 << k) - 1; mask >= 0; --mask) {
    if (dp_right[mask] < n && dp_left[mask] >= 0 &&
        dp_right[mask] - dp_left[mask] >= m && __builtin_popcount(mask) > best) {
      best = __builtin_popcount(mask);
      ans_l = dp_left[mask];
      ans_r = dp_right[mask];
    }

    for (int i = 0; i < k; ++i) {
      if ((mask & (1 << i)) > 0) {
        int mask_new = mask ^ (1 << i);
        dp_right[mask_new] = max(dp_right[mask_new], dp_right[mask]);
        dp_left[mask_new] = min(dp_left[mask_new], dp_left[mask]);
      }
    }
  }

  s = apply(perm[ans_l], s);
  t = apply(perm[ans_r], t);
  s ^= t;

  cout << k - s.count() << "\n";
  cout << ans_l + 1 << " " << ans_r << "\n";
}