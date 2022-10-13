#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 2e5+5;
int parent[MX], sz[MX];
int find(int x) {
  if(x == parent[x]) return x;
  return parent[x] = find(parent[x]);
}
ll ans;
void merge(int a, int b) {
  int x = find(a), y = find(b);
  if(x == y) return;
  if(sz[x] < sz[y])
    swap(x, y);
  ans -= sz[x] * 1LL * (sz[x] - 1);
  ans -= sz[y] * 1LL * (sz[y] - 1);
  sz[x] += sz[y];
  parent[y] = x;
  ans += sz[x] * 1LL * (sz[x] - 1);
}
struct edge {
  int u, v, w; 
  edge(int a, int b, int c):
    u(a), v(b), w(c)
  {

  }
};
ll ret[MX];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n, m; cin >> n >> m;
  vector<edge> in;
  vector<pair<int, int> > qu;
  for(int i = 0; i < n - 1; i++) {
    int u, v, w; cin >> u >> v >> w;
    --u, --v;
    in.push_back(edge(u, v, w));
  }
  for(int i = 0; i < m; i++) {
    int q; cin >> q;
    qu.push_back({q, i});
  }
  sort(in.begin(), in.end(),
      [](const edge &a, const edge &b) -> bool
      {
        return a.w > b.w;
      });
  sort(qu.begin(), qu.end());
  for(int i = 0; i < n; i++) {
    sz[i] = 1, parent[i] = i;
  }
  for(auto &it : qu) {
    while(!in.empty() && in.back().w <= it.f) {
      merge(in.back().u, in.back().v);
      in.pop_back();
    }
    ret[it.s] = ans / 2;
  }
  for(int i = 0; i < m; i++) {
    cout << ret[i] << " ";
  }
}