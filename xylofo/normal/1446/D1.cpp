#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif

//vi V;
// vi cnt(105);
// vi freq(2e5+10);
// int F = 0;

bool smin(auto &a, auto&& b) { return (b < a) ? (a = b, 1) : 0; } 
bool smax(auto &a, auto&& b) { return (a < b) ? (a = b, 1) : 0; } 

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<>(a,b-1)(rng) // [a,b)

//void add(int ind, int end) {
//  --freq[cnt[V[ind]]];
//  ++cnt[V[ind]];
//  ++freq[cnt[V[ind]]];
//  while(freq[F+1]) ++F;
//}
//void del(int ind, int end) {
//  --freq[cnt[V[ind]]];
//  --cnt[V[ind]];
//  ++freq[cnt[V[ind]]];
//  while(!freq[F]) --F;
//}
//int calc() {
//  if(freq[F] >= 2) return 1;
//  return 0;
//}
//
//ll ans = 0;
//
//void mo(vector<pii> Q) {
//  int L = 0, R = 0, blk = 350; // ~N/sqrt(Q)
//  vi s(sz(Q)), res = s;
//#define K(x) pii(x.first/blk, x.second ^ -(x.first/blk & 1))
//  iota(all(s), 0);
//  sort(all(s), [&](int s, int t){ return K(Q[s]) < K(Q[t]); });
//  for (int qi : s) {
//    pii q = Q[qi];
//    if(q.second-q.first <= ans) continue;
//    while (L > q.first) add(--L, 0);
//    while (R < q.second) add(R++, 1);
//    while (L < q.first) del(L++, 0);
//    while (R > q.second) del(--R, 1);
//    if(calc()) ans = max<ll>(ans, R-L);
//  }
//}

int main() {
  //freq[0] = 1e9;

  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vi v(n);
  const int up = min(101,n+1);
  set<int> found;
  vi exists;
  rep(i,0,n) {
    //if(i < n/2) v[i] = 1;
    //else v[i] = 2;
    //v[i] = rand()%2;
    cin>>v[i];
    if(!found.count(v[i]) && v[i] <= up) {
      exists.push_back(v[i]);
      found.insert(v[i]);
    }
  }

  vector<vi> pos(n+1);
  rep(i,0,n) {
    pos[v[i]].push_back(i);
  }
  rep(i,0,n+1) pos[i].push_back(n);

  vector<pii> cand;
  //rep(i,0,n+1) { cand.emplace_back(0,i); cand.emplace_back(i,n); }

  rep(a,0,up) rep(b,a+1,up) {
    int half = sz(pos[a]) + sz(pos[b])+2;
    vi delta(half*2,n);
    vi endpts(half*2,0);

    int del = 0;
    int ps = 0;
    int x = 0, y = 0;
    //debug(a, b, "========");
    while(pos[a][x] != n || pos[b][y] != n) {
      smin(delta[del+half], ps);
      smax(endpts[del+half], min(pos[a][x], pos[b][y]));

      if(pos[a][x] < pos[b][y]) {
        ps = pos[a][x]+1;
        del++;
        ++x;
      }
      else {
        ps = pos[b][y]+1;
        del--;
        ++y;
      }
    }
    smax(endpts[del+half], min(pos[a][x], pos[b][y]));
    rep(i,0,sz(delta)) if(delta[i] < endpts[i])
      cand.emplace_back(delta[i],endpts[i]);
  }


  debug(sz(cand));
  sort(all(cand));
  cand.resize(unique(all(cand))-begin(cand));
  shuffle(all(cand), rng);
  debug(sz(cand));

  //V = v;
  //mo(cand);

  ll ans = 0;
  vector<vi> pref(up,vi(n+1));
  rep(i,0,n) rep(a,0,up) {
    pref[a][i+1] = pref[a][i] + (v[i] == a);
  }

  debug("hej");
  for(auto [l,r] : cand) {
    if(r-l <= ans) continue;
    int f = 0;
    int ok = 1;
    for(int a : exists) {
      int q = pref[a][r] - pref[a][l];//lower_bound(all(pos[a]),r) -lower_bound(all(pos[a]),l);
      if(q == f) ok = 1;
      if(q > f) {
        f = q;
        ok = 0;
      }
    }
    if(ok) ans = max<ll>(ans, r-l);
  }
  cout << ans << endl;
}