#include <bits/stdc++.h>
using namespace std;

mt19937 rng((unsigned long long) new char);

int read() {
  char c;
  do {
    c = getchar();
  } while (c != '-' && (c < '0' || c > '9'));
  bool negative = (c == '-');
  int res = negative ? 0 : c - '0';
  while (true) {
    c = getchar();
    if (c < '0' || c > '9') {
      break;
    }
    res = 10 * res + c - '0';
  }
  return negative ? -res : res;
}

const int M = 20000;
const int N = 10000;
const int W = 25;
const int K = 10;

vector<int> adj[N];
int to[M], cap[M];

int level[N], ptr[N], que[N], par[N];
int visited[N], timer;
int n, m;

void add(int u, int v, int w) {
  to[m] = v, cap[m] = w;
  adj[u].push_back(m++);
  to[m] = u, cap[m] = 0;
  adj[v].push_back(m++);
}

bool bfs() {
  fill(level, level + n, -1);
  int front = 0, back = 0;
  que[back++] = 0;
  level[0] = 0;

  while (front < back) {
    int u = que[front++];
    for (int c : adj[u]) {
      if (cap[c] > 0 && level[to[c]] == -1) {
        level[to[c]] = level[u] + 1;
        if (to[c] == n - 1) {
          return true;
        }
        que[back++] = to[c];
      }
    }
  }
  return false;
}

int dfs(int u, int flow) {
  if (u == n - 1) {
    return flow;
  }

  int initial = flow;
  for ( ; ptr[u] < (int) adj[u].size(); ++ptr[u]) {
    int c = adj[u][ptr[u]];
    if (cap[c] > 0 && level[to[c]] == level[u] + 1) {
      int res = dfs(to[c], min(flow, cap[c]));
      cap[c ^ 1] += res;
      cap[c] -= res;
      flow -= res;
      if (flow == 0) {
        return initial;
      }
    }
  }
  return initial - flow;
}

int max_flow() {
  int res = 0;
  while (bfs()) {
    fill(ptr, ptr + n, 0);
    res += dfs(0, INT_MAX);
  }
  return res;
}

int edmond_karp() {
  int front = 0, back = 0;
  visited[0] = ++timer;
  que[back++] = 0;
  par[0] = -1;

  while (front < back) {
    int u = que[front++];
    for (int c : adj[u]) {
      if (cap[c] > 0 && visited[to[c]] < timer) {
        visited[to[c]] = timer;
        par[to[c]] = c;
        if (to[c] == n - 1) {
          int flow = INT_MAX;
          for (int j = par[n - 1]; j != -1; j = par[to[j ^ 1]]) {
            flow = min(flow, cap[j]);
          }
          for (int j = par[n - 1]; j != -1; j = par[to[j ^ 1]]) {
            cap[j ^ 1] += flow;
            cap[j] -= flow;
          }
          return flow;
        }
        que[back++] = to[c];
      }
    }
  }
  return 0;
}

int cache[1 << K][M], flow[1 << K], sum[1 << K], weight[K], k;
int prv[1 << K], bit[1 << K], label[N];
array<int, 3> edges[M];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int p, q;
  n = read(), p = read(), k = read(), q = read();

  for (int i = 0; i < p; ++i) {
    for (int j = 0; j < 3; ++j) {
      edges[i][j] = read() - (j < 2);
    }
    adj[edges[i][0]].push_back(edges[i][1]);
  }

  for (int i = 0; i < n; ++i) {
    shuffle(adj[i].begin(), adj[i].end(), rng);
  }

  fill(label, label + n, -1);
  label[0] = 0, label[n - 1] = n - 1;

  int front = 0, back = 0, in = 1;
  visited[0] = ++timer;
  que[back++] = 0;

  while (front < back) {
    int u = que[front++];
    for (int c : adj[u]) {
      if (label[c] == -1) {
        label[c] = in++;
        que[back++] = c;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    if (label[i] == -1) {
      label[i] = in++;
    }
  }

  shuffle(edges + k, edges + p, rng);
  fill(adj, adj + n, vector<int>());
  for (int i = 0; i < p; ++i) {
    add(label[edges[i][0]], label[edges[i][1]], edges[i][2]);
  }

  flow[0] = max_flow();
  copy(cap, cap + m, cache[0]);

  for (int i = 1; i < (1 << k); ++i) {
    prv[i] = i & (i - 1);
    bit[i] = __builtin_ctz(i);
  }

  for (int i = 1; i < (1 << k); ++i) {
    copy(cache[prv[i]], cache[prv[i]] + m, cap);
    flow[i] = flow[prv[i]];
    int j = bit[i];
    cap[2 * j] = W;

    int delta = -1;
    while (delta != 0) {
      delta = edmond_karp();
      flow[i] += delta;
    }
    copy(cap, cap + m, cache[i]);
  }

  int all = (1 << k) - 1;
  while (q--) {
    for (int i = 0; i < k; ++i) {
      weight[i] = read();
    }

    int ans = INT_MAX;
    for (int i = 0; i < (1 << k); ++i) {
      if (i > 0) {
        sum[i] = sum[prv[i]] + weight[bit[i]];
      }
      ans = min(ans, sum[i] + flow[all ^ i]);
    }

    cout << ans << "\n";
  }
}