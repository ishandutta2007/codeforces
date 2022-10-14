/**
 *    author:  wxhtzdy
 *    created: 09.08.2022 13:56:22
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
    int n, m;
    cin >> n >> m;
    auto Ask = [&](int x, int y) {
      cout << "SCAN " << x << " " << y << endl;
      int z;
      cin >> z;
      return z;
    };
    auto Answer = [&](int x, int y) {
      cout << "DIG " << x << " " << y << endl;
      int z;
      cin >> z;
      return z;
    };       
    
    
    int s0 = Ask(1, 1) + 4;
    int s1 = Ask(1, m) + 2 - 2 * m;
    
    debug(s0, s1);

    int r_sum12 = (s0 + s1) / 2;
    int c_sum12 = (s0 - s1) / 2;
    
    debug(r_sum12, c_sum12);
    
    int r_dif12 = Ask((r_sum12 + 1) / 2, 1);
    int c_dif12 = Ask(1, (c_sum12 + 1) / 2);

    debug(r_dif12, c_dif12);

    int r_dif = r_dif12 - c_sum12 + 2;
    int c_dif = c_dif12 - r_sum12 + 2;

    debug(r_dif, c_dif);

    int r1 = (r_dif + r_sum12) / 2;
    int r2 = r_sum12 - r1;

    int c1 = (c_dif + c_sum12) / 2;
    int c2 = c_sum12 - c1;

    if (Answer(r1, c1)) {
      Answer(r2, c2);
    } else {
      Answer(r1, c2);
      Answer(r2, c1);
    }
  }                                                                    
  return 0;
}

/*
+r1 + c1 + r2 + c2 = s0
+r1 + m - c1 + r2 + m - c2 = s1

r1 + r2 = (s0 + s1) / 2
c1 + c2 = (s0 - s1) / 2 


-r1 + c1 + r2 + c2 = r_dif12

r2 - r1 = r_dif12 - c_sum12

*/