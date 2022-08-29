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

// GCC __gcd(long long A, long long B)

ll gcd(ll a, ll b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

int X[SIZE], Y[SIZE], U[SIZE], V[SIZE];
pair<int, int> v[SIZE];

pair<int, int> normalize(int x, int y) {
  int g = gcd(abs(x), abs(y));

  x /= g;
  y /= g;
  return {x, y};
}

void solve() {
  int N;

  scanf("%d", &N);

  map<pair<int, int>, int> counter;
  ll ans = 0;

  for (int i = 0; i < N; i++) {
    scanf("%d%d%d%d", X + i, Y + i, U + i, V + i);
    v[i] = normalize(U[i] - X[i], V[i] - Y[i]);
    ans += counter[{-v[i].first, -v[i].second}];
    counter[v[i]]++;
    debug(v[i]);
  }

  printf("%lld\n", ans);
}


int main() {
  int T;

  scanf("%d", &T);

  while (T--) solve();

  return 0;
}