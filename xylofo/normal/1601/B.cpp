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
  int n;
  cin >> n;
  vi a(n+1), b(n+1);
  rep(i,1,n+1) cin>>a[i];
  rep(i,1,n+1) cin>>b[i];
  vi nxt(n+2);
  iota(all(nxt),0);
  function<int(int)> go = [&](int x) {
    if(nxt[x] == x) return x;
    else return nxt[x] = go(nxt[x]);
  };

  vi dad_d(n+1,-1);
  vi dad_x(n+1,-1);
  queue<int> q;
  q.emplace(n);
  dad_x[n] = dad_d[n] = -2;
  while(sz(q)) {
    int x = q.front();
    q.pop();
    if(x == 0) break;
    int y = go(x-a[x]);
    while(y <= x) {
      int z = y + b[y];
      if(dad_x[z] == -1) dad_x[z] = x, dad_d[z] = y, q.emplace(z);
      nxt[y] = y+1;
      y = go(y);
    }
  }
  if(dad_x[0] == -1) {
    cout << -1 << endl;
    return 0;
  }
  vi pth;
  int x = 0;
  while(x != n) {
    pth.emplace_back(dad_d[x]);
    x = dad_x[x];
  }

  reverse(all(pth));
  cout << sz(pth) << endl;
  rep(i,0,sz(pth)) cout << pth[i] << " ";
  cout << endl;
}