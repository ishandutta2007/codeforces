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
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  string s;
  cin>>s;
  vi pref_oo(n), pref_zz(n);
  rep(i,0,n-1) pref_oo[i+1] += pref_oo[i] + (s[i] == '1' && s[i+1] == '1');
  rep(i,0,n-1) pref_zz[i+1] += pref_zz[i] + (s[i] == '0' && s[i+1] == '0');

  rep(i,0,q) {
    int x, y;
    cin>>x>>y;
    --x,--y;
    int ones = pref_oo[y] - pref_oo[x];
    int zeroes = pref_zz[y] - pref_zz[x];
    int ans = 1 + max(ones, zeroes);
    cout << ans << endl;
  }
}