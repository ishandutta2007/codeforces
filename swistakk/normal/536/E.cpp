//#include "HLDWithRev.h"

#include <bits/stdc++.h>
#define PB push_back
#define int long long
#define SZ(x) ((int)(x).size())
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

// Wojtek Nadara
// Tested here: 
// This version allows to keep an order of edges/vertices on a path
// If we are dealing with problems like sum/max on interval then it doesn't matter,
// but if we are solving subword with maximum sum then we need to keep that order which demands reversing of one half of path
// Adjusting it to another version boils down just to adjusting tree's operations (and possibly HLD.Upd and HLD.Query slightly)

struct Node {
  int left_len, mid_val, right_len, whole;
  void Rev() {
    if (!whole) {
      swap(left_len, right_len);
    }
  }
  int Eval();
};

Node Merge(Node a, Node b);

struct HLD {
  struct Tree {
    Tree(int nn) {
      M = 1;
      while (M <= nn) {
        M *= 2;
      }
      node.resize(2 * M + 5);
    }
    Node ReadNode(int a, int b) {
      a += M;
      b += M;
      if (a == b) { return node[a]; }
      Node left = node[a];
      Node right = node[b];
      while (a / 2 != b / 2) {
        if (a % 2 == 0) {
          left = Merge(left, node[a + 1]);
        }
        if (b % 2 == 1) {
          right = Merge(node[b - 1], right);
        }
        a /= 2;
        b /= 2;
      }
      return Merge(left, right);
    }
    
    void Upd(int a) {
      a += M;
      node[a] = {1, 0, 0, 1}; // new value of vertex, will vary wrt different tasks
      a /= 2;
      while (a) {
        node[a] = Merge(node[2 * a], node[2 * a + 1]);
        a /= 2;
      }
    }
    
    int M;
    vector<Node> node;
  };
  
public:
  /* Start of general part */
  HLD(VVI& slo_, int n_, int on_vertices_, int root_ = 1) {
    n = n_;
    on_vertices = on_vertices_;
    assert(SZ(slo_) >= n_);
    slo = slo_;
    path.resize(n + 5);
    wh_path.resize(n + 5);
    ord.resize(n + 5);
    sz.resize(n + 5);
    pre.resize(n + 5);
    par.resize(n + 5);
    path_pot.resize(n + 5);
    root = root_;
    path_cnt = 0;
    d = 0;
    Dfs(root);
    tree.PB(Tree(1));
    for (int p = 1; p <= path_cnt; p++) {
      tree.PB(Tree(SZ(path[p])));
    } 
  }
    
  bool IsAnc(int v, int u) {
    return pre[v] <= pre[u] && pre[u] <= pre[v] + sz[v] - 1;
  }
  
  int n, path_cnt, d, root, on_vertices;
  VVI slo, path;
  vector<Tree> tree;
  VI wh_path, ord, sz, pre, par, path_pot;

  void Dfs(int v) {
    sz[v] = 1;
    d++;
    pre[v] = d;
    int largest_son = 0;
    for (auto nei : slo[v]) {
      if (pre[nei]) { continue; }
      par[nei] = v;
      Dfs(nei);
      sz[v] += sz[nei];
      if (sz[nei] > sz[largest_son]) {
        largest_son = nei;
      }
    }
    if (largest_son == 0) {
      path_cnt++;
      path[path_cnt].PB(v);
      wh_path[v] = path_cnt;
    } else {
      wh_path[v] = wh_path[largest_son];
      ord[v] = ord[largest_son] + 1;
      path[wh_path[v]].PB(v);
    }
  }
  
  struct Info {
    int path, a, b;
  };
  
  vector<vector<Info>> GetPath(int a, int b) {
    vector<Info> res[2];
    for (int tr = 0; tr < 2; tr++) {
      while (1) {
        int p = wh_path[a];
        int mi = ord[a];
        int ma = SZ(path[p]) - 1;
        if (IsAnc(path[p].back(), b)) {
          int kl = mi;
          int kp = ma;
          while (kl <= kp) {
            int aktc = (kl + kp) / 2;
            if (IsAnc(path[p][aktc], b)) {
              kp = aktc - 1;
              ma = aktc;
            } else {
              kl = aktc + 1;
            }
          } 
        }
        res[tr].PB({p, mi, ma});
        if (IsAnc(path[p].back(), b)) {
          break;
        }
        a = par[path[p].back()];
      }
      
      // removing occurance of LCA
      if (tr == 1 || !on_vertices) { 
        if (res[tr].back().a == res[tr].back().b) {
          res[tr].pop_back();
        } else {
          res[tr].back().b--;
        }
      }
      swap(a, b);
    }
    return {res[0], res[1]};
  }
  
  /* End of general part */
  
  /* Start of less general part */
  //Update on path a<->b
  //Currently this is pretty weird, cause I needed to update one edge and did this in this weird way
  void Upd(int a, int b) {
    auto sub = GetPath(a, b);
    for (auto subpaths : sub) {
      for (auto tr : subpaths) {
        tree[tr.path].Upd(tr.a);
      }
    }
  }
  //Query on path a<->b
  int Query(int a, int b) {
    auto subpaths = GetPath(a, b);
    // here put default values ->
    Node no[2] = {{0, 0, 0, 1}, {0, 0, 0, 1}};
    for (int wh = 0; wh < 2; wh++) {
      for (auto tr : subpaths[wh]) {
        no[wh] = Merge(no[wh], tree[tr.path].ReadNode(tr.a, tr.b));
      }
    }
    no[1].Rev();
    Node R = Merge(no[0], no[1]);
    return R.Eval();
  }
  /* End of less general part */
};


#define ALL(x) (x).begin(), (x).end()
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
const int N = 2e5 + 5;
int f[N];
Node Merge(Node a, Node b) {
  if (a.whole && b.whole) {
    return {a.left_len + b.left_len, 0, 0, 1};
  }
  if (a.whole) {
    return {a.left_len + b.left_len, b.mid_val, b.right_len, 0};
  }
  if (b.whole) {
    return {a.left_len, a.mid_val, a.right_len + b.left_len, 0};
  }
  return {a.left_len, a.mid_val + b.mid_val + f[a.right_len + b.left_len], b.right_len, 0};
}
int Node::Eval() {
  return mid_val + f[left_len] + f[right_len];
}
VVI slo;
struct Q {
  int cost, a, b, type;
  bool operator<(const Q& q) const {
    if (cost != q.cost) { return cost > q.cost; }
    return type < q.type;
  }
};
int ans[N];

#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, q);
  slo.resize(n + 5);
  vector<Q> qs;
  for (int i = 1; i <= n - 1; i++) {
    cin>>f[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    make3(int, a, b, c);
    slo[a].PB(b);
    slo[b].PB(a);
    qs.PB({c, a, b, 0});
  }
  HLD hld(slo, n, 0);
  for (int i = 1; i <= q; i++) {
    make3(int, a, b, c);
    qs.PB({c, a, b, i});
  }
  sort(ALL(qs));
  for (auto qq : qs) {
    if (qq.type == 0) {
      hld.Upd(qq.a, qq.b);
    } else {
      ans[qq.type] = hld.Query(qq.a, qq.b);
    }
  }
  for (int i = 1; i <= q; i++) {
    cout<<ans[i]<<"\n";
  }
  return 0;
}