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
 
int c[55][55];

int solve(int l, int r) {
  int add_end = l;
  r -= l;
  int pw = 0;
  while ((1 << (pw + 1)) - 1 <= r) {
    pw++;
  }
  //2^pw - 1 <= r
  //pw - 1 ~--- max st
  for (int i = 1; i <= pw; i++) {
    for (int j = i + 1; j <= pw + 1; j++) {
      c[i][j] = 1 << (j - 2);
    }
  }
  int lst = pw + 1;
  r -= (1 << pw);
  debug(r);
  int cadd = 1 << pw;
  while (r >= 0) {
    int cur = 0;
    lst++;
    while ((1 << (cur + 1)) - 1 <= r) {
      cur++;
    }
    for (int i = cur + 1; i >= 1; i--) {
      int len = (1 << (i - 1)) - 1;
      if (len <= r) {
        c[i][lst] = cadd;
        if (i > 1) {
          c[i][lst] -= 1 << (i - 1);
        }
        cadd += len + 1;
        r -= len + 1;
        if (r < 0) {
          break;
        }
      }
    }
  }
  lst++;
  return lst;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  /*for (int r = 1; r <= 1e6; r++) {
    if (solve(1, r) > 32) {
      cout << r << ' ' << solve(1, r) << endl;
    }
  }*/
  
  /*for (int i = 1; i < lst; i++) {
    c[i][lst] = add_end;
  }
  vector<pair<int, int>> ans;
  for (int i = 1; i < lst; i++) {
    for (int j = i + 1; j <= lst; j++) {
      if (c[i][j]) {
        ans.pb({i, j});
      }
    }
  }
  cout << "YES\n";
  cout << lst << ' ' << SZ(ans) << '\n';
  for (auto it : ans) {
    cout << it.F << ' ' << it.S << ' ' << c[it.F][it.S] << '\n';
  }*/
  int l, r;
  cin >> l >> r;
  int add_end = l;
  r -= l;
  int pw = 0;
  while ((1 << (pw + 1)) - 1 <= r) {
    pw++;
  }
  //2^pw - 1 <= r
  //pw - 1 ~--- max st
  for (int i = 1; i <= pw; i++) {
    for (int j = i + 1; j <= pw + 1; j++) {
      c[i][j] = 1 << (j - 2);
    }
  }
  int lst = pw + 1;
  r -= (1 << pw);
  debug(r);
  int cadd = 1 << pw;
  while (r >= 0) {
    lst++;
    for (int i = pw + 1; i >= 2; i--) {
      int len = (1 << (i - 2)) - 1;
      if (len <= r) {
        c[i][lst] = cadd - (1 << (i - 2));
        cadd += len + 1;
        r -= len + 1;
        if (r < 0) {
          break;
        }
      }
    }
    if (r < 0) {
      break;
    }
    c[1][lst] = cadd;
    cadd++;
    r--;
  }
  lst++;
  assert(lst <= 32);
  for (int i = 1; i < lst; i++) {
    c[i][lst] = add_end;
  }
  vector<pair<int, int>> ans;
  for (int i = 1; i < lst; i++) {
    for (int j = i + 1; j <= lst; j++) {
      if (c[i][j]) {
        ans.pb({i, j});
      }
    }
  }
  cout << "YES\n";
  cout << lst << ' ' << SZ(ans) << '\n';
  for (auto it : ans) {
    cout << it.F << ' ' << it.S << ' ' << c[it.F][it.S] << '\n';
  }
}