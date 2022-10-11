#include <bits/stdc++.h>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);

ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/
using namespace std;

const double PI = 2 * acos(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<ll>> matrix;

int last;

map<int, int> val;
map<int, int> uf;
map<int, int> ufsz;
int uffind(int x) {
  if(!uf.count(x)) {
    uf[x] = x;
    ufsz[x] = 1;
    return x;
  }
  return uf[x] == x ? x : (uf[x] = uffind(uf[x]));
}

map<int, vector<pii>> edges;
// (x) -> (y, w)
int q[1000000];
void ufmerge(int xx, int yy, int w) {
  int x = uffind(xx);
  int y = uffind(yy);
  if(x == y) return;
  if(ufsz[x] < ufsz[y]) {
    swap(x, y);
    swap(xx, yy);
  }
  set<int> seen;
  // merge y into x
  val[yy] = val[xx] ^ w;
  int ql = 0;
  int qr = 0;
  q[qr++] = yy;
  while(ql < qr) {
    int curr = q[ql++];
    // printf("updating %d\n", curr);
    if(!edges.count(curr)) continue;
    for(pii out: edges[curr]) {
      // printf("considering %d, find %d\n", out.first, uffind(out.first));
      if(uffind(out.first) != x && !seen.count(out.first)) {
        seen.insert(out.first);
        val[out.first] = val[curr] ^ out.second;
        q[qr++] = out.first;
      }
    }
  }
  ufsz[x] += ufsz[y];
  uf[y] = x;
  ufsz.erase(y);
  /*
  printf("UNION FIND\n");
  for(auto out: uf) {
    printf("%d %d\n", out.first, uffind(out.first));
  }
  printf("UNION FIND SIZE\n");
  for(auto out: ufsz) {
    printf("%d %d\n", out.first, out.second);
  }
  printf("VALUES\n");
  for(auto out: val) {
    printf("%d %d\n", out.first, out.second);
  }
  printf("\n");
  */
}

int query(int l, int r, bool upd);
void update(int l, int r, int x) {
  int ans = query(l, r, false);
  if(ans != -1) return;
  ufmerge(l-1, r, x);
  edges[l-1].push_back({r, x});
  edges[r].push_back({l-1, x});
}

int query(int l, int r, bool upd) {
  int ret = -1;
  if(uffind(l-1) == uffind(r)) {
    ret = val[l-1] ^ val[r];
  }
  if(upd) {
    if(ret == -1) last = 1;
    else last = ret;
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  last = 0;
  while(n--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      int lp, rp, xp;
      scanf("%d%d%d", &lp, &rp, &xp);
      int l = lp ^ last;
      int r = rp ^ last;
      int x = xp ^ last;
      if(l > r) swap(l, r);
      l++;
      r++;
      update(l, r, x);
    }
    else {
      assert(t == 2);
      int lp, rp;
      scanf("%d%d", &lp, &rp);
      int l = lp ^ last;
      int r = rp ^ last;
      l++;
      r++;
      if(l > r) swap(l, r);
      printf("%d\n", query(l, r, true));
    }
  }
}