#include <bits/stdc++.h>
 
template <int N, int C> struct AhoCorasick {
  AhoCorasick() : n(1) {
    memset(weight, 0, sizeof(weight));
    memset(go, -1, sizeof(go));
  }
 
  void insert(const char *s, int w = 1) {
    int p = 0;
    for (int i = 0; s[i]; ++i) {
      int c = s[i] - 'a';
      if (go[p][c] == -1) {
        go[p][c] = n++;
      }
      p = go[p][c];
    }
    weight[p] += w;
  }
 
  void initialize() {
    std::queue<int> queue;
    for (int c = 0; c < C; ++c) {
      int &v = go[0][c];
      if (~v) {
        queue.push(v);
      }
      (~v ? fail[v] : v) = 0;
    }
    while (!queue.empty()) {
      int u = queue.front();
      queue.pop();
      weight[u] += weight[fail[u]];
      for (int c = 0; c < C; ++c) {
        int &v = go[u][c];
        if (~v) {
          queue.push(v);
        }
        (~v ? fail[v] : v) = go[fail[u]][c];
      }
    }
  }
 
  int n, weight[N], go[N][C], fail[N];
};
 
void update(int64_t &x, int64_t a) { x = std::max(x, a); }
 
const int N = 1001;
const int M = 14;
const int C = 14;
const int64_t MIN = std::numeric_limits<int64_t>::min() / 2;
 
char s[400001];
AhoCorasick<N, C> ac;
int tgo[C][N], dest[N];
int64_t util[N], dp[1 << M][N];
 
int main() {
  int n,nn=0;
  scanf("%d", &n);
  while (n--) {
    int w;
    scanf("%s%d", s, &w);
    ac.insert(s, w);
    nn=std::max(nn,(int)strlen(s));
  }
  ac.initialize();
  n = ac.n;
  for (int i = 0; i < n; ++i) {
    for (int c = 0; c < C; ++c) {
      tgo[c][i] = ac.go[i][c];
    }
  }
  scanf("%s", s);
  for (int i = 0; i < n; ++i) {
    dest[i] = i, util[i] = 0;
  }
  for (int mask = 0; mask < 1 << M; ++mask) {
    for (int i = 0; i < n; ++i) {
      dp[mask][i] = MIN;
    }
  }
  dp[0][0] = 0;
  int m = 0, steps = 0, sole_dest = 0;
  int64_t sole_util = 0;
  auto get_dest = [&](int j) { return steps <= nn ? dest[j] : sole_dest; };
  auto get_util = [&](int j) {
    return steps <= nn ? util[j] : util[j] + sole_util;
  };
  for (int _ = 0; s[_]; ++_) {
    if (s[_] == '?') {
      for (int mask = 0; mask < 1 << M; ++mask) {
        if (__builtin_popcount(mask) == m) {
          for (int j = 0; j < n; ++j) {
            if (dp[mask][j] != MIN) {
              for (int i = 0; i < M; ++i) {
                if (~mask >> i & 1) {
                  int v = ac.go[get_dest(j)][i];
                  update(dp[mask | 1 << i][v],
                         dp[mask][j] + get_util(j) + ac.weight[v]);
                }
              }
            }
          }
        }
      }
      steps = 0;
      for (int i = 0; i < n; ++i) {
        dest[i] = i, util[i] = 0;
      }
      m++;
    } else {
      int c = s[_] - 'a';
      ++steps;
      if (steps <= nn) {
        for (int i = 0; i < n; ++i) {
          util[i] += ac.weight[dest[i] = tgo[c][dest[i]]];
        }
      } else {
        if (steps == nn + 1) {
          sole_dest = dest[0], sole_util = 0;
        }
        sole_util += ac.weight[sole_dest = tgo[c][sole_dest]];
      }
    }
  }
  int64_t result = MIN;
  for (int mask = 0; mask < 1 << M; ++mask) {
    if (__builtin_popcount(mask) == m) {
      for (int j = 0; j < n; ++j) {
        update(result, dp[mask][j] + get_util(j));
      }
    }
  }
  std::cout << result << std::endl;
}