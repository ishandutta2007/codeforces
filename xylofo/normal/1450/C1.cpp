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
  int n;
  cin>>n;
  vector<string> v(n);
  rep(i,0,n) cin>>v[i];
  int k = 0;
  rep(i,0,n) rep(j,0,n)
    if(v[i][j] != '.') ++k;

  char a = 'X', b = 'O';
  rep(_,0,2) {
    rep(off,0,3) {
      int change = 0;
      rep(i,0,n) rep(j,0,n) {
        if((i + j) % 3 == off)
          if(v[i][j] == a) ++change;
        if((i + j) % 3 == (off+1)%3)
          if(v[i][j] == b) ++change;
      }
      if(3 * change <= k) {
        rep(i,0,n) rep(j,0,n) {
          if((i + j) % 3 == off)
            if(v[i][j] == a) v[i][j] = b;
          if((i + j) % 3 == (off+1)%3)
            if(v[i][j] == b) v[i][j] = a;
        }
        rep(i,0,n)
          cout << v[i] << "\n";
        return;
      }
    }

    swap(a,b);
  }

  assert(false);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}