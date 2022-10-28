#include <bits/stdc++.h>
using namespace std;

const int N = 3e5;
const int L = 30;

map<int, int> trie[N * L];
int sub[N * L];
int cnt[N * L];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int m = 1;
  sub[0] = n;
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    int cur = 0;
    while (p > 0) {
      int nxt = 31 - __builtin_clz(p);
      if (trie[cur].count(nxt) == 0) {
        trie[cur][nxt] = m;
        ++m;
      }
      cur = trie[cur][nxt];
      p ^= 1 << nxt;
      ++sub[cur];
    }
    ++cnt[cur];
  }

  vector<pair<int, int>> path;
  for (int i = 0; i < n; ++i) {
    int cur = 0;
    path.emplace_back(0, 0);
    for (int j = L - 1; j >= 0; --j) {
      if ((a[i] & (1 << j)) > 0) {
        if (trie[cur].count(j) != 0) {
          cur = trie[cur][j];
          path.emplace_back(j, cur);
          a[i] ^= 1 << j;
        }
      } else if (cnt[cur] == 0 && trie[cur].begin()->first == j) {
        cur = trie[cur][j];
        path.emplace_back(j, cur);
        a[i] ^= 1 << j;
      }
    }

    cout << a[i] << " ";
    --cnt[cur];

    int pre = -1;
    while (!path.empty()) {
      int u = path.back().second;
      if (pre != -1) {
        trie[u].erase(pre);
      }
      pre = (--sub[u] == 0) ? path.back().first : -1;
      path.pop_back();
    }
  }
  cout << "\n";
}