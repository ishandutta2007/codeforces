#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
 
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

const int MOD = 1e9 + 7;

inline void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += MOD;
  }
}

inline int sum(int a, int b) {
  add(a, b);
  return a;
}

int mult(int a, int b) {
  return (a * 1ll * b) % MOD;
}

int b_pow(int a, int b) {
  int cur = a, ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = mult(ans, cur);
    }
    b >>= 1;
    cur = mult(cur, cur);
  }  
  return ans;
}

int inv(int a) {
  return b_pow(a, MOD - 2);
}

const int N = 1e5 + 10;
const int B = sqrt(N);
const int inf = 1e9 + 10;

int dp[N][B], pref[N][B], f[2 * N], inv_f[2 * N];

inline int C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  return mult(f[n], mult(inv_f[k], inv_f[n - k]));
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  f[0] = inv_f[0] = 1;
  for (int i = 1; i < 2 * N; i++) {
    f[i] = mult(f[i - 1], i);
    inv_f[i] = inv(f[i]);
  }
  pref[0][0] = 1;
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> ways(n + 1);
    for (int i = 1; i <= n; i++) {
      int ost = n - k * (i - 1) - 1;
      if (ost < 0) {
        break;
      }
      ways[i] = C(ost + i, i);
    }
    for (int i = 1; i <= n; i++) {
      if (ways[i]) debug(ways[i]);
      ways[i] = mult(ways[i], f[i]);
    }
    int answer = 0, prob = inv(n);
    for (int cnt = 2; cnt <= n; cnt++) {
      int vl = mult(ways[cnt - 1], n - cnt + 1);
      sub(vl, ways[cnt]);
      prob = mult(prob, inv(n - cnt + 1));
      add(answer, mult(cnt, mult(vl, prob))); 
    }
    cout << answer << '\n';
  }
}