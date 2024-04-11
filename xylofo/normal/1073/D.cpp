#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define all(c) (c).begin(), (c).end()
#define debug(x) cerr << #x << " = " << x << endl
#define eb emplace_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;


struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) { // a[pos] += dif
    for (; pos < s.size(); pos |= pos + 1) s[pos] += dif;
  }
  ll query(int pos) { // sum of values in [0, pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos-1];
    return res;
  }
  ll query(int low, int pos) { 
    return query(pos) - query(low);
  }
  int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
    // Returns n if no sum is >= sum, or -1 if empty sum is.
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1) {
      if (pos + pw <= s.size() && s[pos + pw-1] < sum)
        pos += pw, sum -= s[pos-1];
    }
    return pos;
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  ll t;
  cin>>n>>t;
  vector<ll> v(n);
  FT alive(2*n), sum(2*n);
  rep(i,0,n) {
    int x;
    cin>>x;
    v[i] = x;
    alive.update(i+0,1);
    alive.update(i+n,1);
    sum.update(i+0,x);
    sum.update(i+n,x);
  }
  ll ans = 0;
  int pos = 0;
  while(alive.query(n) > 0) {
    ll q = sum.query(pos, pos+n);
    ll al = alive.query(pos, pos+n);
    ll circ = t/q;
    t -= q*circ;
    ans += circ*al;
    ll q0 = sum.query(pos);
    int idx = sum.lower_bound(q0 + t + 1);
    int i = idx % n;
    alive.update(i+0, -1);
    alive.update(i+n, -1);
    sum.update(i+0, -v[i]);
    sum.update(i+n, -v[i]);
    t -= sum.query(pos, idx);
    ans += alive.query(pos, idx);
    pos = i;
  }
  cout << ans << endl;
  return 0;
}