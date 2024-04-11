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

pii combine(pii a, pii b) {
  return pii(max(a.first, b.first), min(a.second, b.second));
}
bool contain(pii a, int x) {
  return a.first <= x && x <= a.second;
}

template<class T>
struct RMQ {
  vector<vector<T>> jmp;
  RMQ(const vector<T>& V) : jmp(1, V) {
    for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
      jmp.emplace_back(sz(V) - pw * 2 + 1);
      rep(j,0,sz(jmp[k]))
        jmp[k][j] = combine(jmp[k - 1][j], jmp[k - 1][j + pw]);
    }
  }
  T query(int a, int b) {
    if(a == b) return {-2e9, 2e9};
    assert(a < b); // or return inf if a == b
    int dep = 31 - __builtin_clz(b - a);
    return combine(jmp[dep][a], jmp[dep][b - (1 << dep)]);
  }
  int walk(int st, int v) {
    // return max en so that contain(query(st,en), v);
    for(int k = sz(jmp); k--;) {
      if(st < sz(jmp[k]) && contain(jmp[k][st], v))
        st += (1<<k);
    }
    return st;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vi k(n+3,0);
  vector<pii> ival_l(n+3), ival_r(n+3);
  rep(i,1,n+1) {
    cin >> k[i];
    cin >> ival_l[i].first >> ival_l[i].second;
    cin >> ival_r[i].first >> ival_r[i].second;
  }
  ival_l[n+1] = ival_r[n+1] = {-9,2e9};
  k[n+1] = -9;
  ival_l[n+2] = ival_r[n+2] = {-10,-10};
  k[n+1] = -7;

  RMQ rmq_l(ival_l);
  RMQ rmq_r(ival_r);

  vi nxt_fail_l(n+3,n+2);
  vi nxt_fail_r(n+3,n+2);
  for(int i = n+2; i--;) {
    nxt_fail_l[i] = nxt_fail_l[i+1];
    nxt_fail_r[i] = nxt_fail_r[i+1];
    if(!contain(ival_l[i], k[i])) nxt_fail_l[i] = i;
    if(!contain(ival_r[i], k[i])) nxt_fail_r[i] = i;
  }

  // only swaps important, maybe reach?
  vi reach_i_ip1(n+1);
  vi reach_ip1_i(n+1);
  vector<vi> delta_reach_i_ip1(n+3);
  vector<vi> delta_reach_ip1_i(n+3);

  auto okay_for = [&](int i, int l, int r) {
    return contain(ival_l[i], k[l]) && contain(ival_r[i], k[r]);
  };

  auto i_ip1 = [&](int i) { return reach_i_ip1[i] && okay_for(i+1,i,i+1); };
  auto ip1_i = [&](int i) { return reach_ip1_i[i] && okay_for(i+1,i+1,i); };

  //reach_i_ip1[0] = reach_ip1_i[0] = 1; //okay_for(1, 1, 0);
  int start = 1e9;
  delta_reach_ip1_i[0].emplace_back(start);
  delta_reach_i_ip1[0].emplace_back(start);
  delta_reach_ip1_i[1].emplace_back(~start);
  delta_reach_i_ip1[1].emplace_back(~start);

  set<int> from_i_ip1;
  set<int> from_ip1_i;

  rep(i,0,n+1) {
    for(int x : delta_reach_i_ip1[i]) {
      if(x < 0) from_i_ip1.erase(~x);
      else from_i_ip1.emplace(x);
    }
    for(int x : delta_reach_ip1_i[i]) {
      if(x < 0) from_ip1_i.erase(~x);
      else from_ip1_i.emplace(x);
    }
    reach_i_ip1[i] = sz(from_i_ip1) ? ~*begin(from_i_ip1) : 0;
    reach_ip1_i[i] = sz(from_ip1_i) ? ~*begin(from_ip1_i) : 0;

    if(i_ip1(i)) {
      int j = i+1;
      int max_j0 = rmq_l.walk(j,k[i]);
      int max_j1 = nxt_fail_r[j];
      int max_j = min(max_j0, max_j1);
      //while(okay_for(j,i,j)) ++j;
      //assert(j == max_j);
      delta_reach_ip1_i[j].emplace_back(i);
      delta_reach_ip1_i[max_j].emplace_back(~i);
    }
    if(ip1_i(i)) {
      int j = i+1;
      int max_j0 = rmq_r.walk(j,k[i]);
      int max_j1 = nxt_fail_l[j];
      int max_j = min(max_j0, max_j1);
      //while(okay_for(j,j,i)) ++j;
      //assert(j == max_j);
      delta_reach_i_ip1[j].emplace_back(i);
      delta_reach_i_ip1[max_j].emplace_back(~i);
    }
  }
  debug(reach_i_ip1);
  debug(reach_ip1_i);

  if(!i_ip1(n) && !ip1_i(n)) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;

  int l = n+1, r = n+1;
  if(i_ip1(n)) l = n;
  else r = n;

  vector<pii> ans;
  auto go = [&](int nl, int nr) {
    assert(l == nl || r == nr);
    ans.emplace_back(l,r);
    while(l > nl) { --l; ans.emplace_back(l,r); }
    while(r > nr) { --r; ans.emplace_back(l,r); }
  };
  while(l > 0 && r > 0) {
    debug(l,r);
    assert(okay_for(max(l,r), l, r));
    assert(abs(l-r) == 1);
    if(l+1 == r) { // (l, l+1)
      int t = reach_i_ip1[l];
      assert(t);
      t = ~t;
      // (l, t) ... (t+1,t)
      r = t;
      if(t == start) go(0,0);
      else go(t+1, t);
    }
    else if(l == r+1) { // (r+1, r)
      int t = reach_ip1_i[r];
      assert(t);
      t = ~t;
      // (t,r) .. (t,t+1)
      l = t;
      if(t == start) go(0,0);
      else go(t, t+1);
    }
    else assert(false);
  }
  debug(ans);
  assert(sz(ans) == n);
  reverse(all(ans));
  rep(i,0,n) {
    assert(ans[i].first == i+1 || ans[i].second == i+1);
    assert(ans[i].first < i+1 || ans[i].second < i+1);
    cout << (ans[i].second == i+1) << " ";
  }
  cout << endl;
}