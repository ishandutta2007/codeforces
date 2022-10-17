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
  ll W, H, x1, y1, x2, y2, w, h;
  cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
  ll ans = 1e18;

  if(w + x2-x1 <= W){
    smin(ans, max<ll>(w-x1,0));
    smin(ans, max<ll>(w-(W-x2),0));
  }
  if(h + y2-y1 <= H){
    smin(ans, max<ll>(h-y1,0));
    smin(ans, max<ll>(h-(H-y2),0));
  }

  if(ans == 1e18) ans = -1;
  cout << ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cout << setprecision(14) << fixed;
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}