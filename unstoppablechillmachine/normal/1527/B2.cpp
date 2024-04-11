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
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  auto solve_pal = [](string &s) {
    int cnt_zeros = accumulate(all(s), 0ll, [](int result, char c) { 
      return result + (c == '0'); 
    });
    if (cnt_zeros == 1) {
      return -1;
    }
    return (cnt_zeros & 1) ? 1 : -2;
  };

  auto print = [](int result) {
    if (result > 0) {
      cout << "ALICE" << '\n';
    } else if (result == 0) {
      cout << "DRAW" << '\n';
    } else {
      cout << "BOB" << '\n';
    }
  };

  int T;
  cin >> T;
  while (T--) {
    string s, s_pal;
    int n;
    cin >> n >> s;
    s_pal = s;
     int diff = 0;
    for (int i = 0; i < n / 2; i++) {
      if (s[i] != s[n - i - 1]) {
        diff++;
        s_pal[i] = s_pal[n - i - 1] = '1';
      }
    }
    if (diff == 0) {
      print(solve_pal(s)); 
    } else if (diff == 1) {
      print(max(-1 - solve_pal(s_pal), 1 + solve_pal(s_pal)));
    } else {
      cout << "ALICE" << '\n'; 
    } 
  }
}