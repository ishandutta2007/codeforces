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

using Real = long double;

constexpr int mod = 1'000'000'007; //1e9+7(prime number)
constexpr int INF = 1'000'000'000; //1e9
constexpr ll LLINF = 2'000'000'000'000'000'000LL; //2e18
constexpr int SIZE = 200010;

using P_type = long long; //(integer or real)
using G_real = long double; //(float or double or long double)
using P = complex<P_type>;
constexpr G_real P_eps = 1e-8; //

namespace std {
  template<class T>
  bool operator<(const complex<T> &a, const complex<T> &b) {
    return abs(a.real() - b.real()) < P_eps ? a.imag() + P_eps < b.imag() : a.real() + P_eps < b.real();
  }
};

P rotate(P p, double theta) {
  return p * P(cos(theta), sin(theta));
}

//
P_type dot(P a, P b) {
  return (a * conj(b)).real();
}

//
P_type cross(P a, P b) {
  return (conj(a) * b).imag();
}

//
int ccw(P a, P b, P c) {
  if (cross(b - a, c - a) > 0) return 1; //COUNTER_CLOCKWISE(center:a)
  if (cross(b - a, c - a) < -0) return -1; //CLOCKWISE(center:a)
  if (dot(b - a, c - a) < -0) return -2; //c -> a -> b
  if (dot(a - b, c - b) < -0) return 2; //a -> b -> c
  return 0; //a -> c -> b
}

/* AB */
bool isIntersectedLS(P a1, P a2, P b1, P b2) {
  int a = ccw(a1, a2, b1);
  int b = ccw(a1, a2, b2);

  //  a or b = 0 or -2 or 2
  return (a % 2) * (b % 2) <= 0; // T (** < 0)
}

using PReal = complex<G_real>;

PReal toReal(P p) {
  return PReal(p.real(), p.imag());
}

/* / */
vector<PReal> getCrosspointLS(P a1, P a2, P b1, P b2) {
  if (!isIntersectedLS(a1, a2, b1, b2)) return {};

  P a = a2 - a1;
  P b = b2 - b1;
  return {toReal(a1) + toReal(a * cross(b, b1 - a1)) / toReal(cross(b, a))};
}

Real getLength(P a1, P a2, P b1, P b2) {
  P a = a2 - a1;
  P b = b2 - b1;
  return abs(toReal(a * cross(b, b1 - a1)) / toReal(cross(b, a)));
}


int X[SIZE], Y[SIZE];
P p[SIZE];

int main() {
  int N, H;

  scanf("%d%d", &N, &H);

  for (int i = 0; i < N; i++) {
    scanf("%d%d", X + i, Y + i);
    p[i] = P(X[i], Y[i]);
  }

  Real ans = 0;
  P eye = P(X[N - 1], Y[N - 1] + H);
  int top = N - 1;

  for (int i = N - 2; i >= 0; i--) {
    int cc = ccw(eye, p[top], p[i]);
    if (cc == -1) { // CLOCKWISE
      // PReal c = getCrosspointLS(p[top], eye, p[i + 1], p[i])[0];
      // ans += abs(c - toReal(p[i]));
      ans += getLength(p[i], p[i + 1], p[top], eye);
      top = i;
    } else if (cc == 2 && ccw(eye, p[i + 1], p[i]) == 2) { // a -> b -> c
      ans += abs(toReal(p[i + 1] - p[i]));
      top = i;
    }
  }

  printf("%.12Lf\n", ans);

  return 0;
}