
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#include <bits/extc++.h> /** keep-include */
struct chash {
  const uint64_t RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
  const uint64_t C = ll(2e18 * acos(-1)) + 71; // large odd number
  ll operator()(ll x) const { return __builtin_bswap64((x^RANDOM)*C); }
};
__gnu_pbds::gp_hash_table<ll,int,chash> cnt({},{},{},{},{1<<16});

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n;
  cin>>n;
  vector<ll> a(n), b(n);
  rep(i,0,n) cin>>a[i];
  rep(i,0,n) cin>>b[i];

  rep(i,0,n) ++cnt[a[i]];

  ll ans = 0;
  rep(i,0,n) {
    rep(j,0,n) if(cnt[a[j]] >= 2){
      if((a[i] | a[j]) == a[j]) {
        cnt[a[i]] = 2;
      }
    }
    if(cnt[a[i]] >= 2)
      ans += b[i];
  }

  cout << ans << endl;
}