#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 3e6+5;
using cd = complex<double>;
const double PI = acos(-1);
ll m = 1e9 + 9;
ll get(ll b, ll p, ll mod) {
  if(p==0) return 1LL;
  ll x = get(b, p/2, mod);
  x =x*x%mod;
  if(p%2) x = x*b%mod;
  return x;
}
ll MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q; cin >> n >> q;
  string s0, t; cin >> s0 >> t;
  string l = s0;
  vector<vector<pair<string, int>>> store(n+1);
  vector<string> query(q);
  for(int i=0;i<q;i++) {
    int x; cin >> x;
    cin >> query[i];
    store[x].push_back({query[i], i});
  }
  vector<vector<ll>> num(q, vector<ll>(26));
  int x = 0;
  while(l.length() <= 1000000) {
    l = l + t[x++] + l;
    if(x >= n) {
      t += "a";
    }
  }
  vector<vector<ll>> hash(q+1);
  const int p = 31;
  vector<ll> tpow(MX), inv(MX);
  tpow[0] = 1LL;
  inv[0] = 1LL;
  for(int i=1;i<MX;i++) {
    tpow[i] = tpow[i-1]*p%m;
  }
  inv[MX-1] = get(tpow[MX-1], m-2, m);
  for(int i=MX-2;i>0;i--) {
    inv[i] = inv[i+1]*p%m;
  }
  for(int i=0;i<q;i++) {
    hash[i].resize(query[i].length() + 1);
    hash[i][0] = 0LL;
    for(int j=0;j<query[i].length();j++) {
      int c = query[i][j] - 'a';
      hash[i][j+1] =(hash[i][j] + c * tpow[j]) % m;
    }
    if(hash[i].back() < 0) hash[i].back() += m;
  }
  hash.back().resize(l.length() + 1);
  hash.back()[0] = 0LL;
  for(int j=0;j<l.length();j++) {
    int c = l[j] - 'a';
    hash.back()[j+1] = (hash.back()[j] + c * tpow[j]) % m;
  }
  vector<vector<bool>> work(q);
  for(int i=0;i<q;i++) {
    work[i].resize(query[i].length());
    for(int j=0;j<query[i].length();j++) {
      int c = query[i][j] - 'a';
      //j char before c, n-j-1 after c
      ll left, right;
      left = hash.back().back() - hash.back()[l.length()-j];
      left %= m;
      left *= inv[l.length()-j];
      left %= m;
      right = hash.back()[query[i].length()-j-1];
      ll curr = left + c*tpow[j] + right*tpow[j+1];
      curr %= m;
      if(curr < 0) curr += m;
      if(curr == hash[i].back()) {
        ++num[i][c];
        work[i][j] = true;
      }
      else {
        work[i][j] = false;
      }
    }
  }
  vector<ll> ans(q);
  vector<vector<ll>> freq(q, vector<ll>(x+1));
  for(int i=0;i<=min(n, x) ;i++) {
    for(int j=0;j<q;j++) {
      if(i == 0) {
        for(int k=0;k<s0.length();k++) {
          if(k+query[j].length() <= s0.length()) {
            ll x = hash.back()[k+query[j].length()] - hash.back()[k];
            x %= m;
            x *= inv[k];
            x %= m;
            if(x < 0) x += m;
            if(x == hash[j].back()) {
              ++freq[j][i];
            }
          }
        }
      }
      else {
        freq[j][i] = 2*freq[j][i-1];
        for(int k=0;k<query[j].length();k++) {
          int c = t[i-1]-'a';
          if(query[j][k]-'a' == c && k <= s0.length() && (query[j].length() <= s0.length() || k >= query[j].length() - s0.length()-1) && work[j][k]) {
            ++freq[j][i];
          }
        }
        freq[j][i] %= MOD;
      }
    }
    if(i>0)
      s0 = s0 + t[i-1] + s0;
    for(pair<string, int> qu : store[i]) {
      ans[qu.s] = freq[qu.s][i];
      if(ans[qu.s] < 0) ans[qu.s] += MOD;
    }
  }
  vector<ll> twopow(MX);
  twopow[0] = 1LL;
  vector<ll> invtwo(MX);
   invtwo[0] = 1LL;
  for(int i=1;i<MX;i++) {
    twopow[i] = twopow[i-1]*2 % MOD;
  }
  invtwo[MX-1] = get(twopow[MX-1], MOD-2, MOD);
  for(int i=MX-2;i>0;i--) {
    invtwo[i] = 2*1LL*invtwo[i+1]%MOD;
  }
  vector<ll> sum(26);
  for(int i=x+1;i<=n;i++) {
    //answer all queries with i
    sum[t[i-1]-'a'] += invtwo[i];
    sum[t[i-1]-'a'] %= MOD;
    for(pair<string, int> qu : store[i]) {
      for(int j=0;j<26;j++) {
        ans[qu.s] += num[qu.s][j]*1LL*(twopow[i])%MOD*sum[j]%MOD;
        ans[qu.s]%=MOD;
      }
      ans[qu.s] += freq[qu.s][x]*1LL*twopow[i-x]%MOD;
      ans[qu.s] %= MOD;
      if(ans[qu.s] < 0) ans[qu.s] += MOD;
    }
  }
  for(int i=0;i<q;i++) {
    cout << ans[i] << "\n";
  }
}