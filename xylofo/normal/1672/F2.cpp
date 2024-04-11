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
  vi a(n);
  vi b(n);
  rep(i,0,n) cin >> a[i];
  rep(i,0,n) cin >> b[i];
  map<int,int> cnt;
  rep(i,0,n) ++cnt[a[i]];
  int mx = a[0], mxc = 0;
  rep(i,0,n) if(mxc < cnt[a[i]]) mx = a[i], mxc = cnt[a[i]];

  mt19937_64 rng(42);
  vi ord(n);
  iota(all(ord),0);

  vector<vi> where(n+10);
  vi seen(n+10);
  int T = 99;
  vi p(n);

  rep(_,0,27) {
    shuffle(all(ord),rng);

    for(int i : ord) where[a[i]].emplace_back(i);
    shuffle(all(ord),rng);
    for(int i : ord) {
      p[i] = where[b[i]].back();
      where[b[i]].pop_back();
    }


    int ans = 0;
    vi vis(n);
    rep(i,0,n) if(!vis[i]) {
      ++T;
      vi cyc;
      int x = i;
      do {
        vis[x] = true;
        cyc.emplace_back(b[x]);
        x = p[x];
      } while(x != i);
      //debug(cyc);

      vi pth;
      for(int c : cyc) {
        if(seen[c] == T) {
          //vi q = {c};
          while(pth.back() != c) {
            //q.emplace_back(pth.back());
            seen[pth.back()] = 0;
            //seen.erase(pth.back());
            pth.pop_back();
          }
          //debug(q);
          ++ans;
        }
        else {
          //seen.emplace(c);
          seen[c] = T;
          pth.push_back(c);
        }
      }
      //debug(pth);
      ++ans;
    }

    //debug(ans);
    assert(ans >= mxc);
    if(ans > mxc) {
      cout << "WA" << endl;
      return;
    }
  }

  cout << "AC" << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}