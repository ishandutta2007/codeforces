#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
  int n;
  cin>>n;
  vi v(n);
  vi cnt(n);
  rep(i,0,n) {
    cin>>v[i];
    --v[i];
    ++cnt[v[i]];
  }

  vi ed(n);
  rep(i,0,n) {
    int bad = 2;
    if(i && v[i] != v[i-1]) --bad;
    if(i+1 < n && v[i] != v[i+1]) --bad;
    ed[v[i]] += bad;
  }

  int mx = *max_element(all(cnt));
  if(mx > (n+1)/2) {
    cout << -1 << "\n";
    return;
  }

  rep(i,0,2) {
    sort(ed.rbegin(), ed.rend());
    ed[0]--;
  }
  sort(ed.rbegin(), ed.rend());

  int most = ed[0];
  int rest = accumulate(all(ed), 0) - most;
  assert(most >= 0 && rest >= 0);
  assert((most + rest) % 2 == 0);
  int k = min(most, rest);
  //cerr << most << " " << rest << endl;
  most -= k;
  rest -= k;
  int ans = k + most + ((rest+1)/2);
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}