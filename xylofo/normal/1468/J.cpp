#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


struct UF {
  vi e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b]; e[b] = a;
    return true;
  }
};

void solve(int tc) {
  int n,m;
  ll k;
  cin>>n>>m>>k;
  vector<tuple<ll,int,int>> heavy, light;
  rep(i,0,m) {
    int x,y,w;
    cin>>x>>y>>w;
    --x,--y;
    if(w <= k) light.emplace_back(w,x,y);
    else heavy.emplace_back(w,x,y);
  }

  sort(all(heavy));

  ll ans = 0;

  UF uf(n);
  int comp = n;
  for(auto [w,x,y] : light) {
    if(uf.join(x,y)) --comp;
  }
  if(comp > 1) {
    for(auto [w,x,y] : heavy) {
      if(uf.join(x,y)) {
        --comp;
        ans += w - k;
      }
    }
    assert(comp == 1);
  }
  else {
    ans = 1e18;
    for(auto [w,x,y] : light) ans = min(ans, k - w);
    for(auto [w,x,y] : heavy) ans = min(ans, w - k);
    assert(ans != 1e18);
  }

  cout << ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}