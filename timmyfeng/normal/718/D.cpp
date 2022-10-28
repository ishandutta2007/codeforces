#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;
const int N = 100000;

int mul(int a, int b) {
  return (long long) a * b % M;
}

int pow2[2 * N];
int pow3[2 * N];

array<int, 3> bracket(array<int, 3> hash) {
  return {
    hash[0] + 1,
    (mul(2, hash[1]) + 1) % M,
    (mul(3, hash[2]) + 1) % M
  };
}

array<int, 3> join(array<int, 3> hash_a, array<int, 3> hash_b) {
  return {
    hash_a[0] + hash_b[0],
    (hash_a[1] + mul(hash_b[1], pow2[2 * hash_a[0]])) % M,
    (hash_a[2] + mul(hash_b[2], pow3[2 * hash_a[0]])) % M
  };
}

array<int, 3> code[N];
vector<int> adj[N];

void dfs_pull(int u, int p) {
  vector<array<int, 3>> sub;
  for (auto c : adj[u]) {
    if (c != p) {
      dfs_pull(c, u);
      sub.push_back(bracket(code[c]));
    }
  }
  sort(sub.begin(), sub.end());

  for (auto i : sub) {
    code[u] = join(code[u], i);
  }
}

set<array<int, 3>> ans;

void dfs_push(int u, int p) {
  int size = adj[u].size();
  vector<array<int, 3>> sub;
  for (auto c : adj[u]) {
    sub.push_back(bracket(code[c]));
  }

  vector<int> index(size);
  iota(index.begin(), index.end(), 0);
  sort(index.begin(), index.end(), [&sub](int a, int b) {
    return sub[a] < sub[b];
  });

  vector<array<int, 3>> prefix(size);
  prefix[0] = sub[index[0]];
  for (int i = 1; i < size; ++i) {
    prefix[i] = join(prefix[i - 1], sub[index[i]]);
  }

  vector<array<int, 3>> suffix(size);
  suffix[size - 1] = sub[index[size - 1]];
  for (int i = size - 2; i >= 0; --i) {
    suffix[i] = join(sub[index[i]], suffix[i + 1]);
  }

  for (int i = 0; i < size; ++i) {
    if (adj[u][index[i]] != p) {
      array<int, 3> prv = code[u];
      code[u] = join(
          i > 0 ? prefix[i - 1] : array<int, 3>(),
          i < size - 1 ? suffix[i + 1] : array<int, 3>()
      );
      dfs_push(adj[u][index[i]], u);
      code[u] = prv;
    }
  }

  if (adj[u].size() < 4) {
    ans.insert(prefix[size - 1]);
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
  pow3[0] = 1;
  for (int i = 1; i < 2 * n; ++i) {
    pow2[i] = mul(2, pow2[i - 1]);
    pow3[i] = mul(3, pow3[i - 1]);
  }

  dfs_pull(0, -1);
  dfs_push(0, -1);

  cout << ans.size() << "\n";
}