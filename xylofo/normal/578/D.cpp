#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#include <bits/extc++.h>
// To use most bits rather than just the lowest ones:
struct chash { // large odd number for C
  const uint64_t C = ll(4e18 * acos(0)) | 71;
  ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};
__gnu_pbds::gp_hash_table<ll,ll,chash> dp({},{},{},{},{1<<16});

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  string s;
  cin >> n >> m >> s;

  auto at = [&](int i, int a, int b, int c) {
    a -= i-5;
    b -= i-5;
    c -= i-5;
    return i + n * 1LL * (a + 5 * (b + 5 * c));
  };

  function<ll(int,int,int,int)> f =
    [&](int i, int a, int b, int c) -> ll {
      if(i == n) return (b == n-1);
      if(b < i-1) return 0;

      // m[i][i-1] = a
      // m[i][i-0] = b
      // m[i][i+1] = c
      ll key = at(i,a,b,c);

      if(dp.find(key) != dp.end()) return dp[key];

      ll ans = 0;
      unordered_set<char> chr;
      rep(j,max(0,i-1),min(i+2,n))
        chr.emplace(s[j]);
      chr.emplace('?');
      for(char ti : chr) {
        int aa = b;
        if(i>0 && ti == s[i-1]) aa = a+1;
        int bb = max(aa, c);
        if(ti == s[i]) bb = b+1;
        int cc = bb;
        if(i+1 < n && ti == s[i+1]) cc = c+1;
        ll mul = 1;
        if(ti == '?') mul = m - sz(chr)+1;
        ans += mul*f(i+1,aa,bb,cc);
      }

      return dp[key] = ans;
    };

  ll ans = f(0,0,0,0);
  cout << ans << endl;
}