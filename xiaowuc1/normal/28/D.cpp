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
typedef pair<pii, pii> ppiipii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<ll>> matrix;
typedef pair<int, vector<int>> wtf;

// <sum -> <x coordinate, index, <value, diff>>
map<int, vector<ppiipii>> sums;

bool inject(map<int, pii>& dp, int coord, int val, int idx) {
  if(!dp.count(coord)) {
    dp[coord] = {val, idx};
    return true;
  }
  else if(val > dp[coord].first) {
    dp[coord] = {val, idx};
    return true;
  }
  return false;
}

wtf solve(int actualSum, vector<ppiipii>& l) {
  map<int, pii> dp;
  // <coordinate, <value, VECTOR INDEX>>
  vector<int> to;
  for(int a = 0; a < l.size(); a++) {
    to.push_back(-1);
  }
  for(int i = 0; i < l.size(); i++) {
    ppiipii currV = l[i];
    int xCoord = currV.first.first;
    int val = currV.second.first;
    int sz = currV.second.second;
    if(xCoord == 0) {
      inject(dp, sz, currV.second.first, i);
    }
    else {
      if(dp.count(xCoord)) {
        if(inject(dp, xCoord + sz, dp[xCoord].first + val, i)) {
          to[i] = dp[xCoord].second;
        }
      }
    }
  }
  int ans = -1;
  vector<int> ret;
  if(dp.count(actualSum)) {
    ans = dp[actualSum].first;
    int now = actualSum;
    int idx = dp[actualSum].second;
    while(idx >= 0) {
      ret.push_back(l[idx].first.second);
      idx = to[idx];
    }
    reverse(ret.begin(), ret.end());
  }
  return {ans, ret};
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    int v, c, l, r;
    scanf("%d%d%d%d", &v, &c, &l, &r);
    sums[l+r+c].push_back({{l, i}, {v, c}});
  }
  int lhs = -1;
  vector<int> ret;
  for(auto x: sums) {
    wtf cand = solve(x.first, x.second);
    if(cand.first > lhs) {
      lhs = cand.first;
      ret = cand.second;
    }
  }
  printf("%d\n", ret.size());
  if(ret.size()) {
    for(int i = 0; i < ret.size(); i++) {
      printf("%d", ret[i]);
      if(i+1 == ret.size()) printf("\n");
      else printf(" ");
    }
  }
}