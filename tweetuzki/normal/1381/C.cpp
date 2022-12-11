#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

const int MaxN = 100000;

int N, X, Y, NoUse;
int A[MaxN + 5], B[MaxN + 5];
int Buc[MaxN + 5];
std::vector<int> Vec[MaxN + 5];

std::priority_queue< std::pair<int, int> > Pq;

void init() {
  scanf("%d %d %d", &N, &X, &Y);
  for (int i = 1; i <= N; ++i) scanf("%d", &B[i]);
}

void solve() {
  NoUse = 0;

  for (int i = 1; i <= N; ++i) {
    int x = B[i];
    Buc[x]++;
    Vec[x].push_back(i);
  }
  for (int i = 1; i <= N + 1; ++i)
    if (Buc[i] == 0) NoUse = i;

  for (int i = 1; i <= N + 1; ++i)
    Pq.push(std::make_pair(Buc[i], i));
  for (int i = 1; i <= X; ++i) {
    auto p = Pq.top();
    // printf("p = (%d, %d)\n", p.first, p.second);
    Pq.pop();
    Buc[p.second]--;
    int pos = Vec[p.second].back();
    A[pos] = B[pos];
    Vec[p.second].pop_back();
    Pq.push(std::make_pair(Buc[p.second], p.second));
  }

  Y -= X;
  int e = Pq.top().first;

  std::vector<int> posvec;
  std::vector< std::pair<int, int> > vec;
  posvec.clear();
  vec.clear();
  for (int i = 1; i <= N + 1; ++i) {
    while (Vec[i].empty() == false) {
      vec.push_back(std::make_pair(i, Vec[i].back()));
      Vec[i].pop_back();
    }
  }
  B[N + 1] = NoUse;
  for (int i = 1; i <= N - (X + Y); ++i) vec.push_back(std::make_pair(NoUse, N + 1));
  std::sort(vec.begin(), vec.end());
  for (auto p : vec) posvec.push_back(p.second);
  e = std::max(e, N - (X + Y));
  std::rotate(vec.begin(), vec.begin() + e, vec.end());

  // printf("e = %d\n", e);
  // for (int i = 0; i < (int) vec.size(); ++i)
  //   printf("posvec = %d, vec = %d\n", posvec[i], vec[i].second);

  bool ok = true;
  for (int i = 0; i < (int) vec.size(); ++i) {
    // printf("A[%d] = %d\n", posvec[i], vec[i].second);
    A[posvec[i]] = B[vec[i].second];
    if (A[posvec[i]] == B[posvec[i]]) ok = false;
  }
  if (ok == false) {
    puts("NO");
    return;
  }

  puts("YES");
  for (int i = 1; i <= N; ++i)
    printf("%d%c", A[i], " \n"[i == N]);
}

void clear() {
  for (int i = 1; i <= N; ++i) A[i] = 0;
  for (int i = 1; i <= N + 1; ++i) {
    Buc[i] = 0;
    Vec[i].clear();
  }
  while (!Pq.empty()) Pq.pop();
}

int main() {
  int Te;
  scanf("%d", &Te);
  for (int t = 1; t <= Te; ++t) {
    init();
    solve();
    clear();
  }
  return 0;
}