/**
 *    author:  tourist
 *    created: 10.10.2020 18:15:07       
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
  long long x;
  cin >> x;
  vector<tuple<long long, char, long long>> ret;
  while (x > 1) {
    if ((x & (x + 1)) == 0) {
      if (x == 3) {
        ret.emplace_back(3, '+', 3);
        ret.emplace_back(3, '^', 6);
        ret.emplace_back(3, '+', 5);
        ret.emplace_back(3, '+', 6);
        ret.emplace_back(8, '^', 9);
        x = 1;
        break;
      }
      ret.emplace_back(x, '+', x);
      ret.emplace_back(x, '^', 2 * x);
      x = x ^ (2 * x);
      continue;
    }
    long long y = x;
    long long bit = 1;
    while ((bit << 1) <= x) {
      ret.emplace_back(y, '+', y);
      bit <<= 1;
      y <<= 1;
    }
    ret.emplace_back(y, '+', x);
    y += x;
    long long z = x;
    while (y != 0 && z != 0) {
      int dy = __builtin_clzll(y);
      int dz = __builtin_clzll(z);
      if (dy < dz) {
        swap(dy, dz);
        swap(y, z);
      }
      for (int i = 0; i < dy - dz; i++) {
        ret.emplace_back(y << i, '+', y << i);
      }
      ret.emplace_back(z, '^', y << (dy - dz));
      z ^= (y << (dy - dz));
    }
    y += z;
    debug(x, y, y < x);
    x = y;
  }
  cout << ret.size() << '\n';
  for (auto& v : ret) {
    cout << get<0>(v) << " " << get<1>(v) << " " << get<2>(v) << '\n';
  }
  return 0;
}