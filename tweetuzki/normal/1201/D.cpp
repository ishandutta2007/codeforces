#include <bits/stdc++.h>
using namespace std;

typedef long long llt;
typedef pair<int, llt> pil;
typedef pair<llt, int> pli;

const int MaxN = 200000 + 5, MaxM = 200000 + 5;
const int MaxK = 200000 + 5, MaxQ = 200000 + 5;
const int MaxV = 800000 + 5;
const llt INF = 0x3F3F3F3F3F3F3F3F;

int N, M, K, Q;
int R[MaxK], C[MaxK];
int B[MaxQ];
llt Dis[MaxV];
bool Vis[MaxV];
priority_queue< pli, vector<pli>, greater<pli> > pq;
vector<int> Vec[MaxN];
vector<pil> G[MaxV];

void init() {
  scanf("%d %d %d %d", &N, &M, &K, &Q);
  for (int i = 1; i <= K; ++i)
    scanf("%d %d", &R[i], &C[i]);
  for (int i = 1; i <= Q; ++i)
    scanf("%d", &B[i]);
  sort(B + 1, B + 1 + Q);
}

void dijkstra(int s) {
  memset(Dis, 0x3F, sizeof Dis);
  Dis[s] = 0;
  pq.push(make_pair(Dis[s], s));
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    if (Vis[u] == true) continue;
    Vis[u] = true;
//    printf("Dis[%d] = %lld\n", u, Dis[u]);
    for (auto e : G[u]) {
      int v = e.first; llt w = e.second;
      if (Dis[u] + w < Dis[v]) {
        Dis[v] = Dis[u] + w;
        pq.push(make_pair(Dis[v], v));
      }
    }
  }
}

inline int getPre(int r, int pos) {
  return lower_bound(Vec[r].begin(), Vec[r].end(), pos, [](int x, int y){ return C[x] < C[y]; }) - Vec[r].begin() - 1;
}

inline int getNxt(int r, int pos) {
  return getPre(r, pos) + 1;
}

void solve() {
  for (int i = 1; i <= K; ++i)
    Vec[R[i]].push_back(i);
  for (int i = 1; i <= N; ++i)
    sort(Vec[i].begin(), Vec[i].end(), [](int x, int y){ return C[x] < C[y]; });
  llt ans = INF;
  for (int r = 1, nextRow = -1; r <= N; ++r) {
    if (Vec[r].empty()) continue;
    if (nextRow == -1) {
      if (r == 1) {
        G[0].push_back(make_pair(Vec[r][0], 0));
      } else {
        C[K + 1] = B[1];
        int p = getPre(r, K + 1), n = getNxt(r, K + 1);
        if (p >= 0) G[0].push_back(make_pair(Vec[r][p], B[1] - C[Vec[r][p]]));
        if (n < (int) Vec[r].size()) G[0].push_back(make_pair(Vec[r][n], 0));
      }
    }
    for (int i = 0; i < (int) Vec[r].size(); ++i) {
      int u = Vec[r][i];
      G[u].push_back(make_pair(u + K, C[u] - C[Vec[r][0]]));
      G[u + 2 * K].push_back(make_pair(u + 3 * K, C[u] - C[Vec[r][0]]));
      G[u].push_back(make_pair(u + 2 * K, C[Vec[r][Vec[r].size() - 1]] - C[u]));
      G[u + K].push_back(make_pair(u + 3 * K, C[Vec[r][Vec[r].size() - 1]] - C[u]));
      if (i != 0) {
        G[Vec[r][i - 1] + K].push_back(make_pair(u + K, 0));
        G[Vec[r][i - 1] + 3 * K].push_back(make_pair(u + 3 * K, 0));
      }
      if (i != (int) Vec[r].size() - 1) {
        G[Vec[r][i + 1] + 2 * K].push_back(make_pair(u + 2 * K, C[Vec[r][i + 1]] - C[u]));
        G[Vec[r][i + 1] + 3 * K].push_back(make_pair(u + 3 * K, C[Vec[r][i + 1]] - C[u]));
      }
    }
    nextRow = max(nextRow, r + 1);
    while (nextRow <= N && Vec[nextRow].empty()) nextRow++;
//    printf("r = %d, nextRow = %d\n", r, nextRow);
    if (nextRow > N) {
      dijkstra(0);
      for (auto u : Vec[r]) {
        ans = min(ans, r - 1 + Dis[u + 3 * K] + Dis[u + 3 * K] + C[u] - 1);
      }
      break;
    }
    for (int i = 0; i < (int) Vec[r].size(); ++i) {
      int u = Vec[r][i];
      int prefixC = lower_bound(B + 1, B + 1 + Q, C[u]) - B - 1, suffixC = prefixC + 1;
//      printf("u = %d, preC = %d, sufC = %d\n", u, prefixC, suffixC);
      if (prefixC >= 1) {
        C[K + 1] = B[prefixC];
        int p = getPre(nextRow, K + 1), n = getNxt(nextRow, K + 1);
//        printf("p = %d, n = %d\n", p, n);
        int c = C[u] - B[prefixC];
        if (p >= 0) G[u + 3 * K].push_back(make_pair(Vec[nextRow][p], c + B[prefixC] - C[Vec[nextRow][p]]));
        if (n < (int) Vec[nextRow].size()) G[u + 3 * K].push_back(make_pair(Vec[nextRow][n], c));
      }
      if (suffixC <= Q) {
        C[K + 1] = B[suffixC];
        int p = getPre(nextRow, K + 1), n = getNxt(nextRow, K + 1);
//        printf("p = %d, n = %d\n", p, n);
        if (p >= 0) G[u + 3 * K].push_back(make_pair(Vec[nextRow][p], B[suffixC] - C[Vec[nextRow][p]]));
        if (n < (int) Vec[nextRow].size()) G[u + 3 * K].push_back(make_pair(Vec[nextRow][n], 0));
      }
    }
  }
  cout << ans << endl;
}

int main() {
  init();
  solve();
  return 0;
}