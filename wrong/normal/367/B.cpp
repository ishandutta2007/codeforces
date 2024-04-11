#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int N, M, P, A[200050], B[200050];
int X[400050], BD[400050], AD[400050];

int main()
{
  scanf("%d%d%d", &N, &M, &P);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < M; ++i) {
    scanf("%d", &B[i]);
  }

  for (int i = 0; i < N; ++i) X[i] = A[i];
  for (int i = 0; i < M; ++i) X[N + i] = B[i];
  sort(X, X + N + M);
  int K = unique(X, X + N + M) - X;

  for (int i = 0; i < N; ++i) {
    A[i] = lower_bound(X, X + K, A[i]) - X;
    while (A[i] < 0) ;
  }
  for (int i = 0; i < M; ++i) {
    B[i] = lower_bound(X, X + K, B[i]) - X;
    while (B[i] < 0) ;
  }

  for (int i = 0; i < M; ++i) {
    ++BD[B[i]];
  }

  vector<int> sol;
  for (int i = 0; i < P && i < N; ++i) {
    int match = 0;
    if (i + (Int)(M - 1) * P >= N) break;
    for (int j = 0; j < M; ++j) {
      int v = A[i + j * P];
      if (AD[v] == BD[v]) match -= BD[v];
      ++AD[v];
      if (AD[v] == BD[v]) match += BD[v];
    }
    if (match == M) sol.push_back(i);
    for (int j = M; i + (Int)j * P < N; ++j) {
      int v = A[i + (j - M) * P];
      if (AD[v] == BD[v]) match -= BD[v];
      --AD[v];
      if (AD[v] == BD[v]) match += BD[v];
      int w = A[i + j * P];
      if (AD[w] == BD[w]) match -= BD[w];
      ++AD[w];
      if (AD[w] == BD[w]) match += BD[w];
      if (match == M) sol.push_back(i + (j - M + 1) * P);
    }
    for (int j = 0; i + (Int)j * P < N; ++j) {
      AD[A[i + j * P]] = 0;
    }
  }

  sort(sol.begin(), sol.end());
  printf("%d\n", (int)sol.size());
  for (int i = 0; i < (int)sol.size(); ++i) {
    printf("%d%c", sol[i] + 1, i == (int)sol.size() - 1 ? '\n' : ' ');
  }

  return 0;
}