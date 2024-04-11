#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class I>
auto bs(I a, I b, auto&& f) {
  assert(a < b);
  while(a + 1 < b) { // floats: s/1/eps
    I q = a + (b - a)/2;
    (f(q) ? b : a) = q;
  }
  return b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin>>n;
  ll x, sum = 0;
  rep(i,0,n) {
    cin>>x;
    sum += x; 
  }
  ll k = bs<ll>(0,1e13, [&](ll k){
      ll cur = 0;
      rep(i,0,n) cur += k + i;
      return cur > sum;
    });
  --k;
  rep(i,0,n) sum -= k + i;
  assert(0 <= sum && sum < n);
  rep(i,0,sum) cout << k+i+1 << " ";
  rep(i,sum,n) cout << k+i << " ";
  cout << endl;
}