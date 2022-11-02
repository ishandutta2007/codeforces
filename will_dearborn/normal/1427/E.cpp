#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

const int N = 20;
unordered_set<ll> was;
vs ans;
vii d(1e6, pii(1e9, -1));
vl v(2 * N);

void sum(ll x, ll y) {
  assert(was.count(x) && was.count(y));
  ans.push_back(to_string(x) + " + " + to_string(y) + '\n');
  was.insert(x + y);
}

void xr(ll x, ll y) {
  assert(was.count(x) && was.count(y));
  ans.push_back(to_string(x) + " ^ " + to_string(y) + '\n');
  was.insert(x ^ y);
}

void solve(ll n) {
  was.clear();
  ans.clear();
  was.insert(n);
  while (n != 1) {
    for (int j = 0; j < N; ++j) {
      ll x = n << j;
      sum(x, x);
      sum(2 * x, 2 * x - n);
    }
    ll i = n;
    for (int j = 0; j < N; ++j) v[j] = i * ((1LL << (j + 1)) - 1);
    for (int j = 0; j < N; ++j) v[j + N] = i * ((1LL << (j + 1)));
    for (ll x : v) assert(was.count(x));
    int it = 0, c = 2 * N;
    for (int b = 45; b >= 0 && it < v.size(); --b) {
      for (int j = it; j < v.size(); ++j) if (v[j] & (1LL << b)) {
        swap(v[it], v[j]);
        break;
      }
      if (v[it] & (1LL << b)) {
        for (int j = 0; j < v.size(); ++j) if (j != it && (v[j] & (1LL << b))) {
          xr(v[j], v[it]);
          v[j] ^= v[it];
          ++c;
          if (v[j] < n && d[n].first == d[v[j]].first + c) {
            it = v.size();
            n = v[j];
            break;
          }
        }
        ++it;
      }
    }
  }
  assert(ans.size() < 1e5);
  cout << ans.size() << '\n';
  for (auto s : ans) cout << s;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  d[1].first = 0;
  for (int i = 3; i < d.size(); i += 2) {
    for (int j = 0; j < N; ++j) v[j] = i * ((1LL << (j + 1)) - 1);
    for (int j = 0; j < N; ++j) v[j + N] = i * ((1LL << (j + 1)));
    int it = 0, c = 2 * N;
    for (int b = 45; b >= 0 && it < v.size() && d[i].first > 2000; --b) {
      for (int j = it; j < v.size(); ++j) if (v[j] & (1LL << b)) {
        swap(v[it], v[j]);
        break;
      }
      if (v[it] & (1LL << b)) {
        for (int j = 0; j < v.size(); ++j) if (j != it && (v[j] & (1LL << b))) {
          v[j] ^= v[it];
          ++c;
          if (v[j] < i) d[i] = min(d[i], pii(d[v[j]].first + c, v[j]));
        }
        ++it;
      }
    }
//    cerr << i << ' ' << d[i].first << endl;
    assert(d[i].first <= 1e5);
  }
  if (0) for (int n = 1; n < 1e6; n += 2) {
    cerr << n << endl;
    solve(n);
  }
  int n;
  cin >> n;
  solve(n);
  return 0;
}