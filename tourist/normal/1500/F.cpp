/**
 *    author:  tourist
 *    created: 13.03.2021 14:01:42       
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
  long long C;
  cin >> n >> C;
  vector<long long> w(n - 2);
  for (int i = 0; i < n - 2; i++) {
    cin >> w[i];
  }
  long long L = 0;
  long long R = w[0];
  set<long long> s;
  long long k = 1;
  long long b = 0;
  vector<long long> Ls(n - 2);
  vector<long long> Rs(n - 2);
  vector<bool> flag(n - 2);
  vector<long long> any(n - 2);
  Ls[0] = L;
  Rs[0] = R;
  any[0] = L;
  for (int i = 1; i < n - 2; i++) {
    bool inside = false;
    inside |= (L <= w[i] && w[i] <= R);
    if (!inside) {
      auto it = s.find((w[i] - b) / k);
      inside |= (it != s.end());
    }
    flag[i] = inside;
    if (inside) {
      L = 0;
      R = w[i];
      s.clear();
      k = 1;
      b = 0;
    } else {
      if (L <= R && L > w[i]) {
        L = -1;
        R = -2;
      }
      while (!s.empty()) {
        auto it = (k == 1 ? prev(s.end()) : s.begin());
        if (k * (*it) + b <= w[i]) {
          break;
        }
        s.erase(it);
      }
      if (L > R && s.empty()) {
        cout << "NO" << '\n';
        return 0;
      }
      if (L <= R) {
        any[i - 1] = L;
      } else {
        any[i - 1] = k * (*s.begin()) + b;
      }
      if (L <= R) {
        L = w[i] - L;
        R = w[i] - R;
        swap(L, R);
      }
      // x -> k * x + b
      // I want: x -> w - (k * x + b)
      // x -> -k * x + (w - b)
      k = -k;
      b = w[i] - b;
      s.insert((w[i] - b) / k);
    }
    debug(L, R, s, k, b);
    Ls[i] = L;
    Rs[i] = R;
  }
  cout << "YES" << '\n';
  vector<long long> d(n - 2);
  if (L <= R) {
    d.back() = L;
  } else {
    d.back() = k * (*s.begin()) + b;
  }
  debug(any);
  for (int i = n - 3; i > 0; i--) {
    if (flag[i]) {
      d[i - 1] = w[i];
    } else {
      if (d[i] == w[i]) {
        d[i - 1] = any[i - 1];
      } else {
        d[i - 1] = w[i] - d[i];
      }
    }
    assert(0 <= d[i - 1] && d[i - 1] <= w[i - 1]);
  }
  debug(d);
  vector<long long> a(n);
  a[0] = 0;
  a[1] = w[0] - d[0];
  a[2] = w[0];
  for (int i = 3; i < n; i++) {
    bool found = false;
    for (int sign = -1; sign <= 1; sign += 2) {
      a[i] = a[i - 1] + sign * d[i - 2];
      long long mx = max(a[i], max(a[i - 1], a[i - 2]));
      long long mn = min(a[i], min(a[i - 1], a[i - 2]));
      if (mx - mn == w[i - 2]) {
        found = true;
        break;
      }
    }
    assert(found);
  }
  long long mn = *min_element(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    a[i] -= mn;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << '\n';
  return 0;
}