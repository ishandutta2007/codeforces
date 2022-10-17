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
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> dp(n + 2, vector<int>(k + 2));
  vector<int> cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 1;
  }
  for (int j = 1; j <= k; j++) {
    for (int pos = 1; pos <= n; pos++) {
      dp[pos][j] = sum(dp[pos - 1][j - 1], dp[pos + 1][j - 1]);
    }
  }
  for (int pos = 1; pos <= n; pos++) {
    for (int step = 0; step <= k; step++) {
      int coef = mult(dp[pos][step], dp[pos][k - step]);
      add(cnt[pos], coef);      
    }
  }
  for (int pos = 1; pos <= n; pos++) {
    debug(cnt[pos]);
  }
  int cur_sum = 0;
  for (int pos = 1; pos <= n; pos++) {
    add(cur_sum, mult(cnt[pos], a[pos]));
  }
  for (int i = 0; i < q; i++) {
    int pos, new_val;
    cin >> pos >> new_val;
    sub(cur_sum, mult(a[pos], cnt[pos]));
    a[pos] = new_val;
    add(cur_sum, mult(a[pos], cnt[pos]));    
    cout << cur_sum << '\n';
  }
}