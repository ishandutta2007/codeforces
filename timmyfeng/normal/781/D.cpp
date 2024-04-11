#include <bits/stdc++.h>
using namespace std;

const long long R = 1000000000000000000LL;
const int N = 500;
const int L = 60;

bitset<N> adj[N][L][2];

void merge(vector<int> &a, vector<int> &b) {
  vector<int> c;
  merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));
  c.erase(unique(c.begin(), c.end()), c.end());
  a = c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int u, v, b;
    cin >> u >> v >> b;
    adj[u - 1][0][b][v - 1] = true;
  }

  for (int bit = 1; bit < L; ++bit) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < n; ++k) {
          if (adj[i][bit - 1][j][k]) {
            adj[i][bit][j] |= adj[k][bit - 1][j ^ 1];
          }
        }
      }
    }
  }

  long long ans = 0;
  bitset<N> cur;
  cur[0] = true;

  for (int bit = L - 1; bit >= 0; --bit) {
    bitset<N> nxt;
    for (int i = 0; i < n; ++i) {
      if (cur[i]) {
        nxt |= adj[i][bit][__builtin_parityll(ans)];
      }
    }

    if (nxt.count() > 0) {
      cur = nxt;
      ans += 1LL << bit;
    }
  }

  if (ans > R) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
}