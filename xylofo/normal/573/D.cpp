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

const int maxn = 30123;
ll wword[maxn];
ll hhord[maxn];
ll whword[maxn];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  vector<ll> w(n);
  vector<ll> h(n);
  rep(i,0,n) cin>>w[i];
  rep(i,0,n) cin>>h[i];
  vi word(n), hord;
  vi wh;
  iota(all(word),0);
  hord = wh = word;
  sort(all(word),[&](int i, int j){return w[i] > w[j];});
  sort(all(hord),[&](int i, int j){return h[i] > h[j];});
  vi iword(n);
  rep(i,0,n) iword[word[i]] = i;

  rep(i,0,n) wword[i] = w[word[i]];
  rep(i,0,n) hhord[i] = h[hord[i]];
  rep(i,0,n) whword[i] = wh[word[i]];

  auto go = [&](){
    debug('%');
    ll old = 0, oldold = -1e18, oldoldold = -1e18;
    debug(wh);
    debug(word);
    debug(hord);
    rep(i,0,n) {
      ll cur = -1e18;
      if(whword[i] != hord[i]) {
        cur = max(cur, old + wword[i] * hhord[i]);
      }
      if(i && whword[i-1] != hord[i] && whword[i] != hord[i-1]) {
        cur = max(cur, oldold + wword[i]*hhord[i-1] + wword[i-1]*hhord[i]);
      }
      if(i>=2) {
        if(whword[i-2] != hord[i-1]
            && whword[i-1] != hord[i-0]
            && whword[i-0] != hord[i-2])
          cur = max(cur, oldoldold
              + wword[i-2]*hhord[i-1]
              + wword[i-1]*hhord[i-0]
              + wword[i-0]*hhord[i-2]);
        if(whword[i-2] != hord[i-0]
            && whword[i-1] != hord[i-2]
            && whword[i-0] != hord[i-1])
          cur = max(cur, oldoldold
              + wword[i-2]*hhord[i-0]
              + wword[i-1]*hhord[i-2]
              + wword[i-0]*hhord[i-1]);
      }
      oldoldold = oldold;
      oldold = old;
      old = cur;
    }
    return old;
  };

  rep(i,0,q) {
    int a, b;
    cin>>a>>b;
    --a,--b;
    swap(wh[a],wh[b]);
    whword[iword[a]] = wh[a];
    whword[iword[b]] = wh[b];
    cout << go() << "\n";
  }
}