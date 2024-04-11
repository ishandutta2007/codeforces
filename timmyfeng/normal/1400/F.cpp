#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;
const int K = 5e3;
const int A = 10;

int dist[N][K];

struct aho_corasick {

  int to[K][A];
  int link[K];
  bool bad[K];
  int sz = 1;

  void update(const string& s) {
    int cur = 0;
    for (int c : s) {
      c -= '0';
      if (to[cur][c] == 0) {
        to[cur][c] = sz;
        ++sz;
      }
      cur = to[cur][c];
    }
    bad[cur] = true;
  }

  void push() {
    queue<int> que;
    que.push(0);

    while (!que.empty()) {
      int u = que.front();
      que.pop();
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

string cur;

void gen(int sum, int x) {
  if (sum == x) {
    for (int i = 0; i < int(cur.size()); ++i) {
      for (int j = i; j < int(cur.size()); ++j) {
        int val = 0;
        for (int k = i; k <= j; ++k) {
          val += cur[k] - '0';
        }
        if (val != x && x % val == 0) {
          return;
        }
      }
    }
    aho.update(cur);
    return;
  }

  for (int i = 1; i < 10 && sum + i <= x; ++i) {
    cur += char('0' + i);
    gen(sum + i, x);
    cur.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int x;
  string s;
  cin >> s >> x;

  gen(0, x);
  aho.push();

  int n = s.size();
  int m = aho.sz;

  for (int i = 0; i <= n; ++i) {
    fill(dist[i], dist[i] + m, n);
  }
  dist[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dist[i + 1][j] = min(dist[i + 1][j], dist[i][j] + 1);
      int k = aho.to[j][s[i] - '0'];
      if (!aho.bad[k]) {
        dist[i + 1][k] = min(dist[i + 1][k], dist[i][j]);
      }
    }
  }

  cout << *min_element(dist[n], dist[n] + m) << "\n";
}