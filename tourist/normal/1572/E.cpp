/**
 *    author:  tourist
 *    created: 18.09.2021 19:19:50       
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

template <typename T>
struct TPoint {
  T x;
  T y;
  int id;

  TPoint() : x(0), y(0), id(-1) {}
  TPoint(const T& x_, const T& y_) : x(x_), y(y_), id(-1) {}
  TPoint(const T& x_, const T& y_, int id_) : x(x_), y(y_), id(id_) {}

  static constexpr T eps = static_cast<T>(1e-9);

  inline TPoint operator+(const TPoint& rhs) const { return TPoint(x + rhs.x, y + rhs.y); }
  inline TPoint operator-(const TPoint& rhs) const { return TPoint(x - rhs.x, y - rhs.y); }
  inline TPoint operator*(const T& rhs) const { return TPoint(x * rhs, y * rhs); }
  inline TPoint operator/(const T& rhs) const { return TPoint(x / rhs, y / rhs); }

  friend T smul(const TPoint& a, const TPoint& b) {
    return a.x * b.x + a.y * b.y;
  }

  friend T vmul(const TPoint& a, const TPoint& b) {
    return a.x * b.y - a.y * b.x;
  }

  inline T abs2() const {
    return x * x + y * y;
  }

  inline bool operator<(const TPoint& rhs) const {
    return (y < rhs.y || (y == rhs.y && x < rhs.x));
  }

  inline bool is_upper() const {
    return (y > eps || (abs(y) <= eps && x > eps));
  }

  inline int cmp_polar(const TPoint& rhs) const {
    assert(abs(x) > eps || abs(y) > eps);
    assert(abs(rhs.x) > eps || abs(rhs.y) > eps);
    bool a = is_upper();
    bool b = rhs.is_upper();
    if (a != b) {
      return (a ? -1 : 1);
    }
    long long v = x * rhs.y - y * rhs.x;
    return (v > eps ? -1 : (v < -eps ? 1 : 0));
  }
};

using Point = TPoint<long long>;
//using Point = TPoint<long double>;

template <typename T>
string to_string(const TPoint<T>& p) {
  return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<Point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  vector<vector<long long>> area(n, vector<long long>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int k = 2; k <= n - 1; k++) {
      int x = (i + k - 1) % n;
      int y = (i + k) % n;
      area[i][y] = area[i][x] + abs(vmul(p[x] - p[i], p[y] - p[i]));
    }
  }
  debug(area);
  if (k == 0) {
    cout << area[0][n - 1] << '\n';
    return 0;
  }
  long long low = 0;
  long long high = (long long) 4e18;
  while (low < high) {
    long long mid = (low + high + 1) >> 1;
    const int inf = (int) 1e6;
    vector<vector<int>> dp(n, vector<int>(n, -inf));
    for (int len = 1; len <= n - 1; len++) {
      for (int i = 0; i < n; i++) {
        int j = (i + len) % n;
        if (area[i][j] >= mid) {
          dp[i][j] = 0;
        }
        for (int q = 2; q <= len - 2; q++) {
          int u = (i + q) % n;
          if (area[i][j] - area[i][u] - area[u][j] >= mid) {
            dp[i][j] = max(dp[i][j], dp[i][u] + dp[u][j] + 2);
          }
        }
        int p = 0;
        for (int q = 0; q <= len - 2; q++) {
          int u = (i + q) % n;
          p = max(p, q);
          while (p < len) {
            int v = (i + p + 1) % n;
            if (area[i][j] - area[u][v] >= mid) {
              ++p;
            } else {
              break;
            }
          }
          int v = (i + p) % n;
          if (area[i][j] - area[u][v] >= mid) {
            dp[i][j] = max(dp[i][j], dp[u][v] + 1);
          }
        }
        debug(mid, i, j, dp[i][j]);
      }
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dp[i][j] + dp[j][i] + 1 >= k) {
          ok = true;
          break;
        }
      }
      if (ok) break;
    }
    if (ok) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  cout << low << '\n';
  return 0;
}