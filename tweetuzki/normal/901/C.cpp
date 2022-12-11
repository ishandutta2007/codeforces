#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 300000 + 5, MaxM = 300000 + 5, MaxQ = 300000 + 5;

struct data {
  int l, r;

  data(int _l = 0, int _r = 0) {
    l = std::min(_l, _r);
    r = std::max(_l, _r);
  }

  inline friend bool operator < (const data &a, const data &b) {
    if (a.l != b.l) return a.l < b.l;
    else return a.r < b.r;
  }
};

struct Graph {
  int cnte;
  int Head[MaxN], To[MaxM * 2], Next[MaxM * 2];

  inline void addEdge(int from, int to) {
    cnte++; To[cnte] = to;
    Next[cnte] = Head[from]; Head[from] = cnte;
  }
};

int N, M, Q, S;
int Low[MaxN], Dfn[MaxN], Dfc;
int Stk[MaxN], Tp;
int Mn[MaxN], Mx[MaxN];
int MaxR[MaxN];
long long Pre[MaxN];
data Range[MaxN]; int CntR;
Graph G;

void init() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= M; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    G.addEdge(u, v);
    G.addEdge(v, u);
  }
  scanf("%d", &Q);
}

void tarjan(int u, int f) {
  Low[u] = Dfn[u] = ++Dfc;
  Stk[++Tp] = u;
  for (int i = G.Head[u]; i; i = G.Next[i]) {
    int v = G.To[i];
    if (v == f) continue;
    if (Dfn[v] == 0) {
      tarjan(v, u);
      Low[u] = std::min(Low[u], Low[v]);
    } else Low[u] = std::min(Low[u], Dfn[v]);
  }
  if (Low[u] == Dfn[u]) {
    S++;
    Mx[S] = Mn[S] = u;
    while (Tp > 0) {
      int v = Stk[Tp--];
      Mx[S] = std::max(Mx[S], v);
      Mn[S] = std::min(Mn[S], v);
      if (v == u) break;
    }
  }
}

void solve() {
  for (int i = 1; i <= N; ++i)
    if (Dfn[i] == 0) tarjan(i, 0);
  for (int i = 1; i <= S; ++i) {
    if (Mx[i] == Mn[i]) continue;
    Range[++CntR] = data(Mn[i], Mx[i]);
  }

  std::sort(Range + 1, Range + 1 + CntR);
  int mR = N + 1;
  for (int i = N, j = CntR + 1; i >= 1; --i) {
    while (j - 1 >= 1 && Range[j - 1].l >= i) {
      j--;
      mR = std::min(mR, Range[j].r);
    }
    MaxR[i] = mR;
  }
  for (int i = 1; i <= N; ++i) Pre[i] = Pre[i - 1] + MaxR[i];
//  for (int i = 1; i <= N; ++i) printf("MaxR[%d] = %d\n", i, MaxR[i]);
  for (int i = 1; i <= Q; ++i) {
    int l, r;
    long long ans = 0;
    scanf("%d %d", &l, &r);
    int pos = std::lower_bound(MaxR + 1, MaxR + 1 + N, r + 1) - MaxR;
//    printf("l = %d, r = %d, pos = %d\n", l, r, pos);
    if (pos < l) {
      ans = 1LL * (r + 1) * (r - l + 1);
    } else if (pos > r) {
      ans = Pre[r] - Pre[l - 1];
    } else {
      ans = Pre[pos - 1] - Pre[l - 1] + 1LL * (r + 1) * (r - pos + 1);
    }
    ans -= 1LL * (l + r) * (r - l + 1) / 2;
    printf("%lld\n", ans);
  }
}

int main() {
  init();
  solve();
  return 0;
}