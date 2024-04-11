/**
 *    author:  tourist
 *    created: 29.08.2021 17:38:14       
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
  int n;
  cin >> n;
  vector<long long> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  if (n % 2 == 1) {
    --n;
  }
  unsigned long long ans = 0;
  vector<vector<long long>> mx(n, vector<long long>(n, 1));
  vector<vector<long long>> my(n, vector<long long>(n, 1));
  for (int i = 0; i < n; i += 2) {
    long long b = 0;
    long long min_b = 0;
    for (int j = i + 1; j < n; j++) {
      if (j % 2 == 1) {
        mx[i][j] = max(1LL, -min_b);
        b -= c[j];
        min_b = min(min_b, b);
      } else {
        b += c[j];
      }
    }
  }
  for (int i = n - 1; i >= 0; i -= 2) {
    long long b = 0;
    long long min_b = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (j % 2 == 0) {
        my[j][i] = max(1LL, -min_b);
        b -= c[j];
        min_b = min(min_b, b);
      } else {
        b += c[j];
      }
    }
  }
  for (int i = 0; i < n; i += 2) {
    for (int j = i + 1; j < n; j += 2) {
      long long x = c[i];
      long long y = c[j];
      if (mx[i][j] <= x && my[i][j] <= y) {
        ans += min(x - mx[i][j] + 1, y - my[i][j] + 1);
      }
    }
  }
//      debug(i, j, x, y, mx, my);
  cout << ans << '\n';
  return 0;
}