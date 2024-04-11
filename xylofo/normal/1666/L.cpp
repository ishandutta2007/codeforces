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



void bad(string s = "Impossible") {
  cout << s << endl;
  exit(0);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  int s;
  cin>>s;
  --s;

  vector<vi> g(n);
  rep(i,0,m) {
    int x,y;
    cin>>x>>y;
    --x,--y;
    g[x].emplace_back(y);
  }

  vi pth1(n), pth2(n);
  int pp;
  vi col(n);
  vi par(n,-1);
  vi ppar(n,-1);
  function<void(int,int)> dfs = [&](int x, int p) {
    if(par[x] != -1) {
      if(x != s && col[x] == 2 && ppar[x] != ppar[p]) {
        pp = p;
        throw x;
      }
      return;
    }

    par[x] = p;
    if(p >= 0) ppar[x] = ppar[p];
    if(p == s) ppar[x] = x;
    col[x] = 1;
    for(int y : g[x]) if(y != p) {
      dfs(y,x);
    }
    col[x] = 2;
  };

  try {
    dfs(s,-2);
  }
  catch (int t){
    vi p1, p2;
    p2.emplace_back(t);
    while(t >= 0) { p1.emplace_back(t); t = par[t]; }
    while(pp >= 0) { p2.emplace_back(pp); pp = par[pp]; }
    reverse(all(p1));
    reverse(all(p2));
    cout << "Possible" << endl;
    cout << sz(p1) << endl;
    for(int x : p1) cout << x+1 << " ";
    cout << endl;
    cout << sz(p2) << endl;
    for(int x : p2) cout << x+1 << " ";
    cout << endl;
    exit(0);
  }
  bad();
}