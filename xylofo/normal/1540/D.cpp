//#pragma GCC target("avx,avx2")
//#pragma GCC optimize("Ofast")


#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;


const int SZ = 1e5+10;
struct FT {
  int s[SZ];
  //vector<int> s;
  //FT(int n) : s(n) {}
  int N;
  void init(int n) { fill(s,s+n, 0); N = n; } // { s.resize(n); }
  void update(int pos, int dif) { // a[pos] += dif
    for (; pos < N; pos |= pos + 1) s[pos] += dif;
  }
  int query(int pos) { // sum of values in [0, pos)
    int res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos-1];
    return res;
  }
  int lower_bound(int sum) {// min pos st sum of [0, pos] >= sum
    // Returns n if no sum is >= sum, or -1 if empty sum is.
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= N && s[pos + pw-1] < sum)
        pos += pw, sum -= s[pos-1];
    }
    return pos;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vi larger(n);
  rep(i,0,n) {
    cin>>larger[i];
    //larger[i] = i;
  }

  const int MAGIC = 550; // ~ sqrt n

  struct block {
    int lo = 1e9, hi = -1e9;
    vi ans;
    FT fw;
  };


  vi where(n);
  rep(i,0,n) where[i] = i/MAGIC;
  vector<block> blocks(where.back()+1);
  rep(i,0,n) blocks[where[i]].hi = i+1;
  for(int i = n; i--; ) blocks[where[i]].lo = i;

  auto fix = [&](block &b, int HI) {
    rep(i,b.lo,HI+1) b.fw.update(b.ans[i-b.lo],+1); // restore fenwick tree

    for(int i = HI; i >= b.lo; --i) {
      int idx = i - larger[i];
      // want idx smallest which is free?
      int q = b.fw.lower_bound(idx+1);
      //assert(q != -1 && q != b.hi);
      b.fw.update(q,-1);
      b.ans[i-b.lo] = q;
    }
  };

  for(auto& b : blocks) {
    b.ans.resize(b.hi-b.lo,0);
    b.fw.init(b.hi);
    rep(q,0,b.hi) b.fw.update(q,+1);
    for(int q : b.ans) b.fw.update(q,-1); // dummy updates
    fix(b, b.hi-1);
  }

  auto update = [&](int i, int x) {
    larger[i] = x;
    fix(blocks[where[i]],i);
  };

  auto query = [&](int i) {
    auto &b = blocks[where[i]];
    int q = b.ans[i-b.lo];
    rep(bi, where[i]+1, sz(blocks)) {
      q = blocks[bi].fw.lower_bound(q+1);
      //assert(q != -1 && q != blocks[bi].hi);
    }
    return q;
  };


  int q;
  cin>>q;
  rep(_,0,q) {
    int t,i;
    cin>>t>>i;
    //t = rand()%2+1;
    //i = rand()%n + 1;

    --i;
    if(t == 1) {
      int x;
      //x = rand()%(i+1);
      cin>>x;
      update(i,x);
    }
    else if(t == 2) {
      int ans = query(i);
      cout << ans+1 << "\n";
    }
    else assert(false);
  }
}