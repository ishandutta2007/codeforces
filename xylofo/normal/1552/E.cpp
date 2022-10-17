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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, k;
  cin >> n >> k;
  vi v(n*k);
  rep(i,0,n*k) cin>>v[i];
  int target = (n+(k-1)-1)/(k-1);
  vi alive(n+1,true);
  vector<pii> ans(n);
  vector<tuple<int,int,int>> todo;
  vi lst(n+1,-1);
  vi vis(n+1,0);
  int T = 99;
  rep(i,0,n*k) {
    if(!alive[v[i]]) continue;
    if(vis[v[i]] != T) {
      vis[v[i]] = T;
      lst[v[i]] = i;
    }
    else {
      todo.emplace_back(v[i],lst[v[i]],i);
      alive[v[i]] = false;
    }

    if(sz(todo) == target) {
      for(auto [c,a,b] : todo) ans[c-1] = {a,b};
      todo.clear();
      ++T;
    }
  }
  assert(count(all(alive),false) == n);
  for(auto [c,a,b] : todo) ans[c-1] = {a,b};
  for(auto [l,r] : ans) cout << l+1 << " " << r+1 << "\n";
}