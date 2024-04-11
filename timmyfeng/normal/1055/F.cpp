#include <bits/stdc++.h>
using namespace std;

const int N = 1'000'000;
const int L = 62;

long long path[N];
int n;

array<int, 2> split(int l, long long bit) {
  int r = l;
  int m = l;
  while (r < n && (path[r] ^ path[l]) < 2 * bit) {
    m += ((path[r] & bit) == 0);
    ++r;
  }
  return {m - l, r - m};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long t;
  cin >> n >> t;

  for (int i = 1; i < n; ++i) {
    int p;
    long long w;
    cin >> p >> w;
    path[i] = path[p - 1] ^ w;
  }
  sort(path, path + n);

  vector<array<int, 2>> pairs;
  pairs.push_back({0, 0});
  long long ans = 0;

  for (long long bit = 1LL << (L - 1); bit > 0; bit >>= 1) {
    long long zeroes = 0;
    for (auto [a, b] : pairs) {
      auto aa = split(a, bit);
      auto bb = split(b, bit);
      for (auto i : {0, 1}) {
        zeroes += (long long) aa[i] * bb[i];
      }
    }

    bool on = (t > zeroes);
    if (on) {
      t -= zeroes;
      ans ^= bit;
    }

    vector<array<int, 2>> pairs_new;
    for (auto [a, b] : pairs) {
      auto aa = split(a, bit);
      auto bb = split(b, bit);
      for (auto i : {0, 1}) {
        if (aa[i] > 0 && bb[i ^ on] > 0) {
          pairs_new.push_back({
              a + (i ? aa[0] : 0),
              b + ((i ^ on) ? bb[0] : 0)
          });
        }
      }
    }
    swap(pairs, pairs_new);
  }

  cout << ans << "\n";
}