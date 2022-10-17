#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n;
std::vector<PII> A;

VI solve(){
  std::vector<std::vector<PII> > ev(n);
  FOR(i, n) ev[A[i].X].push_back(MP(A[i].Y, i));
  std::priority_queue<PII> que;

  VI ret;
  FOR(i, n){
    TRAV(e, ev[i]){
      que.push(MP(-e.X, e.Y));
    }
    int cur = que.top().Y;
    assert(-que.top().X >= i);
    que.pop();
    ret.push_back(cur);
  }

  return ret;
}

const int INF = 1000000066;
struct Tree{
  int BOTTOM;
  std::vector<PII> t;
  void build(int sz){
    BOTTOM = 1;
    while(BOTTOM < sz) BOTTOM *= 2;
    t.resize(BOTTOM*2, MP(INF, -1));
  }
  void set(int v, int a){
    v += BOTTOM;
    t[v] = MP(a, v-BOTTOM);
    while(v > 1){
      v>>=1;
      t[v] = std::min(t[v<<1], t[(v<<1)+1]);
    }
  }

  PII query(int a, int b){
    a += BOTTOM;
    b += BOTTOM+1;
    PII ret = MP(INF, -1);
    while(a < b){
      if(a&1) ret = std::min(ret, t[a++]);
      if(b&1) ret = std::min(ret, t[--b]);
      a>>=1;b>>=1;
    }
    return ret;
  }
};


VI xd(VI a){
  VI ret(n);
  FOR(i, n) ret[a[i]] = i;
  return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
  std::cin >> n;
  A.resize(n);
  FOR(i, n) std::cin >> A[i].X >> A[i].Y, A[i].X--, A[i].Y--;

  auto fs = solve();
  /*
  FOR(i, n) A[i].X = n-1-A[i].X, A[i].Y = n-1-A[i].Y, std::swap(A[i].X, A[i].Y);
  auto sc = solve();
  std::reverse(sc.begin(), sc.end());
  FOR(i, n) A[i].X = n-1-A[i].X, A[i].Y = n-1-A[i].Y, std::swap(A[i].X, A[i].Y);

  fs = xd(fs);
  sc = xd(sc);

  if(fs != sc){
    std::cout << "NO\n";
    TRAV(i, sc) std::cout << i+1 << " ";
    std::cout << "\n";
    TRAV(i, fs) std::cout << i+1 << " ";
    return 0;
  }

  fs = xd(fs);
  */

  Tree tree;
  tree.build(n);
  FOR(i, n) tree.set(i, A[fs[i]].X);

//  TRAV(i, fs) std::cout << i << " ";
  //std::cout << std::endl;

  VI sc;
  FOR(i, n){
    auto xd = tree.query(i+1, A[fs[i]].Y);
    if(xd.X <= i){
      int v = xd.Y;
      sc = fs;
      std::swap(sc[i], sc[v]);
      break;
    }
  }

  if(!sc.empty()){
    std::cout << "NO\n";
    TRAV(i, xd(fs)) std::cout << i+1 << " ";
    std::cout << "\n";
    TRAV(i, xd(sc)) std::cout << i+1 << " ";
  }else{
    std::cout << "YES\n";
    TRAV(i, xd(fs)) std::cout << i+1 << " ";
  }

	return 0;
}