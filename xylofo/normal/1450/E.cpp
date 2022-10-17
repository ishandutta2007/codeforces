#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void bad(string s = "NO") {
  cout << s << endl;
  exit(0);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin>>n>>m;
  const int inf = 1e9;
  vector<vi> d(n, vi(n, inf));
  vector<pii> force;
  vector<pii> force2;
  rep(i,0,m) {
    int x,y,b;
    cin>>x>>y>>b;
    --x,--y;
    d[x][y] = 1;
    d[y][x] = (b ? -1 : 1);
    if(b) force.emplace_back(x,y);
    else force2.emplace_back(x,y);
  }


  rep(i,0,n) d[i][i] = 0;
  rep(k,0,n) rep(i,0,n) rep(j,0,n)
    if (d[i][k] != inf && d[k][j] != inf) {
      auto nd = max(d[i][k] + d[k][j], -inf);
      d[i][j] = min(d[i][j], nd);
    }

  rep(i,0,n) if(d[i][i] < 0) bad();

  int x = 0, y = 0;
  rep(i,0,n) rep(j,0,n)
    if(d[x][y] < d[i][j])
      x = i, y = j;

  vi a(n);
  rep(i,0,n) a[i] = d[x][i];
  for(auto [i,j] : force)
    if(a[j] != a[i]+1) bad();
  for(auto [i,j] : force2)
    if(abs(a[j]- a[i]) != 1) bad();

  cout << "YES" << endl;
  cout << d[x][y] << endl;
  rep(i,0,n) cout << a[i] << " ";
  cout << endl;
}