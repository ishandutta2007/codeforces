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

const int BAD = 1e9;

struct FT {
  vi s;
  FT(int n) : s(n,BAD) {}
  void update(int pos, int dif) { // a[pos] += dif
    assert(0 <= pos && pos < sz(s));
    for (; pos < sz(s); pos |= pos + 1) smin(s[pos], dif);
  }
  int query(int pos) { // sum of values in [0, pos)
    assert(0 <= pos && pos <= sz(s));
    int res = BAD;
    for (; pos > 0; pos &= pos - 1) smin(res, s[pos-1]);
    return res;
  }
};

struct FT2 {
  vector<vi> ys; vector<FT> ft;
  FT2(int limx) : ys(limx) {}
  void fakeUpdate(int x, int y) {
    for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);
  }
  void init() {
    for (vi& v : ys) sort(all(v)), ft.emplace_back(sz(v));
  }
  int ind(int x, int y) {
    return (int)(lower_bound(all(ys[x]), y) - ys[x].begin()); }
  void update(int x, int y, int dif) {
    for (; x < sz(ys); x |= x + 1)
      ft[x].update(ind(x, y), dif);
  }
  int query(int x, int y) {
    int sum = BAD;
    for (; x; x &= x - 1)
      smin(sum, ft[x-1].query(ind(x-1, y)));
    return sum;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vi l(m), r(m);
  vector<vi> at_x(n+1);
  rep(i,0,m) {
    cin>>l[i]>>r[i];
    //l[i] = rand()%n+1, r[i] = rand()%n+1;
    //if(l[i] > r[i]) swap(l[i], r[i]);

    --l[i];
    at_x[r[i]-l[i]].emplace_back(i);
  }

  FT2 ft(n+10);
  rep(i,0,m) ft.fakeUpdate(n-l[i],r[i]);
  ft.init();

  auto activate = [&](int i) {
    ft.update(n-l[i],r[i],i);
  };

  auto find_lowest_index = [&](int L, int R) {
    return ft.query(n-L+1, R+1);
  };

  function<int(int,int)> solve = [&](int L, int R) {
    int x = find_lowest_index(L,R);
    if(x == BAD) return 0;
    assert(L <= l[x] && r[x] <= R);
    return solve(L, l[x]) + solve(r[x], R) + r[x]-l[x];
  };

  vi res(sz(at_x));
  for(int x = sz(at_x); x--;) {
    for(auto i : at_x[x]) activate(i);
    res[x] = solve(0,n);
  }

  rep(i,1,n+1) cout << res[i] << "\n";
}