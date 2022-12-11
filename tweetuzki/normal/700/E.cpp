#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int MaxN = 200000, MaxV = 400000;

int N;
int A[MaxN + 5];
int F[MaxV + 5];

namespace ST {

int cnt;
int rt[MaxV + 5];
int lson[MaxV * 40], rson[MaxV * 40], sum[MaxV * 40];

void insertTree(int pos, int &i, int l, int r) {
  if (i == 0) i = ++cnt;
  if (l == r) {
    sum[i] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid) insertTree(pos, lson[i], l, mid);
  else insertTree(pos, rson[i], mid + 1, r);
  sum[i] = sum[lson[i]] + sum[rson[i]];
}

int mergeTree(int x, int y, int l, int r) {
  if (x == 0 || y == 0) return x + y;
  int i = ++cnt;
  sum[i] = sum[x] + sum[y];
  if (l == r) return i;
  int mid = (l + r) >> 1;
  lson[i] = mergeTree(lson[x], lson[y], l, mid);
  rson[i] = mergeTree(rson[x], rson[y], mid + 1, r);
  return i;
}

int binaryTree(int x, int i, int l, int r) {
  if (sum[i] == 0) return 0;
  if (l == r) return l;
  int mid = (l + r) >> 1;
  if (x <= mid) return binaryTree(x, lson[i], l, mid);
  else {
    int res = binaryTree(x, rson[i], mid + 1, r);
    if (res != 0) return res;
    else return binaryTree(x, lson[i], l, mid);
  }
}

}

namespace SAM {

int cnt, last;
int ch[MaxV + 5][26], link[MaxV + 5], len[MaxV + 5];
int at[MaxV + 5];
std::vector<int> gr[MaxV + 5];

void init() {
  link[0] = -1;
}

void expand(int c, int id) {
  int p = last, cur = ++cnt;
  len[cur] = len[p] + 1;
  at[cur] = id;
  last = cur;
  while (p != -1 && ch[p][c] == 0) {
    ch[p][c] = cur;
    p = link[p];
  }
  if (p == -1) return;
  int q = ch[p][c];
  if (len[p] + 1 == len[q]) {
    link[cur] = q;
    return;
  }
  int clone = ++cnt;
  len[clone] = len[p] + 1;
  memcpy(ch[clone], ch[q], sizeof ch[q]);
  link[clone] = link[q];
  at[clone] = at[q];
  link[cur] = link[q] = clone;
  while (p != -1 && ch[p][c] == q) {
    ch[p][c] = clone;
    p = link[p];
  }
}

void build_tree() {
  for (int i = 1; i <= cnt; ++i)
    gr[link[i]].push_back(i);
}

void get_right(int u) {
  if (at[u] != 0) ST::insertTree(at[u], ST::rt[u], 1, N);
  else ST::rt[u] = ++ST::cnt;
  for (int i = 0; i < (int) gr[u].size(); ++i) {
    int v = gr[u][i];
    get_right(v);
    ST::rt[u] = ST::mergeTree(ST::rt[u], ST::rt[v], 1, N);
  }
}

int anc[MaxV + 5];

void dfs(int u) {
  for (int i = 0; i < (int) gr[u].size(); ++i) {
    int v = gr[u][i];
    F[v] = F[u];
    int p = anc[u];
    int bg = ST::binaryTree(at[v] - 1, ST::rt[p], 1, N);
    if (bg >= at[v] - len[v] + len[p]) F[v] = F[p] + 1;
//    printf("v = %d, p = %d, f = %d\n", v, p, F[v]);
    if (F[u] == F[v]) anc[v] = anc[u];
    else anc[v] = v;
    dfs(v);
  }
}

}

void init() {
  scanf("%d", &N);
  static char s[MaxN + 5];
  scanf("%s", s + 1);
  for (int i = 1; i <= N; ++i) A[i] = s[i] - 'a';
}

void solve() {
  SAM::init();
  for (int i = 1; i <= N; ++i) SAM::expand(A[i], i);
//  for (int i = 1; i <= SAM::cnt; ++i) printf("link[%d] = %d\n", i, SAM::link[i]);
  SAM::build_tree();
  SAM::get_right(0);
  SAM::dfs(0);
  int ans = 0;
  for (int i = 0; i <= SAM::cnt; ++i) ans = std::max(ans, F[i]);
  printf("%d\n", ans);
}

int main() {
  init();
  solve();
  return 0;
}