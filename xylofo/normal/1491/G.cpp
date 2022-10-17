#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vi p(n);
  rep(i,0,n) {
    cin>>p[i];
    --p[i];
  }

  vi flip(n);
  vector<pii> ans;
  auto swp = [&](int i, int j) {
    debug(i,j);
    assert(i != j);
    swap(p[i], p[j]);
    swap(flip[i], flip[j]);
    flip[i] ^= 1;
    flip[j] ^= 1;
    ans.emplace_back(i,j);
  };

  vi singletons;
  vector<vi> cyc;
  vi vis(n);
  rep(i,0,n) if(!vis[i]) {
    int x = i;
    vi c;
    do {
      vis[x] = 1;
      c.emplace_back(x);
      x = p[x];
    } while(x != i);
    if(sz(c) > 1) cyc.emplace_back(c);
    else singletons.emplace_back(i);
  }
  debug(cyc);
  debug(singletons);
  //TODO: sort cyc by size?
  while(sz(cyc) >= 2) {
    vi a = cyc.back(); cyc.pop_back();
    vi b = cyc.back(); cyc.pop_back();
    swp(a[0], b[0]);
    while(!flip[p[a[0]]]) swp(a[0], p[a[0]]);
    while(!flip[p[b[0]]]) swp(b[0], p[b[0]]);
    assert(a[0] == p[b[0]] && b[0] == p[a[0]] && flip[a[0]] && flip[b[0]]);
    swp(a[0],b[0]);
    for(int x : a) singletons.emplace_back(x);
    for(int y : b) singletons.emplace_back(y);
  }

  if(sz(cyc)) {
    vi c = cyc.back(); cyc.pop_back();
    if(sz(c) == 2) {
      int x = c[0], y = c[1], z = singletons[0];
      swp(x,z);
      swp(y,z);
      swp(x,z);
    }
    else {
      int x = c[0], y = c[1], z = c[2];
      swp(x,y);
      swp(y,z);
      while(!flip[p[x]]) swp(x, p[x]);
      while(!flip[p[y]]) swp(y, p[y]);
      assert(x == p[y] && y == p[x] && flip[x] && flip[y]);
      swp(x,y);
    }
  }

  cout << sz(ans) << endl;
  for(auto [a,b] : ans)
    cout << a+1 << " " << b+1 << "\n";

  assert(sz(ans) <= n+1);
  rep(i,0,n) assert(p[i] == i);
  rep(i,0,n) assert(!flip[i]);
}