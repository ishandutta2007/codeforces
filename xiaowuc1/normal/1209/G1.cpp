#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int lhs[200005];
int rhs[200005];
int l[200005];
void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> l[i];
    if(lhs[l[i]] == 0) lhs[l[i]] = i;
    rhs[l[i]] = i;
  }
  set<pii> fin;
  vector<pii> rel;
  for(int i = 1; i <= 200000; i++) {
    if(lhs[i]) rel.push_back({lhs[i], rhs[i]});
  }
  sort(rel.begin(), rel.end());
  for(int i = 0; i < rel.size();) {
    int currl = rel[i].first;
    int currr = rel[i].second;
    int j = i+1;
    while(j < rel.size() && rel[j].first <= currr) {
      currr = max(currr, rel[j++].second);
    }
    fin.insert({currl, currr});
    i = j;
  }
  int ret = n;
  for(pii out: fin) {
    map<int, int> dp;
    int save = 0;
    for(int i = out.first; i <= out.second; i++) {
      save = max(save, ++dp[l[i]]);
    }
    ret -= save;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}