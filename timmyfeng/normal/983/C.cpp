#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 1;
const int S = 1e3;
const int F = 10;
const int E = 4;

vector<multiset<int>> vals;
int dist[N][S][F];
int add[S][F];
int sub[S][F];

void gen(const multiset<int>& cur) {
  vals.push_back(cur);
  if (int(cur.size()) < E) {
    for (int i = cur.empty() ? 1 : *(--cur.end()); i < F; ++i) {
      multiset<int> nxt = cur;
      nxt.insert(i);
      gen(nxt);
    }
  }
}

int a[N];
int b[N];

struct state {
  int i;
  int elevator;
  int floor = 1;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
  }

  gen({});

  for (int i = 0; i < int(vals.size()); ++i) {
    for (int j = 1; j < F; ++j) {
      if (int(vals[i].size()) < E) {
        multiset<int> oth = vals[i];
        oth.insert(j);
        add[i][j] = lower_bound(vals.begin(), vals.end(), oth) - vals.begin();
      } else {
        add[i][j] = -1;
      }

      if (vals[i].count(j)) {
        multiset<int> oth = vals[i];
        oth.erase(oth.find(j));
        sub[i][j] = lower_bound(vals.begin(), vals.end(), oth) - vals.begin();
      } else {
        sub[i][j] = -1;
      }
    }
  }

  queue<state> que;
  memset(dist, -1, sizeof dist);

  auto update = [&](const state& v, int d) {
    if (dist[v.i][v.elevator][v.floor] == -1) {
      dist[v.i][v.elevator][v.floor] = d;
      que.push(v);
    }
  };

  update(state(), 0);

  while (!que.empty()) {
    state u = que.front();
    int d = dist[u.i][u.elevator][u.floor];
    que.pop();

    if (u.elevator == 0 && u.i == n) {
      cout << d << "\n";
      exit(0);
    }

    if (u.i + 1 <= n && add[u.elevator][b[u.i + 1]] != -1 && a[u.i + 1] == u.floor) {
      update({u.i + 1, add[u.elevator][b[u.i + 1]], u.floor}, d + 1);
    }

    if (sub[u.elevator][u.floor] != -1) {
      update({u.i, sub[u.elevator][u.floor], u.floor}, d + 1);
    }

    if (u.floor > 1) {
      update({u.i, u.elevator, u.floor - 1}, d + 1);
    }

    if (u.floor + 1 < F) {
      update({u.i, u.elevator, u.floor + 1}, d + 1);
    }
  }
}