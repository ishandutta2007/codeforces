#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vi a(n);
  rep(i,0,n) cin>>a[i];

  function<int(vi,int)> solve = [&](vi v, int bit) {
    if(sz(v) <= 2) return sz(v);
    if(bit < 0) assert(false);
    vi a,b;
    rep(i,0,sz(v)){
      if(v[i]>>bit&1) a.push_back(v[i]);
      else b.push_back(v[i]);
    }
    int A = solve(a, bit-1);
    int B = solve(b, bit-1);
    if(sz(b)) ++A;
    if(sz(a)) ++B;
    return max(A,B);
  };
  int x = solve(a,31);
  cout << sz(a)-x << endl;
}