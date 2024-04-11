#include <bits/stdc++.h>
using namespace std;

const int N = 3e5;
const int L = 19;

int time_in[N][L];
bool ans[N];
int nxt[L];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  fill(nxt, nxt + L, n);
  for (int i = n - 1; i >= 0; --i) {
    fill(time_in[i], time_in[i] + L, n);
    for (int j = 0; j < L; ++j) {
      if ((a[i] & (1 << j)) > 0) {
        time_in[i][j] = i;
        if (nxt[j] < n) {
          for (int k = 0; k < L; ++k) {
            time_in[i][k] = min(time_in[i][k], time_in[nxt[j]][k]);
          }
        }
        nxt[j] = i;
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;

    bool ok = false;
    for (int j = 0; j < L; ++j) {
      ok |= ((a[y] & (1 << j)) > 0 && y >= time_in[x][j]);
    }
    cout << (ok ? "Shi" : "Fou") << "\n";
  }
}