#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

#define WIN do { cout << "White" << "\n"; return; } while(0)
#define DRAW do { cout << "Draw" << "\n"; return; } while(0)

void solve(int tc) {
  int n;
  cin >> n;
  vector<vi> g(n);
  rep(i,1,n) {
    int x,y;
    cin>>x>>y;
    --x,--y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  string s;
  cin>>s;
  int whites = count(all(s),'W');

  if(n <= 2) DRAW;
  if(n == 3 && whites <= 1) DRAW;
  if(n == 3 && whites >= 2) WIN;

  assert(n > 3);

  int deg3 = 0;
  rep(i,0,n) {
    if(sz(g[i]) >= 2 && s[i] == 'W') WIN;
    if(sz(g[i]) >= 4) WIN;
    if(sz(g[i]) == 3) {
      ++deg3;
      int a = g[i][0];
      int b = g[i][1];
      int c = g[i][2];
      int t = (sz(g[a])>1) + (sz(g[b])>1) + (sz(g[c])>1);
      if(t > 1) WIN;
      if(s[a] == 'W') WIN;
      if(s[b] == 'W') WIN;
      if(s[c] == 'W') WIN;
    }
  }
  assert(whites + deg3 <= 2);
  if(whites == 2 || deg3 == 2) {
    if(n%2 == 1) WIN;
    else DRAW;
  }
  if(whites == 1 && deg3 == 1) {
    if(n%2 == 0) WIN;
    else DRAW;
  }

  DRAW;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) try { solve(t); } catch(int s) {};
}