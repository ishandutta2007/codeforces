#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// DID YOU FIX GLOBAL STATE

typedef long long ll;
const double PI = 2 * acos(0);
const int MOD = 1000000007;

void dfs(vector<ll>& v, ll g) {
  if(v[v.size()-1] == g) {
    printf("YES\n%d\n", v.size());
    for(int i = 0; i < v.size(); i++) {
      printf("%lld", v[i]);
      if(i + 1 == v.size()) printf("\n");
      else printf(" ");
    }
    exit(0);
  }
  if(10*v[v.size()-1] + 1 <= g) {
    v.push_back(10*v[v.size()-1] + 1);
    dfs(v, g);
    v.erase(v.begin() + v.size() - 1);
  }
  if(2*v[v.size()-1] <= g) {
    v.push_back(2*v[v.size()-1]);
    dfs(v, g);
    v.erase(v.begin() + v.size() - 1);
  }
}

void solve() {
  ll a, b;
  scanf("%lld%lld", &a, &b);
  vector<ll> l;
  l.push_back(a);
  dfs(l, b);
  printf("NO\n");
}

int main() {
  solve();
  return 0;
}