#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);
*/
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;
typedef pair<int, ppiipii> pippiipii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
typedef pair<string, string> pss;
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef long double ld;

const int MOD = 1000000007;

ll modpow(ll b, ll e, ll m) {
  ll r = 1;
  while(e) {
    if(e%2) {
      r*=b;
      r%=m;
    }
    b*=b;
    b%=m;
    e/=2;
  }
  return r;
}

int n, m, k;
ll l[500005];

int ufpar[500005];
int find(int x) {
  return ufpar[x] == x ? x : (ufpar[x] = find(ufpar[x]));
}
bool merge(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  if(fx == fy) return false;
  ufpar[fx] = fy;
  return true;
}
void ufreset(vector<int>& v) {
  for(int out: v) {
    ufpar[out] = out;
  }
}

map<ll, vector<pii>> edges;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i < n; i++) {
    scanf("%lld", &l[i]);
  }
  while(m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    edges[l[a]^l[b]].push_back(pii(a, b));
  }
  ll twopow = modpow(2, n, MOD);
  ll ret = (1LL << k);
  ret %= MOD;
  ret *= twopow;
  ret %= MOD;
  for(auto out: edges) {
    ret += MOD-twopow;
    if(ret >= MOD) ret -= MOD;
    int nc = n;
    {
      vector<int> all;
      for(pii out2: out.second) {
        all.push_back(out2.first);
        all.push_back(out2.second);
      }
      ufreset(all);
    }
    for(pii out2: out.second) {
      int lhs = find(out2.first);
      int rhs = find(out2.second);
      if(merge(lhs, rhs)) nc--;
    }
    ret += modpow(2, nc, MOD);
    if(ret >= MOD) ret -= MOD;
  }
  printf("%lld\n", ret);
}