/**
 *    author: m371
 *    created: 06.10.2021 21:43:33
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
    long long n, m;
    cin >> n >> m;
    vector<long long> a(m);
    for (int i = 0; i < m; i++) {
      cin >> a[i];
    }
    if (accumulate(a.begin(), a.end(), 0LL) < n) {
      cout << -1 << '\n';
      continue;
    }
    const int LOG = 61;
    vector<int> cnt(LOG);
    for (int i = 0; i < m; i++) {
      cnt[log2(a[i])]++;   
    }        
    debug(cnt);
    int ans = 0;
    for (int i = 0; i < LOG; i++) {
      if (n & (1LL << i)) {
        if (cnt[i] == 0) {
          for (int j = i + 1; j < LOG; j++) {
            if (cnt[j] > 0) {
              for (int k = j; k > i; k--) {
                cnt[k]--;
                ans += 1;
                cnt[k - 1] += 2;
              }
              break;
            }
          }
          cnt[i]--;
        } else {
          cnt[i]--;
        }
      }
      if (i + 1 < LOG) {
        cnt[i + 1] += cnt[i] / 2;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}