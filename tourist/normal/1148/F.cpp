/**
 *    author:  tourist
 *    created: 01.06.2019 18:10:30       
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
  vector<long long> val(n);
  vector<long long> mask(n);
  vector<int> when(n);
  long long total = 0;
  for (int i = 0; i < n; i++) {
    cin >> val[i] >> mask[i];
    total += val[i];
    when[i] = __builtin_ctzll(mask[i]);
  }
  if (total < 0) {
    for (int i = 0; i < n; i++) {
      val[i] *= -1;
    }
    total *= -1;
  }
  long long s = 0;
  for (int bit = 62; bit >= 0; bit--) {
    vector<long long> t(2, 0);
    for (int i = 0; i < n; i++) {
      if (when[i] == bit) {
        int cur = __builtin_popcountll(s & mask[i]);
        t[cur % 2] += val[i];
      }
    }
    debug(t);
    if (t[0] > t[1]) {
      s |= (1LL << bit);
    }
  }
  cout << s << '\n';
  return 0;
}