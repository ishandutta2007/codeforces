#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void solve() {
  int n; cin >> n;
  vector<vi> people(n, vi(5));
  rep(i,0,n) {
    rep(j,0,5) {
      cin >> people[i][j];
    }
  }
  auto wins = [&](int x, int y) {
    int score = 0;
    rep(i,0,5) score += people[x][i] < people[y][i];
    if (score >= 3) return x;
    return y;
  };

  vi interesting(n);
  rep(i,0,n) interesting[i] = i;
  while(sz(interesting) > 1) {
    int ind = rand() % sz(interesting);
    int x = interesting[ind];
    vi beatsX;
    trav(y, interesting) if (x != y) {
      if (wins(x, y) == y) {
        beatsX.push_back(y);
      }
    }
    if (sz(beatsX) == 0) {
      beatsX.push_back(x);
    }
    else {
      interesting = beatsX;
    }
  }
  int x = interesting[0];
  rep(i,0,n) if (i != x) {
    if (wins(x, i) != x) {
      cout << -1 << endl;
      return;
    }
  }
  cout << x+1 << endl;
}


int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t; cin >> t;
  while(t--) solve();
}