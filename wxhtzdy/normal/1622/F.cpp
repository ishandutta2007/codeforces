/**
 *    author:  wxhtzdy
 *    created: 25.01.2022 08:03:23
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
  int n;
  cin >> n;
  mt19937 rng(time(0));
  vector<long long> a(n + 1);
  vector<bool> prime(n + 1, true); 
  for (int i = 2; i <= n; i++) {
    if (prime[i]) {
      long long x = rng();
      long long y = rng();
      a[i] = (((x & ((1 << 29) - 1)) << 29) | y);         
      for (int j = i + i; j <= n; j += i) {
        prime[j] = false;
        int x = j;
        while (x % i == 0 && x > 0) {
          a[j] ^= a[i];
          x /= i;
        }
      }
    }
  }
  debug(a);
  long long t = 0, x = 0;
  for (int i = 2; i <= n; i++) {
    x ^= a[i];     
    a[i] = x;
    t ^= x;
  }
  if (t == 0) {
    cout << n << '\n';
    for (int  i = 1; i <= n; i++) {
      cout << i << " ";
    }
    return 0;
  }               
  for (int i = 1; i <= n; i++) {
    if (t == a[i]) {
      cout << n - 1 << '\n';
      for (int j = 1; j <= n; j++) {
        if (i == j) {
          continue;
        }
        cout << j << " ";
      }     
      return 0;
    }
  }     
  map<long long, int> who;
  for (int i = 1; i <= n; i++) {
    who[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    t ^= a[i];
    if (who[t] != 0 && who[t] != i) {
      cout << n - 2 << '\n';
      for (int j = 1; j <= n; j++) {
        if (j == i || j == who[t]) {
          continue;
        }
        cout << j << " ";
      }
      return 0;
    }
    t ^= a[i];
  }
  t ^= a[n];
  who.clear();
  for (int i = 1; i < n; i++) {
    who[a[i]] = i;
  }            
  for (int i = 1; i < n; i++) {
    t ^= a[i];
    if (who[t] != 0 && who[t] != i) {
      cout << n - 3 << '\n';
      for (int j = 1; j < n; j++) {
        if (j == i || j == who[t]) {
          continue;
        }
        cout << j << " ";
      }
      return 0;
    }
    t ^= a[i];
  }
  assert(false);
  return 0;
}