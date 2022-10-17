#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void solve(int tc) {
  string s;
  cin>>s;

  auto sim = [&](int bx, int by) {
    if(bx == 0 && by == 0) return false;
    int x = 0, y = 0;
    for(char c: s) {
      int ox = x, oy = y;
      if(c == 'L') --x;
      if(c == 'R') ++x;
      if(c == 'D') --y;
      if(c == 'U') ++y;
      if(x == bx && y == by) x = ox, y = oy;
    }
    if(x == 0 && y == 0) {
      cout << bx << " " << by << endl;
      return true;
    }
    return false;
  };

  int x = 0, y = 0;
  for(char c: s) {
    if(c == 'L') --x;
    if(c == 'R') ++x;
    if(c == 'D') --y;
    if(c == 'U') ++y;
    if(x != 0 || y != 0) if(sim(x,y)) return;
  }

  cout << 0 << " " << 0 << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}