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
#include <unordered_map>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> state;
typedef pair<double, pii> event;

map<state, int> dp;
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    dp[{x, {y, z}}] = i+1;
  }
  vector<pii> ret;
  auto it = dp.begin();
  while(it != dp.end()) {
    auto it2 = it;
    it2++;
    if(it2 == dp.end()) break;
    if(it->first.first == it2->first.first && it->first.second.first == it2->first.second.first) {
      ret.push_back({it->second, it2->second});
      dp.erase(it);
      it = ++it2;
      it2--;
      dp.erase(it2);
    }
    else {
      it++;
    }
  }
  it = dp.begin();
  while(it != dp.end()) {
    auto it2 = it;
    it2++;
    if(it2 == dp.end()) break;
    if(it->first.first == it2->first.first) {
      ret.push_back({it->second, it2->second});
      dp.erase(it);
      it = ++it2;
      it2--;
      dp.erase(it2);
    }
    else {
      it++;
    }
  }
  it = dp.begin();
  while(dp.size()) {
    int a = it->second;
    dp.erase(it++);
    int b = it->second;
    dp.erase(it++);
    ret.push_back({a, b});
  }
  for(auto out: ret) {
    cout << out.first << " " << out.second << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}