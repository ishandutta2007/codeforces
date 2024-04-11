/**
 *    author:  wxhtzdy
 *    created: 08.07.2022 16:42:55
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
  int qq, d;
  cin >> qq >> d;
  const int MAX = 2e5 + 5;
  const int B = sqrt(MAX);
  int cnt = (MAX + B - 1) / B;
  vector<long long> f(MAX);
  vector<int> q(cnt);
  vector<int> val(MAX);
  vector<int> delta(cnt);
  vector<int> act(MAX);
  vector<int> id(MAX);
  for (int i = 0; i < MAX; i++) {
    id[i] = i / B;
  }
  long long ans = 0;
  while (qq--) {
    int a;
    cin >> a;
    if (act[a] == 0) {
      int mv = val[a] + delta[id[a]];
      ans += mv * 1LL * (mv - 1) / 2;
      f[id[a]] += mv - 1;
      q[id[a]] += 1;
      int l = max(1, a - d);
      int r = a - 1;
      if (l > r) {
        act[l] = 1;
        cout << ans << '\n';
        continue;
      }
      while (l <= r && l % B != 0) {
        if (act[l]) {
          int fv = val[l] + delta[id[l]];
          f[id[l]] -= fv - 1;
          ans -= fv * 1LL * (fv - 1) / 2;
          fv += 1;
          ans += fv * 1LL * (fv - 1) / 2;
          f[id[l]] += fv - 1;
        }
        val[l] += 1;
        l += 1;
      }
      while (r >= l && r % B != B - 1) {
        if (act[r]) {
          int fv = val[r] + delta[id[r]];
          f[id[r]] -= fv - 1;
          ans -= fv * 1LL * (fv - 1) / 2;
          fv += 1;
          ans += fv * 1LL * (fv - 1) / 2;
          f[id[r]] += fv - 1;
        }
        val[r] += 1;
        r -= 1;
      }               
      while (l <= r) {
        delta[id[l]] += 1;    
        f[id[l]] += q[id[l]];
        ans += f[id[l]];
        l += B;
      }
      act[a] = 1;
    } else {
      int mv = val[a] + delta[id[a]];
      ans -= mv * 1LL * (mv - 1) / 2;
      f[id[a]] -= mv - 1;
      q[id[a]] -= 1;
      int l = max(1, a - d);
      int r = a - 1;
      if (l > r) {
        act[l] = 0;
        cout << ans << '\n';
        continue;
      }
      while (l <= r && l % B != 0) {
        if (act[l]) {
          int fv = val[l] + delta[id[l]];
          f[id[l]] -= fv - 1;
          ans -= fv * 1LL * (fv - 1) / 2;
          fv -= 1;
          ans += fv * 1LL * (fv - 1) / 2;
          f[id[l]] += fv - 1;
        }
        val[l] -= 1;
        l += 1;
      }
      while (r >= l && r % B != B - 1) {
        if (act[r]) {
          int fv = val[r] + delta[id[r]];
          f[id[r]] -= fv - 1;
          ans -= fv * 1LL * (fv - 1) / 2;
          fv -= 1;
          ans += fv * 1LL * (fv - 1) / 2;
          f[id[r]] += fv - 1;
        }
        val[r] -= 1;
        r -= 1;
      }               
      while (l <= r) {
        delta[id[l]] -= 1;    
        ans -= f[id[l]];
        f[id[l]] -= q[id[l]];
        l += B;
      }
      act[a] = 0;  
    }
    cout << ans << '\n';
  }
  return 0;
}