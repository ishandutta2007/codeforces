#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


vi topoSort(const vector<vi>& gr) {
  vi indeg(sz(gr)), ret;
  trav(li, gr) trav(x, li) indeg[x]++;
  queue<int> q; // use priority queue for lexic. smallest ans.
  rep(i,0,sz(gr)) if (indeg[i] == 0) q.push(-i);
  while (!q.empty()) {
    int i = -q.front(); // top() for priority queue
    ret.push_back(i);
    q.pop();
    trav(x, gr[i])
      if (--indeg[x] == 0) q.push(-x);
  }
  return ret;
}


void bad(string s = "-1") {
  cout << s << endl;
  exit(0);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<vi> g(n), rg(n);
  rep(i,0,m) {
    int a,b;
    cin>>a>>b;
    --a,--b;
    g[a].emplace_back(b);
    rg[b].emplace_back(a);
  }
  vi ord = topoSort(g);
  if(sz(ord) < n) bad();

  auto go = [&](vi &reach, auto& g) {
    for(int x : ord) {
      reach[x] = x;
      for(int y : g[x]) reach[x] = min(reach[x], reach[y]);
    }
  };

  vi l(n), r(n);
  go(l, rg);
  reverse(all(ord));
  go(r, g);

  string ans;
  rep(i,0,n) ans += "EA"[(l[i] == i && r[i] == i)];
  int k = count(all(ans), 'A');
  cout << k << endl;
  cout << ans << endl;
}