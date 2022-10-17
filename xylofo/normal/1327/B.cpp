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

void solve(int tc) {
  int n;
  cin>>n;
  vi taken(n);
  int free_princess = -1;
  rep(i,0,n) {
    int k;
    cin>>k;
    bool done = false;
    rep(j,0,k) {
      int x;
      cin>>x;
      --x;
      if(!done && !taken[x])
        taken[x] = done = 1;
    }
    if(!done) free_princess = i;
  }
  if(free_princess == -1) cout << "OPTIMAL\n";
  else {
    cout << "IMPROVE\n";
    rep(i,0,n) if(!taken[i]) {
      cout << free_princess+1 << " " << i+1 << "\n";
      return;
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