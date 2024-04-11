#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
const int M = 1e4;
const int INF = 1e3;

map<int, int> ddist[M];
vector<int> special;
vector<int> vals[M];
vector<int> adj[N];
vector<int> cur;
int sieve[N];
int dist[M];
int ndx[N];
int m;

int calc(const vector<int>& pf) {
  int res = 1;
  for (int i : pf) {
    res *= i + 1;
  }
  return res;
}

void gen(int remain, int pre) {
  if (calc(cur) > 300)
    return;

  vals[m++] = cur;
  for (int i = 1; i <= min(remain, pre); ++i) {
    cur.push_back(i);
    gen(remain - i, i);
    cur.pop_back();
  }
}

void process(int src) {
  if (!ddist[src].empty())
    return;

  special.push_back(src);
  memset(dist, -1, sizeof dist);
  queue<int> que;
  que.push(src);
  dist[src] = 0;

  while (!que.empty()) {
    int u = que.front();
    que.pop();

    int val = calc(vals[u]);
    if (ddist[src].count(val) == 0) {
      ddist[src][val] = dist[u];
    } else {
      ddist[src][val] = min(ddist[src][val], dist[u]);
    }

    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        que.push(v);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 2; i < N; ++i) {
    if (sieve[i] == 0) {
      for (int j = i; j < N; j += i) {
        if (sieve[j] == 0) {
          sieve[j] = i;
        }
      }
    }
  }

  gen(22, 22);

  auto update = [&](int i, vector<int> v) {
    int k = lower_bound(vals, vals + m, v) - vals;
    if (k < m && vals[k] == v) {
      adj[i].push_back(k);
    }
  };

  for (int i = 0; i < m; ++i) {
    vector<int> v = vals[i];
    for (int j = 0; j < int(v.size()); ++j) {
      if (j == 0 || v[j] < v[j - 1]) {
        ++v[j];
        update(i, v);
        --v[j];
      }
      if (j == int(v.size()) - 1 || v[j] > v[j + 1]) {
        if (v[j] == 1) {
          v.pop_back();
          update(i, v);
          v.push_back(1);
        } else {
          --v[j];
          update(i, v);
          ++v[j];
        }
      }
    }
    v.push_back(1);
    update(i, v);
  }

  for (int i = 1; i < N; ++i) {
    int ii = i;
    int pre = 0;
    vector<int> pf;
    while (ii > 1) {
      if (sieve[ii] == pre) {
        ++pf.back();
      } else {
        pf.emplace_back(1);
      }
      pre = sieve[ii];
      ii /= sieve[ii];
    }
    sort(pf.rbegin(), pf.rend());

    ndx[i] = lower_bound(vals, vals + m, pf) - vals;
    process(ndx[i]);
  }

  map<pair<int, int>, int> ans;
  for (int i : special) {
    for (int j : special) {
      int res = INF;
      for (auto [k, d] : ddist[i]) {
        res = min(res, d + ddist[j][k]);
      }
      ans[{i, j}] = res;
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << ans[{ndx[a], ndx[b]}] << "\n";
  }
}