/**
 *    author:  tourist
 *    created: 30.08.2020 18:01:47       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
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

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
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

const long long inf = (long long) 4e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long r1, r2, r3, d;
  cin >> n >> r1 >> r2 >> r3 >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long dp0 = 0;
  long long dp1 = inf;
  for (int i = 0; i < n; i++) {
    long long cost1 = a[i] * r1 + r3;
    long long cost2 = min(cost1, min(a[i] * r1 + r1 + r1, r2 + r1));
    long long new_dp0 = inf;
    long long new_dp1 = inf;
    new_dp0 = min(new_dp0, dp0 + cost1);
    new_dp1 = min(new_dp1, dp0 + cost2 + d);
    new_dp0 = min(new_dp0, dp1 + cost2 + d);
    if (i == n - 1) {
      new_dp0 = min(new_dp0, dp1 + cost1);
    }
    dp0 = new_dp0;
    dp1 = new_dp1;
    debug(i, cost1, cost2, dp0, dp1);
  }
  cout << min(dp0, dp1 + d) + d * (n - 1) << '\n';
  return 0;
}