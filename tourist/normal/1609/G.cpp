/**
 *    author:  tourist
 *    created: 28.11.2021 18:24:02       
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
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  auto init_b = b;
  vector<long long> da(n - 1);
  for (int i = 0; i < n - 1; i++) {
    da[i] = a[i + 1] - a[i];
  }
  vector<long long> db(m - 1);
  for (int i = 0; i < m - 1; i++) {
    db[i] = b[i + 1] - b[i];
  }
  fenwick<int> fenw(m - 1);
  fenwick<long long> fenw2(m - 1);
  long long ans = 0;
  for (int i = 0; i < m - 1; i++) {
    ans += db[i] * (m - 1 - i);
  }
  while (q--) {
    int type, k, d;
    cin >> type >> k >> d;
    if (type == 1) {
      if (k == n) {
        a[0] += d;
        k -= 1;
      }
      for (int i = 0; i < k; i++) {
        a[n - k + i] += d * (i + 1);
        da[n - k + i - 1] += d;
      }
    } else {
      if (k == m) {
        b[0] += d;
        k -= 1;
      }
      fenw.modify(m - k - 1, d);
      fenw2.modify(m - k - 1, ((long long) -d) * (m - k - 2));
      ans += ((long long) d) * k * (k + 1LL) / 2;
    }
    long long res = ans;
    res += (a[0] + b[0]) * (n + m - 1);
    for (int i = 0; i < n - 1; i++) {
      int low = 0, high = m - 1;
      while (low < high) {
        int mid = (low + high) >> 1;
        if (db[mid] + fenw.get(mid) > da[i]) {
          high = mid;
        } else {
          low = mid + 1;
        }
      }
      int my_id = (n - 2 - i) + (m - 1 - low) + 1;
      res += da[i] * my_id;
      res += init_b[low] - init_b[0];
      res += fenw.get(low - 1) * (long long) (low - 1) + fenw2.get(low - 1);
    }
    cout << res << '\n';
  }
  return 0;
}