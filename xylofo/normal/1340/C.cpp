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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vi d(m);
  trav(x, d) cin >> x;
  sort(all(d));
  int G,R;
  cin>>G>>R;
  vector<vector<ll> > dist(m,vector<ll>(G,1e18));
  queue<pii> q,nq;
  dist[0][0] = 0;
  q.emplace(0,0);
  ll t = 0;
  while(sz(q) + sz(nq)) {
    if(q.empty()) { swap(q, nq); t += G+R; }
    auto [x,s] = q.front();
    q.pop();
    auto go = [&](int y) {
      int ss = s + abs(d[x] - d[y]);
      if(ss < G && smin(dist[y][ss], t + ss))
        q.emplace(y,ss);
      if(ss == G && smin(dist[y][0], t + G+R))
        nq.emplace(y,0);
    };
    if(x-1 >= 0) go(x-1);
    if(x+1 < m) go(x+1);
  }
  dist[m-1][0] -= R;
  auto ans = *min_element(all(dist[m-1]));
  if(ans >= 1e17) ans = -1;
  cout << ans << endl;
}