/**
 *    author:  tourist
 *    created: 18.10.2017 12:37:47       
**/
#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T>
vector<int> manacher(int n, const T &s) {
  if (n == 0) {
    return vector<int>();
  }
  vector<int> res(2 * n - 1, 0);
  int l = -1, r = -1;
  for (int z = 0; z < 2 * n - 1; z++) {
    int i = (z + 1) >> 1;
    int j = z >> 1;
    int p = (i >= r ? 0 : min(r - i, res[2 * (l + r) - z]));
    while (j + p + 1 < n && i - p - 1 >= 0) {
      if (s[j + p + 1] != s[i - p - 1]) {
        break;
      }
      p++;
    }
    if (j + p > r) {
      l = i - p;
      r = j + p;
    }
    res[z] = p;
  }
  return res;
  // res[2 * i] = odd radius in position i
  // res[2 * i + 1] = even radius between positions i and i + 1
  // s = "abaa" -> res = {0, 0, 1, 0, 0, 1, 0}
}

template <typename T>
vector<int> manacher(const T &s) {
  return manacher(s.size(), s);
}

const int md = 51123987;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}

inline int mul(int a, int b) {
#if !defined(_WIN32) || defined(_WIN64)
  return (long long) a * b % md;
#endif
  unsigned long long x = (long long) a * b;
  unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
  asm(
    "divl %4; \n\t"
    : "=a" (d), "=d" (m)
    : "d" (xh), "a" (xl), "r" (md)
  );
  return m;
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}

char s[2345678];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  vector<int> p = manacher(n, s);
  debug(p);
  int total = n;
  for (int i = 0; i < 2 * n - 1; i++) {
    add(total, p[i]);
  }
  vector<int> start(n + 1, 0), finish(n + 1, 0);
  for (int z = 0; z < 2 * n - 1; z++) {
    int i = (z + 1) >> 1;
    int j = z >> 1;
    start[i - p[z]]++;
    start[j + 1]--;
    finish[i]++;
    finish[j + p[z] + 1]--;
  }
  for (int i = 0; i < n; i++) {
    add(start[i + 1], start[i]);
    add(finish[i + 1], finish[i]);
  }
  int ans = 0;
  int acc = 0;
  for (int i = 0; i < n; i++) {
    add(ans, mul(start[i], acc));
    add(acc, finish[i]);
  }
  total = mul(mul(total, total + md - 1), inv(2));
  sub(total, ans);
  printf("%d\n", total);
  return 0;
}