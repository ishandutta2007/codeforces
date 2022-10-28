#include <bits/stdc++.h>
using namespace std;

const int N = 400000 + 1;
const int L = __lg(N) + 1;

int par[N][L], maxi[N][L], prv[N][L];
long long sum[N][L];
int length[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;

  int ans = 0, n = 1;
  length[n] = 1;

  for (int t = 0; t < q; ++t) {
    long long type, r, x;
    cin >> type >> r >> x;
    r ^= ans, x ^= ans;

    if (type == 1) {
      par[++n][0] = r;
      maxi[n][0] = x;

      for (int i = __lg(q); i >= 0; --i) {
        if (maxi[r][i] < x) {
          r = par[r][i];
        }
      }

      length[n] = length[r] + 1;
      sum[n][0] = x;
      prv[n][0] = r;

      for (int i = 1; i <= __lg(q); ++i) {
        maxi[n][i] = max(maxi[n][i - 1], maxi[par[n][i - 1]][i - 1]);
        par[n][i] = par[par[n][i - 1]][i - 1];

        sum[n][i] = sum[n][i - 1] + sum[prv[n][i - 1]][i - 1];
        prv[n][i] = prv[prv[n][i - 1]][i - 1];
      }
    } else {
      int u = r;
      ans = 0;
      for (int i = __lg(q); i >= 0; --i) {
        if (sum[r][i] <= x) {
          x -= sum[r][i];
          ans += 1 << i;
          r = prv[r][i];
        }
      }
      ans = min(ans, length[u]);
      cout << ans << "\n";
    }
  }
}