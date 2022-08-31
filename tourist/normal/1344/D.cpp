/**
 *    author:  tourist
 *    created: 06.05.2020 18:00:01       
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
  long long k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  auto Get = [&](long long limit) {
    // increase while delta >= limit
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      int low = 0, high = a[i];
      while (low < high) {
        int mid = (low + high) >> 1;
        if (a[i] - 3LL * mid * (mid + 1) - 1 >= limit) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }
      b[i] = low;
      sum += b[i];
    }
    return sum;
  };
  long long L = (long long) -4e18;
  long long R = (long long) 4e18;
  while (L < R) {
    long long M = L + (R - L) / 2;
    long long s = Get(M);
    if (s > k) {
      L = M + 1;
    } else {
      R = M;
    }
  }
  long long s = Get(L);
  assert(s <= k);
  debug(s, b);
  auto res = b;
  long long s_new = Get(L - 1);
  debug(s_new, b);
  assert(s_new >= k);
  for (int i = 0; i < n; i++) {
    assert(b[i] == res[i] || b[i] == res[i] + 1);
    if (b[i] == res[i] + 1 && s < k) {
      res[i] += 1;
      s += 1;
    }
  }
  assert(s == k);
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << res[i];
  }
  cout << '\n';
  return 0;
}