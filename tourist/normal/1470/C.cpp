/**
 *    author:  tourist
 *    created: 05.01.2021 18:11:34       
**/
#undef LOCAL

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
  int n, k;
  cin >> n >> k;
  vector<int> a(n, k);
  vector<int> b(n);
  #ifdef LOCAL
  mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
  int secret = rng() % n;
  debug(secret);
  int Q = 0;
  #endif
  auto Ask = [&](int pos) {
    #ifdef LOCAL
    Q += 1;
    int res = a[pos];
    for (int i = 0; i < n; i++) {
      b[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      int R = (i + 1) % n;
      int L = (i + n - 1) % n;
      if (i == secret) {
        b[R] += a[i];
      } else {
        b[L] += a[i] / 2;
        b[R] += (a[i] + 1) / 2;
      }
    }
    swap(a, b);
    return res;
    #else
    cout << "? " << pos + 1 << endl;
    int foo;
    cin >> foo;
    return foo;
    #endif
  };
  const int WAIT = 500;
  for (int i = 0; i < WAIT; i++) {
    Ask(0);
  }
  int step = (n + 399) / 400;
  int L = -1;
  int R = -1;
  for (int i = 0; i < n; i += step) {
    int x = Ask(i);
    if (x > k) {
      L = i - (n + 1) / 2;
      R = i;
      while (L + 1 < R) {
        int M = L + (R - L) / 2;
        x = Ask((M % n + n) % n);
        if (x > k) {
          R = M;
        } else {
          L = M;
        }
      }
      int res = (L % n + n) % n;
      cout << "! " << res + 1 << endl;
      #ifdef LOCAL
      debug(res);
      debug(Q);
      assert(res == secret);
      #endif
      return 0;
    }
    if (x < k) {
      L = i;
      R = i + (n + 1) / 2;
      while (L + 1 < R) {
        int M = L + (R - L) / 2;
        x = Ask((M % n + n) % n);
        if (x < k) {
          L = M;
        } else {
          R = M;
        }
      }
      int res = (R % n + n) % n;
      cout << "! " << res + 1 << endl;
      #ifdef LOCAL
      debug(res);
      debug(Q);
      assert(res == secret);
      #endif
      return 0;
    }
  }
  assert(false);
  return 0;
}