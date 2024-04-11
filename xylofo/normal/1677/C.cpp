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
  cin >> n;
  vi p1(n), p2(n), p(n);
  rep(i,0,n) { cin>>p1[i]; --p1[i]; }
  rep(i,0,n) { cin>>p2[i]; --p2[i]; }

  rep(i,0,n) p[p1[i]] = p2[i];

  int lo = 1;
  int hi = n;
  ll ans = 0;

  vi vis(n);
  rep(i,0,n) if(!vis[i]){
    int x = i;
    int c = 0;
    do {
      vis[x] = 1;
      x = p[x];
      ++c;
    } while(x != i);

    rep(_,0,c/2) {
      ans += 2*hi - 2*lo;
      ++lo;
      --hi;
    }
  }

  cout << ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}


/*
 *
 *
 * cycles with lens l1, l2, ..., lk summing to n
 *
 * one cycle?
 *
 * even cycle?
 *
 * 1 n 2 n-1
 *
 * is large yes and is small okay!
 * largest half positive twice!
 * smallest half negative twice!
 *
 * odd cycle? mid number not counted at all?
 *
 *
 *
 * */