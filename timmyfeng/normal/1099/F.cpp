#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int M = 1e6 + 1;

vector<int> adj[N];
long long dist[N];
long long dp[N];
long long tt[N];
long long x[N];
long long t;

template <class T>
struct fenwick_tree {

  T tree[M];

  void update(int a, T val) {
    for ( ; a < M; a += a & -a) {
      tree[a] += val;
    }
  }

  T query(int a) {
    T res = 0;
    for ( ; a; a -= a & -a) {
      res += tree[a];
    }
    return res;
  }

  int kth(T k) {
    int res = 0;
    T cur = 0;
    for (int i = 31 - __builtin_clz(M); i >= 0; --i) {
      if (res + (1 << i) < M - 1 && cur + tree[res + (1 << i)] < k) {
        res += 1 << i;
        cur += tree[res];
      }
    }
    return res + 1;
  }

};

fenwick_tree<long long> ft_cnt;
fenwick_tree<long long> ft_sum;

void dfs(int u) {
  long long remain = t - 2 * dist[u];
  if (remain <= 0)
    return;

  ft_sum.update(tt[u], x[u] * tt[u]);
  ft_cnt.update(tt[u], x[u]);
  long long k = ft_sum.kth(remain);
  long long val = ft_sum.query(k);

  dp[u] = ft_cnt.query(k) - (val > remain ? ((val - remain - 1) / k + 1) : 0LL);

  long long best1 = 0;
  long long best2 = 0;

  for (int c : adj[u]) {
    dfs(c);
    if (dp[c] > best1) {
      best2 = best1;
      best1 = dp[c];
    } else {
      best2 = max(best2, dp[c]);
    }
  }

  ft_cnt.update(tt[u], -x[u]);
  ft_sum.update(tt[u], -x[u] * tt[u]);
  dp[u] = max(dp[u], (u == 1 ? best1 : best2));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n >> t;

  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }

  for (int i = 1; i <= n; ++i) {
    cin >> tt[i];
  }

  for (int i = 2; i <= n; ++i) {
    int p, l;
    cin >> p >> l;
    adj[p].push_back(i);
    dist[i] = dist[p] + l;
  }

  dfs(1);

  cout << dp[1] << "\n";
}