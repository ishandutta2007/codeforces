#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const bool DEB = false;

int main() {
  int n, k;
  cin >> n >> k;
  int K = k;
  if(k == 1) k = 2;
  int siz = k/2;
  int groups = n/siz;
  debug(siz, groups);
  vi alive(n,1);

  vi active(n,0);
  queue<int> S;

  vi _cols(n);
  rep(i,0,n) _cols[i] = rand()%12;
  //if(DEB) debug(_cols);

  int q = 0;
  auto answer = [&](){
    int x = count(all(alive),1);
    cout << "! "  << x << endl;
    if(DEB) {
      set<int> cc;
      rep(i,0,n) cc.emplace(_cols[i]);
      debug(sz(cc));
      assert(sz(cc) == x);
    }
    debug(q, 3*n*n/(2*K));
    assert(q <= 3*n*n/(2*K));
    exit(0);
  };
  auto reset = [&](){
    while(sz(S)) {
      int a = S.front();
      S.pop();
      active[a] = 0;
    }
    if(DEB) return;
    cout << "R" << endl;
  };
  auto _query = [&](int x){
    ++q;
    bool ex = false;
    if(DEB) rep(i,0,n) if(active[i] && _cols[i] == _cols[x]) ex = true;

    ++active[x];
    S.emplace(x);
    if(sz(S) > K) {
      --active[S.front()];
      S.pop();
    }
    assert(0 <= x && x < n);

    if(DEB) return ex;


    cout << "? "  << x+1 << endl;
    string c;
    cin>>c;
    assert(c == "N" || c == "Y");
    return c == "Y";
  };
  auto query = [&](int x){
    if(!alive[x]) return;
    assert(!active[x]);
    if(_query(x)) alive[x] = false;
  };
  auto query_group = [&](int b){
    rep(i,b*siz,(b+1)*siz) query(i);
  };

  // paths s, s-1, s+1, s-2, s+2 ...
  // covers disjoint edges for different s
  rep(s,0,groups/2) {
    reset();
    rep(i,0,groups) {
      int r = i%2==0 ? 1 : -1;
      int x = ((s+r*((i+1)/2))%groups + groups)%groups;
      query_group(x);
    }
  }

  answer();
}