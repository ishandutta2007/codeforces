#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <bitset>
#include <complex>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <cassert>
#include <functional>

using ll = long long;
using namespace std;

template<typename A, typename B>
bool chmin(A &a, const B b) {
  if (a <= b) return false;
  a = b;
  return true;
}

template<typename A, typename B>
bool chmax(A &a, const B b) {
  if (a >= b) return false;
  a = b;
  return true;
}

#ifndef LOCAL
#define debug(...) ;
#else
#define debug(...) cerr << __LINE__ << " : " << #__VA_ARGS__ << " = " << _tostr(__VA_ARGS__) << endl;

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v);

template<typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}

void _tostr_rec(ostringstream &oss) {
  oss << "\b\b \b";
}

template<typename Head, typename... Tail>
void _tostr_rec(ostringstream &oss, Head &&head, Tail &&...tail) {
  oss << head << ", ";
  _tostr_rec(oss, forward<Tail>(tail)...);
}

template<typename... T>
string _tostr(T &&...args) {
  ostringstream oss;
  int size = sizeof...(args);
  if (size > 1) oss << "{";
  _tostr_rec(oss, forward<T>(args)...);
  if (size > 1) oss << "}";
  return oss.str();
}
#endif

constexpr int mod = 1'000'000'007; //1e9+7(prime number)
constexpr int INF = 1'000'000'000; //1e9
constexpr ll LLINF = 2'000'000'000'000'000'000LL; //2e18
constexpr int SIZE = 200010;

/* Coordinate Compression */

template<typename T>
map<T, int> compress(vector<T> &vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());

  map<T, int> dict;
  for (int i = 0; i < (int)vec.size(); i++) {
    dict[vec[i]] = i;
  }
  return dict;
}

constexpr int SQRT = 400;

int solve() {
  int N;

  scanf("%d", &N);

  vector<vector<int>> A(N);
  vector<int> as;

  for (int i = 0; i < N; i++) {
    int k, v;
    scanf("%d", &k);

    for (int j = 0; j < k; j++) {
      scanf("%d", &v);
      A[i].push_back(v);
      as.push_back(v);
    }
  }

  auto dictA = compress(as);

  vector<vector<int>> rA(dictA.size());

  for (int i = 0; i < N; i++) {
    for (auto &v : A[i]) {
      v = dictA[v];

      if (A[i].size() < SQRT)
        rA[v].push_back(i);
    }
  }

  vector<int> memo(dictA.size(), -1);

  for (int i = 0; i < N; i++) {
    if (A[i].size() < SQRT) continue;

    for (int x : A[i]) {
      memo[x] = i;
    }

    for (int j = 0; j < N; j++) {
      if (j == i) continue;

      int c = 0;
      for (int x : A[j]) c += memo[x] == i;
      if (c >= 2) {
        printf("%d %d\n", i + 1, j + 1);
        return 0;
      }
    }
  }

  vector<pair<int, int>> memo2(dictA.size(), {-1, -1});

  for (int i = 0; i < dictA.size(); i++) {
    for (int j : rA[i]) {
      for (int x : A[j]) {
        if (x == i) continue;

        if (memo2[x].first == i) {
          printf("%d %d\n", memo2[x].second + 1, j + 1);
          return 0;
        }
        memo2[x] = {i, j};
      }
    }
  }

  puts("-1");

  return 0;
}

int main() {
  int T;
  scanf("%d", &T);

  while (T--) solve();
}