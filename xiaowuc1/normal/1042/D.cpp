#include <bits/stdc++.h>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);

ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/
using namespace std;

const double PI = 2 * acos(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<ll>> matrix;

int n;
ll le;

set<ll> allPref;
ll l[200005];
map<ll, int> disc;

int bit[250000];
void update(int idx, int val) {
  idx += 5;
  while(idx < 250000) {
    bit[idx] += val;
    idx += idx & -idx;
  }
}
int query(int idx) {
  idx += 5;
  int ret = 0;
  while(idx) {
    ret += bit[idx];
    idx -= idx & -idx;
  }
  return ret;
}

int main() {
  scanf("%d%lld", &n, &le);
  for(int i = 0; i < n; i++) {
    scanf("%lld", &l[i]);
  }
  allPref.insert(0);
  {
    ll now = 0;
    for(int i = 0; i < n; i++) {
      now += l[i];
      allPref.insert(now);
    }
  }
  for(auto x: allPref) {
    int sz = disc.size();
    disc[x] = sz;
  }
  ll ans = 0;
  update(disc[0], 1);
  ll now = 0;
  for(int i = 0; i < n; i++) {
    now += l[i];
    auto worse = allPref.upper_bound(now-le);
    if(worse != allPref.begin()) {
      worse--;
      ans += (i+1) - query(disc[*worse]);
    }
    else {
      ans += i+1;
    }
    update(disc[now], 1);
  }
  printf("%lld\n", ans);
}