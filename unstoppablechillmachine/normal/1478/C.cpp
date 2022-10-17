#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

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
 
#ifdef PC
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    bool ok = true;
    vector<int> a(2 * n);
    for (auto &it : a) {
      cin >> it;
    }
    sort(all(a));
    int all_sum = a[0] / 2, sum = 0;
    vector<int> delta;
    for (int i = 0; i < 2 * n; i += 2) {
      if (a[i] != a[i + 1] || (i + 2 < 2 * n && a[i + 1] == a[i + 2])) {
        ok = false;
      }
      if (a[i] % 2 == 1) {
        ok = false;
      }
      if (i + 2 < 2 * n) {
        if ((a[i + 2] - a[i]) % (i + 2) != 0) {
          ok = false;
        } 
        delta.pb((a[i + 2] - a[i]) / (i + 2));
      }
    }
    for (int i = 1; i < SZ(delta); i++) {
      delta[i] += delta[i - 1];
      debug(delta[i]);
      sum += delta[i];
    }
    if (!delta.empty()) sum += delta[0];
    debug(SZ(delta));
    int first = (all_sum - sum);
    if (first < 0 || first % n != 0) {
      ok = false;
    }
    first /= n;
    debug(first, sum, all_sum);
    if (first <= 0) {
      ok = false;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}