/**
 *    author:  wxhtzdy
 *    created: 23.10.2022 18:16:17
**/
#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}
string to_string(const char* s) {
  return to_string((string) s);
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<long long> pref_sum(n + 1);
    vector<long long> pref_xor(n + 1);
    for (int i = 1; i <= n; i++) {
      pref_sum[i] = pref_sum[i - 1] + a[i];
      pref_xor[i] = pref_xor[i - 1] ^ a[i];
    }        
    auto Get = [&](int l, int r) {
      long long range_sum = pref_sum[r] - pref_sum[l - 1];
      long long range_xor = pref_xor[r] ^ pref_xor[l - 1];
      return range_sum - range_xor;      
    };
    int lst = 0;          
    vector<int> prv(n + 1);
    for (int i = 1; i <= n; i++) {
      prv[i] = lst;
      if (a[i] > 0) {
        lst = i;
      }
    }               
    lst = n + 1;
    vector<int> nxt(n + 1);
    for (int i = n; i >= 1; i--) {
      nxt[i] = lst;
      if (a[i] > 0) {
        lst = i;
      }
    }
    //debug(prv);
    //debug(nxt);                       
    while (q--) {
      int l, r;
      cin >> l >> r;
      vector<int> ids;    
      {
        int x = l;
        for (int iter = 0; iter < 32; iter++) {
          ids.push_back(x);
          x = nxt[x];
          if (x > r) {
            break;
          }
        }
      }
      {
        int x = r;
        for (int iter = 0; iter < 32; iter++) {
          ids.push_back(x);
          x = prv[x];
          if (x < l) {
            break;
          }
        }
      }
      int bstl = l;
      int bstr = r;
      long long ans = Get(l, r);                                         
      for (int i : ids) {
        for (int j : ids) {
          if (i > j) {
            continue;
          }
          long long nans = Get(i, j);
          if (ans < nans) {
            ans = nans;
            bstl = i;
            bstr = j;             
          } else if (ans == nans && bstr - bstl > j - i) {
            bstl = i;
            bstr = j;
          }
        }
      }
      cout << bstl << " " << bstr << " " << '\n';
    }
  }                                                                    
  return 0;
}