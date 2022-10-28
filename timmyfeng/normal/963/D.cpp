#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int A = 26;

vector<int> pos[N];
string b[N];
int pre[N];
int ndx[N];
int a[N];

struct aho_corasick {

  int to[N][A];
  int link[N];
  int sz = 1;

  void update(const string& s, int i) {
    int cur = 0;
    for (int c : s) {
      c -= 'a';
      if (to[cur][c] == 0) {
        to[cur][c] = sz;
        ++sz;
      }
      cur = to[cur][c];
    }
    ndx[cur] = i;
  }

  void push() {
    queue<int> que;
    que.push(0);

    while (!que.empty()) {
      int u = que.front();
      que.pop();

      if (ndx[link[u]] != 0) {
        pre[u] = link[u];
      } else {
        pre[u] = pre[link[u]];
      }

      for (int i = 0; i < A; ++i) {
        if (to[u][i] != 0) {
          link[to[u][i]] = (u == 0) ? 0 : to[link[u]][i];
          que.push(to[u][i]);
        } else {
          to[u][i] = to[link[u]][i];
        }
      }
    }
  }

} aho;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> s >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    aho.update(b[i], i);
  }

  aho.push();

  int cur = 0;
  for (int i = 0; i < int(s.size()); ++i) {
    cur = aho.to[cur][s[i] - 'a'];
    int u = (ndx[cur] == 0) ? pre[cur] : cur;
    while (u != 0) {
      pos[ndx[u]].push_back(i);
      u = pre[u];
    }
  }

  for (int i = 1; i <= n; ++i) {
    int ans = N;
    for (int j = 0; j + a[i] - 1 < int(pos[i].size()); ++j) {
      ans = min(ans, pos[i][j + a[i] - 1] - pos[i][j] + int(b[i].size()));
    }
    cout << (ans == N ? -1 : ans) << "\n";
  }
}