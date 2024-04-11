#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void getNext(vector<ll>& v, ll inc) {
  v.push_back(inc);
  for(int i = 0; i < v.size()-1; i++) v[v.size()-1] += v[i];
}

vector<ll> dfs(vector<ll> v, ll b, ll m, int expectedsize) {
  if(v[v.size()-1] == b) return v;
  ll lhs = 1;
  ll rhs = m;
  while(lhs <= rhs) {
    ll mid = (lhs+rhs)/2;
    vector<ll> cand = v;
    getNext(cand, mid);
    vector<ll> llhs = cand;
    vector<ll> rrhs = cand;
    while(rrhs.size() < expectedsize) {
      getNext(llhs, 1);
      getNext(rrhs, m);
    }
    if(rrhs[expectedsize-1] < b) {
      lhs = mid+1;
    }
    else if(llhs[llhs.size()-1] > b) {
      rhs = mid-1;
    }
    else {
      return dfs(cand, b, m, expectedsize);
    }
  }
  return {};
}

void realsolve() {
  ll a, b, m;
  cin >> a >> b >> m;
  int expectedsize = 1;
  {
    vector<ll> curr;
    curr.push_back(a);
    while(curr[curr.size()-1] < b) {
      getNext(curr, m);
    }
    expectedsize = curr.size();
  }
  vector<ll> ret = dfs({a}, b, m, expectedsize);
  if(ret.size() == 0) cout << "-1\n";
  else {
    cout << ret.size();
    for(auto out: ret) cout << " " << out;
    cout << "\n";
  }
}

void solve() {
  int t;
  cin >> t;
  while(t--) realsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}