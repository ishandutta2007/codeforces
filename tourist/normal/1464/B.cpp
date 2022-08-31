/**
 *    author:  tourist
 *    created: 20.12.2020 18:09:01       
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  long long c01, c10;
  cin >> c01 >> c10;
  int n = (int) s.size();
  long long add = 0;
  {
    int p0 = 0;
    int p1 = 0;
    for (char c : s) {
      if (c == '0') {
        add += c10 * p1;
        p0 += 1;
      }
      if (c == '1') {
        add += c01 * p0;
        p1 += 1;
      }
    }
  }
  vector<long long> cost0(n, -1);
  vector<long long> cost1(n, -1);
  {
    int k1 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        k1 += 1;
      }
    }
    int p1 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        p1 += 1;
      }
      if (s[i] == '?') {
        cost0[i] = c10 * p1 + c01 * (k1 - p1);
      }
    }
  }
  {
    int k0 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        k0 += 1;
      }
    }
    int p0 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        p0 += 1;
      }
      if (s[i] == '?') {
        cost1[i] = c01 * p0 + c10 * (k0 - p0);
      }
    }
  }
  debug(cost0);
  debug(cost1);
  int cq = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      cq += 1;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      ans += cost0[i];
    }
  }
  long long start = ans;
  long long cur = ans;
  int pq = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      pq += 1;
      cur += cost1[i] - cost0[i];
      ans = min(ans, cur + c10 * pq * (cq - pq));
    }
  }
  cur = start;
  pq = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '?') {
      pq += 1;
      cur += cost1[i] - cost0[i];
      ans = min(ans, cur + c01 * pq * (cq - pq));
    }
  }
  cout << ans + add << '\n';
  return 0;
}