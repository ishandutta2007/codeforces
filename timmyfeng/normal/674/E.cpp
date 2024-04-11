#include <bits/stdc++.h>
using namespace std;

const int N = 500000;
const int D = 64;

double prob[N][D];
int par[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(8);

  int q;
  cin >> q;

  fill(prob[1] + 1, prob[1] + D, 1.0);
  int n = 1;

  while (q--) {
    int type, u;
    cin >> type >> u;

    if (type == 1) {
      par[++n] = u;
      u = n;

      double prv = 1.0;
      fill(prob[u] + 1, prob[u] + D, 1.0);
      for (int i = 1; i < D && par[u]; ++i) {
        int p = par[u];
        double cur = prob[p][i];
        prob[p][i] /= (1.0 + prv) / 2.0;
        prob[p][i] *= (1.0 + prob[u][i - 1]) / 2.0;
        prv = cur;
        u = p;
      }
    } else {
      double ans = 0.0;
      for (int i = 1; i < D; ++i) {
        ans += 1.0 - prob[u][i];
      }
      cout << ans << "\n";
    }
  }
}