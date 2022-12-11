#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <queue>
#include <utility>

const int MaxN = 100000, MaxM = 100000;

struct frac {
  long long a, b;
  frac(long long _a = 0LL, long long _b = 1LL) { a = _a, b = _b; }
  inline friend bool operator<(const frac &x, const frac &y) { return 1.0 * x.a * y.b < 1.0 * x.b * y.a; }
};

int N, M, K, V;
long long A[MaxN + 5];
int Ans[MaxM + 5];
bool IsAssign[MaxM + 5];
int Bel[MaxM + 5];
std::pair<int, int> MaxAssign[MaxN + 5];
std::vector< std::pair<int, int> > Vec[MaxN + 5];
std::pair<int, int> Mul[MaxM + 5];
std::priority_queue< std::pair<frac, int> > Pq;

void init() {
  scanf("%d %d %d", &N, &M, &K);
  for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]);
  for (int i = 1; i <= M; ++i) {
    int opt, x, y;
    scanf("%d %d %d", &opt, &x, &y);
    Bel[i] = x;
    if (opt == 1) {
      MaxAssign[x] = std::max(MaxAssign[x], std::make_pair(y, i));
      IsAssign[i] = true;
    }
    else if (opt == 2) Vec[x].push_back(std::make_pair(y, i));
    else if (y != 1) Mul[++V] = std::make_pair(y, i);
  }
  for (int i = 1; i <= N; ++i)
    if (MaxAssign[i].first > A[i]) Vec[i].push_back(std::make_pair(MaxAssign[i].first - A[i], MaxAssign[i].second));
}

void solve() {
  for (int i = 1; i <= N; ++i) std::sort(Vec[i].begin(), Vec[i].end());
  std::sort(Mul + 1, Mul + 1 + V);
  long long s = 0;
  for (int i = 1; i <= N; ++i) s += A[i];
  for (int i = 1; i <= N; ++i) {
    if (Vec[i].empty()) continue;
    std::pair<int, int> ed = *(Vec[i].end() - 1);
    Pq.push(std::make_pair(frac(A[i] + ed.first, A[i]), i));
  }
  int cnt = 0;
  while (!Pq.empty()) {
    if (cnt >= K) break;
    int x = Pq.top().second, y = (Vec[x].end() - 1)->first;
    frac k = Pq.top().first;
    Pq.pop();
    if (cnt + V >= K) {
      int cmpId = cnt + V - K + 1;
      if (k < frac(1LL * Mul[cmpId].first)) break;
    }
    Ans[++cnt] = (Vec[x].end() - 1)->second;
    A[x] += y;
    Vec[x].pop_back();
    if (!Vec[x].empty()) {
      std::pair<int, int> ed = *(Vec[x].end() - 1);
      Pq.push(std::make_pair(frac(A[x] + ed.first, A[x]), x));
    }
  }
  while (cnt < K && V > 0) {
    cnt++;
    Ans[cnt] = Mul[V].second;
    V--;
  }
  static int firId[MaxN + 5];
  for (int i = 1; i <= cnt; ++i) {
    int x = Ans[i];
    if (firId[Bel[x]] == 0) firId[Bel[x]] = i;
    if (IsAssign[x] == true && firId[Bel[x]] != i)
      std::swap(Ans[firId[Bel[x]]], Ans[i]);
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; ++i)
    printf("%d%c", Ans[i], " \n"[i == K]);
}

int main() {
  init();
  solve();
  return 0;
}