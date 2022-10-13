#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 3e5+5;
int numCover[MX];
ll mod = 998244353;
ll fac[MX], invFac[MX];
ll num[MX][41];
ll inv(ll b, ll p = mod - 2) {
  if(p==0) return 1LL;
  ll x = inv(b, p/2);
  if(p%2) return (((x*x)%mod*b)%mod+mod)%mod;
  else return ((x*x)%mod+mod)%mod;
}
ll choose(int a, int b) {
  if(b<0 || b>a || a<0) return 0LL;
  return fac[a]*1LL*invFac[b]%mod*1LL*invFac[a-b]%mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  int m; cin >> m;
  vector<pair<int, int>> in(n);
  fac[0] = 1LL;
  for(int i=1;i<=n;i++) fac[i] = fac[i-1]*1LL*i%mod;
  for(int i=0;i<=n;i++) invFac[i] = inv(fac[i]);
  for(int i=0;i<n;i++) cin >> in[i].f >> in[i].s;
  vector<pair<int, int>> bad(m);
  for(int i=0;i<m;i++) cin >> bad[i].f >> bad[i].s, --bad[i].f, --bad[i].s;
  for(int i=0;i<n;i++) {
    ++numCover[in[i].s];
    --numCover[in[i].f - 1];
  }
  for(int i=n;i>=0;i--) numCover[i]+=numCover[i+1];
  for(int i=1;i<=n;i++) {
    for(int j=0;j<=40;j++) {
      num[i][j] = num[i-1][j]+choose(numCover[i]-j, i-j);
      num[i][j]%=mod;
    }
  }
  ll ans = 0LL;
  for(int msk=0;msk<1<<m;msk++) {
    int cnt = __builtin_popcount(msk);
    int l = 1, r = n;
    set<int> idxIn;
    for(int i=0;i<m;i++) {
      if((msk&(1<<i)) == 0) continue;
      l = max(l, in[bad[i].f].f);
      l = max(l, in[bad[i].s].f);
      r = min(r, in[bad[i].f].s);
      r = min(r, in[bad[i].s].s);
      idxIn.insert(bad[i].f);
      idxIn.insert(bad[i].s);
    }
    if(l>r) continue;
    int numSet = idxIn.size();
    ll curr = num[r][numSet] - num[l-1][numSet];
    if(cnt%2==0) ans+=curr;
    else ans-=curr;
    ans%=mod;
  }
  ans%=mod;
  if(ans<0) ans+=mod;
  cout << ans << "\n";
}