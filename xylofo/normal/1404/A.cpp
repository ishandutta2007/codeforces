#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
  int k,n;
  cin>>n>>k;
  string s;
  cin>>s;
  rep(i,0,n) {
    if(s[i] == '?') continue;
    if(s[i%k] == '?') s[i%k] = s[i];
    if(s[i%k] != s[i]) goto bad;
  }
  s.resize(k);
  if(2*count(all(s), '0') > k) goto bad;
  if(2*count(all(s), '1') > k) goto bad;

  cout << "YES" << endl;
  return;
bad:;
  cout << "NO" << endl;
}


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}