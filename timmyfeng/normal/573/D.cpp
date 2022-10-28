#include <bits/stdc++.h>
using namespace std;

const int N = 30000;

vector<array<int, 2>> prv[8 + 1][1 << 8];
bool valid[8 + 1][1 << 8];

long long strength[4 * N][1 << 8];
int length[4 * N];

array<int, 2> horse[N], warrior[N];
int node[N], where[N], n;

void pull(int u) {
  fill(strength[u], strength[u] + (1 << 8), 0);
  for (int i = 0; i < (1 << 8); ++i) {
    for (auto [l, r] : prv[length[u]][i]) {
      if (min(strength[2 * u][l], strength[2 * u + 1][r]) > 0) {
        strength[u][i] = max(strength[u][i], strength[2 * u][l] + strength[2 * u + 1][r]);
      }
    }
  }
}

void update(int u, int v) {
  fill(strength[u], strength[u] + (1 << 8), 0);
  for (int i = -2; i <= 2; ++i) {
    if (v + i >= 0 && v + i < n && warrior[v][1] != horse[v + i][1]) {
      strength[u][1 << (i + 2)] = (long long) warrior[v][0] * horse[v + i][0];
    }
  }
}

void build(int u, int l, int r) {
  if (l == r) {
    length[u] = 1;
    update(u, l);
    node[l] = u;
  } else {
    int m = (l + r) / 2;
    build(2 * u, l, m);
    build(2 * u + 1, m + 1, r);
    length[u] = min(8, length[2 * u] + length[2 * u + 1]);
    pull(u);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = -2; i <= 2; ++i) {
    valid[1][1 << (i + 2)] = true;
  }

  for (int i = 2; i <= 8; ++i) {
    int l = (i + 1) / 2, r = i / 2;
    for (int j = 0; j < (1 << (l + 4)); ++j) {
      for (int k = 0; k < (1 << (r + 4)); ++k) {
        int mask = j | (k << l);
        if (valid[l][j] && valid[r][k] && __builtin_popcount(mask) == i) {
          if (i > 4) {
            mask = (mask & 15) | (mask >> i << 4);
            if (__builtin_popcount(mask) > 4) {
              continue;
            }
          }
          prv[i][mask].push_back({j, k});
          valid[i][mask] = true;
        }
      }
    }
  }

  int q;
  cin >> n >> q;

  for (int i = 0; i < n; ++i) {
    cin >> warrior[i][0];
    warrior[i][1] = i;
  }

  for (int i = 0; i < n; ++i) {
    cin >> horse[i][0];
    horse[i][1] = i;
  }

  sort(warrior, warrior + n);
  sort(horse, horse + n);

  for (int i = 0; i < n; ++i) {
    where[horse[i][1]] = i;
  }

  build(1, 0, n - 1);

  while (q--) {
    int a, b;
    cin >> a >> b;

    swap(where[--a], where[--b]);
    a = where[a], b = where[b];
    swap(horse[a][1], horse[b][1]);

    set<int> que;
    for (auto c : {a, b}) {
      for (int i = max(0, c - 2); i <= min(n - 1, c + 2); ++i) {
        que.insert(node[i] / 2);
        update(node[i], i);
      }
    }

    while (true) {
      int u = *--que.end();
      que.erase(--que.end());
      if (u == 0) {
        break;
      }
      que.insert(u / 2);
      pull(u);
    }

    cout << *max_element(strength[1], strength[1] + (1 << 8)) << "\n";
  }
}