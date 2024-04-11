#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
//#define debug(v) cerr << "[ " << #v << " = " << v << " ]"  << endl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<set<int>> g1(n), g2(n);
  struct edge { int x, y, w, color = -1, dir = 0; };
  vector<edge> ed(m);
  rep(i,0,m) {
    edge& e = ed[i];
    cin>>e.x>>e.y>>e.w;
    //e.y = e.x = rand()%n + 1;
    //while(e.y == e.x) e.y = rand()%n + 1;
    //e.w = rand()%2 + 1;

    --e.x,--e.y;
    if(e.w == 1) {
      g1[e.x].emplace(i);
      g1[e.y].emplace(i);
    }
    else {
      g2[e.x].emplace(i);
      g2[e.y].emplace(i);
    }
  }
  debug("input done");

  int ans = 0;
  rep(x,0,n) if(sz(g1[x])%2 == 1) ++ans;
  debug(ans);

  auto rem = [&](int e) {
    if(ed[e].w == 1) {
      g1[ed[e].x].erase(e);
      g1[ed[e].y].erase(e);
    }
    else {
      g2[ed[e].x].erase(e);
      g2[ed[e].y].erase(e);
    }
  };
  auto walk = [&](int x, int e) {
    assert(x == ed[e].x || x == ed[e].y);
    return x^ed[e].x^ed[e].y;
  };

  auto arb_walk = [&](int x, int c, int dir, auto& g) {
    while(sz(g[x])) {
      int e = *begin(g[x]);
      rem(e);
      assert(ed[e].color == -1);
      ed[e].color = c;
      ed[e].dir = (x == ed[e].x ? dir : -dir);
      x = walk(x,e);
    }
    return x;
  };

  vi vertex_to_path_col2(n,-1);
  vector<pii> path_col2(200+n, {-1,-1});
  int c = 99;
  rep(x,0,n) {
    ++c;
    if(sz(g2[x]) % 2 == 0) continue;
    int y = arb_walk(x, c, 1, g2);
    assert(vertex_to_path_col2[x] == -1);
    assert(vertex_to_path_col2[y] == -1);
    vertex_to_path_col2[x] = vertex_to_path_col2[y] = c;
    path_col2[c] = {x,y};
  }

  debug("walk2 done");

  rep(i,0,n) {
    assert(sz(g2[i])%2 == 0);
    arb_walk(i,9,1,g2);
  }
  debug("walk2 really done");

  vi do_reverse_color(sz(path_col2),0);

  rep(i,0,sz(path_col2)) if(path_col2[i].first != -1) {
    auto [x,y] = path_col2[i];
    // fix direction of this path!
    int z = y;
    while(sz(g1[z]) % 2 == 1) {
      z = arb_walk(z,6,1,g1);
      int pc = vertex_to_path_col2[z];
      if(pc == -1) break;
      if(pc == i) break;
      if(path_col2[pc].second == z) {
        swap(path_col2[pc].first, path_col2[pc].second);
        do_reverse_color[pc] = true;
      }
      assert(path_col2[pc].first == z);
      z = path_col2[pc].second;
    }

    z = x;
    while(sz(g1[z]) % 2 == 1) {
      z = arb_walk(z,6,-1,g1);
      int pc = vertex_to_path_col2[z];
      if(pc == -1) break;
      if(pc == i) break;
      if(path_col2[pc].first == z) {
        swap(path_col2[pc].first, path_col2[pc].second);
        do_reverse_color[pc] = true;
      }
      assert(path_col2[pc].second == z);
      z = path_col2[pc].first;
    }
  }

  debug("walk1 part1");

  rep(x,0,n) {
    if(sz(g1[x])%2 == 1) {
      assert(vertex_to_path_col2[x] == -1);
      arb_walk(x,3,1,g1);
    }
  }
  debug("walk1 part2");

  rep(x,0,n) {
    assert(sz(g1[x])%2 == 0);
    arb_walk(x,7,1,g1);
  }

  debug("walk1 part3");

  rep(x,0,n) assert(sz(g1[x]) == 0 && sz(g2[x]) == 0);

  debug("asserts1");
  vi delta(n);

  cout << ans << endl;

  rep(e,0,m) {
    assert(ed[e].dir);
    bool rev = false;
    if(ed[e].dir == -1) rev = true;
    if(do_reverse_color[ed[e].color]) rev = !rev;
    cout << 1 + rev;
    delta[ed[e].x] += rev ? ed[e].w : -ed[e].w;
    delta[ed[e].y] += rev ? -ed[e].w : ed[e].w;
  }
  cout << endl;

  rep(i,0,n) assert(abs(delta[i]) == 1 || (delta[i]%2+2)%2 == 0);
  rep(i,0,n) if(abs(delta[i]) == 1) debug(i+1);
}