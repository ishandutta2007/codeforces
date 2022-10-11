#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;

const int BIT_SIZE = 200005;
int bit[BIT_SIZE];
void bitupdate(int idx, int val) {
  idx += 2;
  while(idx < BIT_SIZE) {
    bit[idx] += val;
    idx += idx & -idx;
  }
}
int bitquery(int idx) {
  idx += 2;
  int ret = 0;
  while(idx) {
    ret += bit[idx];
    idx -= idx & -idx;
  }
  return ret;
}


const int MOD = 998244353;
ll modpow(ll b, ll e, ll m) {
  ll r = 1;
  while(e) {
    if(e%2==1) {
      r*=b;
      r%=m;
    }
    b*=b;
    b%=m;
    e/=2;
  }
  return r;
}
ll inv(ll b) {
  return modpow(b, MOD-2, MOD);
}
int l[200005];
int n;
void solve() {
  cin >> n;
  int known = 0;
  ll ret = 0;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    if(l[i] != -1) {
      // known knowns
      int see = bitquery(l[i]);
      ret += known++ - see;
      ret %= MOD;
      bitupdate(l[i], 1);
    }
  }
  int prefixunknown = 0;
  int rununknown = n - known;
  for(int i = 0; i < n; i++) {
    // known unknowns
    if(l[i] != -1) {
      int other = l[i]-1-bitquery(l[i] - 1);
      int other2 = n-known-other;
      // probability of success is other/(n-known)
      // there are rununknown left
      ll inc = rununknown;
      inc *= other;
      inc %= MOD;
      inc *= inv(n-known);
      inc %= MOD;
      ret += inc;
      ret %= MOD;
      inc = prefixunknown;
      inc *= other2;
      inc %= MOD;
      inc *= inv(n-known);
      inc %= MOD;
      ret += inc;
      ret %= MOD;
    }
    else {
      prefixunknown++;
      rununknown--;
    }
  }
  // unknown unknowns
  ll inc = n-known;
  inc *= (n-known-1);
  inc %= MOD;
  inc *= inv(4);
  inc %= MOD;
  ret += inc;
  ret %= MOD;
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  solve();
}