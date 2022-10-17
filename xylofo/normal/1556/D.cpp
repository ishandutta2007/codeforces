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

int main() {
  int n, k;
  cin >> n >> k;

  vi V(n);
  rep(i,0,n) V[i] = rand()%123;

  auto OR = [&](int i, int j) {
    //return V[i] bitor V[j];
    cout << "or " << i+1 << " " << j+1 << endl;
    int res;
    cin>>res;
    return res;
  };
  auto AND = [&](int i, int j) {
    //return V[i] bitand V[j];
    cout << "and " << i+1 << " " << j+1 << endl;
    int res;
    cin>>res;
    return res;
  };
  auto XOR = [&](int i, int j) {
    return OR(i,j)^AND(i,j);
  };

  vector<vi> three(3,vi(32,-1));
  auto st = [&](int i, int bit, int v) {
    if(three[i][bit] == -1) three[i][bit] = v;
    assert(three[i][bit] == v);
  };
  auto go = [&](int i, int j) {
    int a = AND(i,j);
    int b = OR(i,j);
    rep(bit,0,32) {
      int band = (a>>bit&1);
      int bor = (b>>bit&1);
      if(band == bor) st(i,bit,band), st(j,bit,band);
    }
  };
  go(0,1); go(0,2); go(1,2);

  debug(three);
  rep(i,0,3) rep(bit,0,sz(three[0])) if(three[i][bit] == -1) {
    assert(three[(i+1)%3][bit] != -1);
    three[i][bit] = !three[(i+1)%3][bit];
  }
  debug(three);

  vi v(n);
  rep(i,0,3) {
    rep(bit,0,sz(three[0])) {
      assert(three[i][bit] != -1);
      v[i] += three[i][bit]<<bit;
    }
  }
  rep(j,3,n) v[j] = XOR(0,j) ^ v[0];

  debug(V);
  debug(v);

  sort(all(v));
  cout << "finish " << v[k-1] << endl;

}