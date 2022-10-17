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

string to_str(int x) {
  if (!x) {
    return "0";
  }
  string s;
  while (x) {
    s.pb(char('0' + x % 10));
    x /= 10;
  }
  reverse(all(s));
  return s;
}

void out(vector<string> &ans) {
  cout << SZ(ans) << '\n';
  for (auto it : ans) {
    cout << it << '\n';
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  string s;
  cin >> s;
  int add = 0;
  while (s.back() == '0') {
    s.pop_back();
    add++;
  }
  reverse(all(s));
  vector<int> blocks = {0};
  char prv = '1';
  for (auto it : s) {
    if (it == prv) {
      blocks.back()++;
    }
    else {
      prv = char(int('1') ^ int('0') ^ int(prv));
      blocks.pb(1);
    }
  }
  vector<pair<int, int>> segs;
  segs.pb({0, 0});
  for (int i = 2; i < SZ(blocks); i += 2) {
    if (blocks[i - 1] > 1) {
      segs.pb({i, i});
    }
    else {
      segs.back().S += 2;
    }
  }
  vector<string> rez;
  for (auto it : segs) {
    bool have_big = false;
    for (int i = it.F; i <= it.S; i++) {
      if (i % 2 == 0 && blocks[i] > 1) {
        have_big = true;
      }
    }
    if (!have_big) {
      for (int i = it.F; i <= it.S; i++) {
        if (i % 2 == 0) {
          rez.pb("+2^" + to_str(add));
        }  
        add += blocks[i];
      }
    }
    else {
      rez.pb("-2^" + to_str(add));
      for (int i = it.F; i <= it.S; i++) {
        if (i & 1) {
          rez.pb("-2^" + to_str(add));
        }
        add += blocks[i];
      }
      rez.pb("+2^" + to_str(add));
    }
    if (it.S + 1 < SZ(blocks)) {
      add += blocks[it.S + 1];
    }
  }
  out(rez);
}