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


bool smin(auto &a, auto&& b) { return (b < a) ? (a = b, 1) : 0; } 
bool smax(auto &a, auto&& b) { return (a < b) ? (a = b, 1) : 0; } 

void solve(int tc) {
  int n;
  cin >> n;
  vi a(n);
  rep(i,0,n) cin >> a[i];

  vi sum(1<<n);
  rep(i,0,n) sum[1<<i] = a[i];
  rep(b,0,n) rep(msk,0,1<<n) if(msk>>b&1)
    sum[msk] += sum[msk^(1<<b)];

  const int inf = 1e9;
  vector<vi> dp(n+1,vi(1<<n,inf)); // did use, pos_rem
  vector<vector<vi>> dad(n, vector<vi>(n+1, vi(1<<n,-1)));

  dp[0][(1<<n)-1] = 0;
  rep(i,0,n) {
    vector<vi> ndp = dp;
    rep(taken,0,n+1) {
      rep(can_use,0,1<<n) if(dp[taken][can_use] != inf) {
        if(can_use>>i&1) {
          int r = can_use^(1<<i);
          for(int sub = r; true; sub = (sub-1)&r) {
            int here = a[i] + sum[sub];
            if(here > dp[taken][can_use])
              if(smin(ndp[taken+1][r^sub], here))
                dad[i][taken+1][r^sub] = sub^(1<<i);
            if(sub == 0) break;
          }
        }
      }
    }
    dp = move(ndp);
  }
  int best = 0;
  rep(taken,0,n+1) if(dp[taken][0] != inf)  best = taken;
  debug(best);
  assert(best);

  int msk = 0, taken = best;
  vector<vi> groups(n);
  for(int i = n; i--;) {
    assert(taken>=0);
    int sub = dad[i][taken][msk];
    if(sub == -1) continue;
    //debug(bitset<15>(msk),bitset<15>(sub));
    assert((sub&msk) == 0);
    assert(sub>>i&1);
    rep(j,0,n) if(sub>>j&1) groups[i].emplace_back(j);
    --taken;
    msk ^= sub;
  }
  assert(taken == 0 && msk == (1<<n)-1);
  debug(groups);

  cout << n-best << "\n";
  vi alive(n,1);
  auto idx = [&](int i) {
    assert(alive[i]);
    int r = 1;
    rep(j,0,i) r += alive[j];
    return r;
  };
  rep(i,0,n) if(sz(groups)) {
    for(int x : groups[i]) if(x != i) {
      cout << idx(x) << " " << idx(i) << "\n";
      alive[x] = 0;
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}