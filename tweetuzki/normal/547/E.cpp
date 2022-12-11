#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int MaxN = 200000, MaxV = 200000;
const int MaxQ = 500000;
const int Alpha = 26;

int N, Q, V;
int Ch[MaxV + 5][Alpha], Fail[MaxV + 5];
int End[MaxN + 5];
int Siz[MaxV + 5], Wson[MaxV + 5];
int L[MaxQ + 5], R[MaxQ + 5];
long long Ans[MaxQ + 5];
std::vector<int> Col[MaxV + 5];
std::vector<int> Tr[MaxV + 5];
std::vector<int> Que[MaxQ + 5];

struct FenwickTree {
  int t[MaxN + 5];
  inline int lowbit(int i) { return i & -i; }
  inline void update(int x, int v) { for (int i = x; i <= N; i += lowbit(i)) t[i] += v; return; }
  inline long long query(int x) { long long res = 0; for (int i = x; i > 0; i -= lowbit(i)) res += t[i]; return res; }
  inline long long qrange(int l, int r) { return query(r) - query(l - 1); }
};
FenwickTree T;

inline void insert(char *s, int id) {
  int u = 0;
  for (int i = 0; s[i]; ++i) {
    int c = s[i] - 'a';
    if (Ch[u][c] == 0) Ch[u][c] = ++V;
    u = Ch[u][c];
    Col[u].push_back(id);
  }
  End[id] = u;
}

void init() {
  scanf("%d %d", &N, &Q);
  for (int i = 1; i <= N; ++i) {
    static char s[MaxV + 5];
    scanf("%s", s);
    insert(s, i);
  }
  for (int i = 1; i <= Q; ++i) {
    int k;
    scanf("%d %d %d", &L[i], &R[i], &k);
    Que[End[k]].push_back(i);
  }
}

void getFail() {
  static int que[MaxV + 5];
  int head = 1, tail = 0;
  for (int i = 0; i < Alpha; ++i)
    if (Ch[0][i] != 0) {
      que[++tail] = Ch[0][i];
      Tr[0].push_back(Ch[0][i]);
    }
  while (head <= tail) {
    int u = que[head++];
    for (int c = 0; c < Alpha; ++c) {
      if (Ch[u][c] == 0) Ch[u][c] = Ch[Fail[u]][c];
      else {
        Fail[Ch[u][c]] = Ch[Fail[u]][c];
        Tr[Fail[Ch[u][c]]].push_back(Ch[u][c]);
        que[++tail] = Ch[u][c];
      }
    }
  }
}

void dfs1(int u) {
  Siz[u] = (int) Col[u].size();
  for (int i = 0; i < (int) Tr[u].size(); ++i) {
    int v = Tr[u][i];
    dfs1(v);
    Siz[u] += Siz[v];
    if (Siz[v] > Siz[Wson[u]]) Wson[u] = v;
  }
}

inline void ins(int u) {
  for (int i = 0; i < (int) Col[u].size(); ++i)
    T.update(Col[u][i], 1);
}

inline void del(int u) {
  for (int i = 0; i < (int) Col[u].size(); ++i)
    T.update(Col[u][i], -1);
}

void dfs3(int u) {
  ins(u);
  for (int i = 0; i < (int) Tr[u].size(); ++i) dfs3(Tr[u][i]);
}

void dfs4(int u) {
  del(u);
  for (int i = 0; i < (int) Tr[u].size(); ++i) dfs4(Tr[u][i]);
}

void dfs2(int u) {
  for (int i = 0; i < (int) Tr[u].size(); ++i) {
    int v = Tr[u][i];
    if (v == Wson[u]) continue;
    dfs2(v);
    dfs4(v);
  }
  if (Wson[u] != 0) dfs2(Wson[u]);
  ins(u);
  for (int i = 0; i < (int) Tr[u].size(); ++i) {
    int v = Tr[u][i];
    if (v == Wson[u]) continue;
    dfs3(v);
  }
  for (int i = 0; i < (int) Que[u].size(); ++i) {
    int id = Que[u][i];
    Ans[id] = T.qrange(L[id], R[id]);
  }
}

void solve() {
  getFail();
  dfs1(0);
  dfs2(0);
  for (int i = 1; i <= Q; ++i) printf("%lld\n", Ans[i]);
}

int main() {
  init();
  solve();
  return 0;
}