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

const int MOD = 998244353;
 
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
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> pref(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    if (n == 2) {
      cout << 1 + (a[0] != a[1]) << '\n';
      continue;
    }
    pref[0][0] = a[0];
    for (int i = 1; i < n; i++) {
      pref[i] = pref[i - 1];
      pref[i][i % 2] += a[i];
    }

    auto get_sum = [&](int l, int r, int parity) {
      if (l > r) {
        return 0ll;
      }
      int result = pref[r][parity];
      if (l) {
        result -= pref[l - 1][parity];
      }
      return result;
    };

    auto calc = [&](int l, int r, int delta, bool can_end_with_c) {
      if (l == r + 1) {
        return (delta > 0 ? 1ll : 0ll); 
      }
      if (get_sum(l, r, 0) + get_sum(l, r, 1) + delta <= 0) {
        return 0ll;
      }
      int lo = 0, hi = (r - l + 1) / 2 + 1;
      while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        int block_r = l + 2 * mid;
        if (get_sum(l, block_r - 1, l % 2) + delta + get_sum(block_r, r, 0) + get_sum(block_r, r, 1) > get_sum(l, block_r - 1, 1 - l % 2)) {
          lo = mid;
        }
        else {
          hi = mid;
        }
      }
      int result = lo + 1;
      debug(l, r, result);
      if (r - l + 1 == lo * 2 && !can_end_with_c) {
        result--;
      }
      return result;
    };  
    
    int ans = 0;
    for (int cnt_r = 2; cnt_r <= n; cnt_r++) {
      if (get_sum(0, cnt_r - 1, 0) + get_sum(0, cnt_r - 1, 1) > get_sum(cnt_r, n - 1, 0) + get_sum(cnt_r, n - 1, 1)) {
        add(ans, 1);
      }
    }
    debug(ans);

    for (int fst = 0; fst < 2; fst++) {
      for (int lst = 0; lst < 2; lst++) {
        string fst_c = fst ? "R" : "C"; 
        string lst_c = lst ? "R" : "C";
        int delta = 0;
        delta += (fst ? a[0] : -a[0]);
        delta += (lst ? a.back() : -a.back());
        for (int block_c_len = 0; block_c_len + 2 <= n; block_c_len++) {
          if (fst && !block_c_len) {
            continue;
          }
          add(ans, calc(block_c_len + 1, n - 2, delta - get_sum(1, block_c_len, 0) - get_sum(1, block_c_len, 1), lst));
          if (!fst && lst) {
            debug(block_c_len, ans);
          }
        }
        //debug(fst_c, lst_c, ans);
      }
    }

    cout << ans << '\n';
  }
}