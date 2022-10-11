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

vector<ll> all;

ll solve(ll curr) {
  if(all[0] > curr) return 0;
  if(all[all.size()-1] <= curr) return all.size();
  int lhs = 0;
  int rhs = all.size()-1;
  while(lhs != rhs) {
    int mid = (lhs+rhs+1)/2;
    if(all[mid] <= curr) lhs = mid;
    else rhs = mid-1;
  }
  return lhs+1;
}

bool valid(ll x) {
  if(x <= 0) return false;
  int r = 0;
  while(x) {
    if(x%10) r++;
    x /= 10;
  }
  return r <= 3;
}

int buf[20];

void check() {
  ll curr = 0;
  for(int i = 0; i < 19; i++) {
    curr *= 10;
    curr += buf[i];
  }
  if(valid(curr)) all.push_back(curr);
}

void dfs(int curr, int val) {
  if(curr == 19) check();
  else {
    buf[curr] = 0;
    dfs(curr+1, val);
    if(val < 3) {
      for(int i = 1; i < 10; i++) {
        buf[curr] = i;
        dfs(curr+1, val+1);
      }
    }
    buf[curr] = 0;
  }
}

void init() {
  dfs(0, 0);
  sort(all.begin(), all.end());
}

void solve() {
  ll lhs, rhs;
  scanf("%lld%lld", &lhs, &rhs);
  printf("%lld\n", solve(rhs) - solve(lhs-1));
}

int main() {
  init();
  int qq;
  scanf("%d", &qq);
  while(qq--) solve();
}