#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


bool smin(auto &a, auto&& b) { return (b < a) ? (a = b, 1) : 0; } 
bool smax(auto &a, auto&& b) { return (a < b) ? (a = b, 1) : 0; } 

template<class T>
auto dijkstra(int source, vector<vector<int>> &g) {
  int n = g.size();
  vector<T> dist(n, numeric_limits<T>::max());
  priority_queue<pair<T,int> > pq;
  dist[source] = 0;
  pq.emplace(0,source);
  while(!pq.empty()) {
    T d; int x;
    tie(d,x) = pq.top();
    d = -d;
    pq.pop();
    if(d > dist[x]) continue;
    for(auto y : g[x]) {
      if(dist[y] > d + 1) {
        dist[y] = d + 1;
        pq.emplace(-dist[y], y);
      }
    }
  }
  return dist;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n, m, k;
  cin >> n >> m >> k;
  vi good(n,0);
  rep(i,0,k) {
    int x;
    cin>>x;
    --x;
    good[x] = 1;
  }
  vector<vi> g(n);
  bool xtr = 0;
  rep(i,0,m) {
    int x, y;
    cin>>x>>y;
    --x,--y;
    g[x].push_back(y);
    g[y].push_back(x);
    if(good[x] && good[y]) xtr = true;
  }
  auto distS = dijkstra<int>(0,g);
  auto distT = dijkstra<int>(n-1,g);

  ll ans = 0;
  if(xtr) ans = distS[n-1];

  set<pii> s;
  vector<pii> v;
  rep(i,0,n) if(good[i]) {
    s.emplace(distT[i], i);
    v.emplace_back(distS[i], i);
  }
  sort(all(v));
  v.pop_back();
  for(auto [ds,x] : v) {
    s.erase(pii(distT[x], x));
    auto [dt,y] = *s.rbegin();
    ll cur = min(ds + dt + 1, distS[n-1]);
    smax(ans, cur);
  }
  cout << ans << endl;
}