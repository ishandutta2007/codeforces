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
  int n;
  cin >> n;
  vi p(n), ip(n);
  rep(i,0,n) {
    cin>>p[i];
    --p[i];
    ip[p[i]] = i;
  }
  vi vis(n);
  UF uf(n);
  vector<vi> cyc;
  rep(i,0,n) if(!vis[i]) {
    int x = i;
    vi c;
    do {
      c.emplace_back(x);
      vis[x] = true;
      x = p[x];
    } while(x != i);
    cyc.emplace_back(c);
    for(int x : c) uf.join(x,c[0]);
  }
  debug(cyc);

  vi pp = p;
  debug(p);
  rep(i,0,n-1) {
    if(!uf.sameSet(i, i+1)) {
      uf.join(i,i+1);
      debug(i, i+1, pp[ip[i]], pp[ip[i+1]]);
      swap(pp[ip[i]], pp[ip[i+1]]);
    }
  }
  debug(pp);

  ll cost1 = 0, cost2 = 0;
  rep(i,0,n) cost1 += abs(pp[i] - p[i]);

  vi inv(n);
  rep(i,0,n) inv[pp[i]] = i;

  vi q(n,0);
  int x = 0;
  rep(i,0,n) {
    x = inv[q[i]];
    q[(i+1)%n] = x;
  }
  assert(q[0] == 0);
  debug(q);
  //rep(i,0,n) q[i] = pp[i];
  //rep(i,0,n) q[i] = (inv[i]+n-1)%n;
  rep(i,0,n) cost2 += abs(q[i] - p[q[(i+1)%n]]);

  debug(cost1, cost2);
  assert(cost1 == cost2);

  rep(i,0,n) cout << q[i]+1 << " ";
  cout << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}