#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 998'244'353;
ll inv(ll a, ll md) { return 1<a ? md - inv(md%a,a)*md/a : 1; }
ll inv(ll a) { return inv(a, mod); }

vi topoSort(const vector<vi>& gr) {
  vi indeg(sz(gr)), ret;
  for (auto& li : gr) for (int x : li) indeg[x]++;
  queue<int> q;
  rep(i,0,sz(gr)) if (indeg[i] == 0) q.push(-i);
  while (!q.empty()) {
    int i = -q.front();
    ret.push_back(i);
    q.pop();
    for (int x : gr[i]) if (--indeg[x] == 0) q.push(-x);
  }
  return ret;
}

void FST(vector<ll>& a, bool inverse) {
  for (int n = sz(a), step = 1; step < n; step *= 2) {
    for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
      ll &u = a[j], &v = a[j + step];
      tie(u, v) = make_pair((u + v)%mod,(mod + u - v)%mod);
    }
  }
  if(inverse) for (ll& x : a) x = (x * inv(sz(a))) % mod;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<vi> g(n);
  rep(i,0,m) {
    int x,y;
    cin>>x>>y;
    --x,--y;
    g[x].emplace_back(y);
  }

  vi ord = topoSort(g);
  assert(sz(ord) == n);
  reverse(all(ord));

  vi grundy(n,0), reach(n);
  for(int x : ord) {
    for(int y : g[x]) ++reach[grundy[y]];
    while(reach[grundy[x]]) ++grundy[x];
    for(int y : g[x]) --reach[grundy[y]];
  }

  int bits = 1;
  while(bits < n) bits *= 2;

  vector<ll> freq(bits), phi(bits);
  rep(i,0,n) ++freq[grundy[i]];

  rep(i,0,bits) phi[i] = ((mod-freq[i]) * inv(n+1)) % mod;
  phi[0] = (phi[0] + 1) % mod;

  FST(phi, 0);
  rep(i,0,bits) phi[i] = inv(phi[i]);
  FST(phi, 1);

  ll bob = (phi[0] * inv(n+1)) % mod;
  ll alice = (mod + 1 - bob) % mod;

  cout << alice << endl;
}