#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
  return a;
}

int mul(int a, int b) {
  return (long long) a * b % M;
}

int pow2[2 * N];

array<int, 2> bracket(array<int, 2> hash) {
  return {hash[0] + 1, add(add(hash[1], hash[1]), 1)};
}

array<int, 2> join(array<int, 2> hash_a, array<int, 2> hash_b) {
  return {hash_a[0] + hash_b[0], add(hash_a[1], mul(hash_b[1], pow2[2 * hash_a[0]]))};
}

map<int, array<int, 2>> code[N];
map<array<int, 2>, int> freq;
vector<int> adj[N];

void dfs_pull(int u, int p) {
  vector<array<int, 2>> sub;
  for (auto c : adj[u]) {
    if (c != p) {
      dfs_pull(c, u);
      sub.push_back(bracket(code[c][u]));
    }
  }
  sort(sub.begin(), sub.end());

  for (auto i : sub) {
    code[u][p] = join(code[u][p], i);
  }

  ++freq[code[u][p]];
}

void dfs_push(int u, int p) {
  int size = adj[u].size();
  vector<array<int, 2>> sub;
  for (auto c : adj[u]) {
    sub.push_back(bracket(code[c][u]));
  }

  vector<int> index(size);
  iota(index.begin(), index.end(), 0);
  sort(index.begin(), index.end(), [&sub](int a, int b) {
    return sub[a] < sub[b];
  });

  vector<array<int, 2>> prefix(size);
  prefix[0] = sub[index[0]];
  for (int i = 1; i < size; ++i) {
    prefix[i] = join(prefix[i - 1], sub[index[i]]);
  }

  vector<array<int, 2>> suffix(size);
  suffix[size - 1] = sub[index[size - 1]];
  for (int i = size - 2; i >= 0; --i) {
    suffix[i] = join(sub[index[i]], suffix[i + 1]);
  }

  for (int i = 0; i < size; ++i) {
    code[u][adj[u][index[i]]] = join(
        i > 0 ? prefix[i - 1] : array<int, 2>(),
        i < size - 1 ? suffix[i + 1] : array<int, 2>()
    );
  }
  code[u][-1] = prefix[size - 1];

  for (auto c : adj[u]) {
    if (c != p) {
      dfs_push(c, u);
    }
  }
}

array<int, 2> ans;

void dfs_ans(int u, int p) {
  ans = max(ans, {(int) freq.size(), u});

  for (auto c : adj[u]) {
    if (c != p) {
      if (--freq[code[u][-1]] == 0) {
        freq.erase(code[u][-1]);
      }
      ++freq[code[u][c]];
      if (--freq[code[c][u]] == 0) {
        freq.erase(code[c][u]);
      }
      ++freq[code[c][-1]];

      dfs_ans(c, u);

      if (--freq[code[u][c]] == 0) {
        freq.erase(code[u][c]);
      }
      ++freq[code[u][-1]];
      if (--freq[code[c][-1]] == 0) {
        freq.erase(code[c][-1]);
      }
      ++freq[code[c][u]];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n == 1) {
    cout << 1 << "\n";
    exit(0);
  }

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  pow2[0] = 1;
  for (int i = 1; i < 2 * n; ++i) {
    pow2[i] = add(pow2[i - 1], pow2[i - 1]);
  }

  dfs_pull(0, -1);
  dfs_push(0, -1);
  dfs_ans(0, -1);

  cout << ans[1] + 1 << "\n";
}