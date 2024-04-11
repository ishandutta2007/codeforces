#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

void Solve() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> adj(N, vector<int>(N, -1));
  vector<int> A(M), B(M), C(M);
  for (int i = 0; i < M; ++i) {
    cin >> A[i] >> B[i] >> C[i];
    A[i]--;
    B[i]--;
    if (C[i] > 0) C[i]--;
    adj[A[i]][B[i]] = i;
    adj[B[i]][A[i]] = i;
  }
  using Bs = bitset<256>;
  vector<array<Bs, 3>> D;
  vector<uint8_t> v;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (adj[i][j] == -1) {
        continue;
      }
      for (int k = j + 1; k < N; ++k) {
        if (adj[i][k] == -1 || adj[j][k] == -1) {
          continue;
        }
        if (C[adj[i][j]] != -1 && C[adj[i][k]] != -1 && C[adj[j][k]] != -1) {
          if ((C[adj[i][j]] + C[adj[i][k]] + C[adj[j][k]]) % 3 != 0) {
            cout << "-1\n";
            return;
          }
        }
        D.push_back({});
        for (int x = 0; x < M; ++x) {
          if (x == adj[i][j] || x == adj[j][k] || x == adj[i][k]) {
            continue;
          }
          D.back()[0].set(x);
        }
        D.back()[1].set(adj[i][j]);
        D.back()[1].set(adj[j][k]);
        D.back()[1].set(adj[i][k]);
        v.push_back(0);
      }
    }
  }
  for (int i = 0; i < M; ++i) {
    if (C[i] != -1) {
      D.push_back({});
      for (int x = 0; x < M; ++x) {
        if (x == i) continue;
        D.back()[0].set(x);
      }
      D.back()[1].set(i);
      v.push_back(C[i]);
    }
  }

  auto Inv = [&](uint8_t x) { return x; };

  int last = 0;

  auto Get = [&](int x, int y) {
    if (D[x][0].test(y)) {
      return 0;
    }
    if (D[x][1].test(y)) {
      return 1;
    }
    if (D[x][2].test(y)) {
      return 2;
    }
    assert(false);
  };

  for (int col = 0; col < M; ++col) {
    int pivot = -1;
    for (int row = last; row < D.size(); ++row) {
      if (D[row][1].test(col) || D[row][2].test(col)) {
        pivot = row;
        break;
      }
    }
    if (pivot == -1) {
      continue;
    }
    swap(D[last], D[pivot]);
    swap(v[last], v[pivot]);
    for (int i = last + 1; i < D.size(); ++i) {
      uint8_t t = Get(i, col) * Inv(Get(last, col)) % 3;
      array<Bs, 3> nxt{};
      for (int x = 0; x < 3; ++x) {
        for (int y = 0; y < 3; ++y) {
          int z = (x + 3 - t * y % 3) % 3;
          nxt[z] |= D[i][x] & D[last][y];
        }
      }
      D[i] = nxt;
      v[i] += 3 - t * v[last] % 3;
      v[i] %= 3;
    }
    last++;
  }
  for (int i = last; i < D.size(); ++i) {
    if (v[i] > 0) {
      cout << "-1\n";
      return;
    }
  }
  vector<int> x(M);
  vector<bool> used(M);
  vector<int> which(M, -1);
  for (int i = last - 1; i >= 0; --i) {
    int j = 0;
    while (j < M && Get(i, j) == 0) j++;
    assert(j < M);
    assert(!used[j]);
    used[j] = true;
    which[i] = j;
    int s = 0;
    for (int k = j + 1; k < M; ++k) {
      s += x[k] * Get(i, k);
    }
    x[j] = (v[i] + 3 - s % 3) * Inv(Get(i, j)) % 3;
  }
  for (int i = 0; i < M; ++i) {
    cout << x[i] + 1 << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    Solve();
  }
  return 0;
}