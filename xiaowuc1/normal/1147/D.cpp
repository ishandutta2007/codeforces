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
typedef pair<pii, pii> state;
typedef vector<vector<ll>> matrix;

const int MOD = 998244353;
string s;

vector<pii> edges[2005]; // <out, different color>
int dp[2005];
/*
0 to s.size()-1 are original
*/

bool bfs(int start) {
  assert(dp[start] < 2);
  queue<int> q;
  q.push(start);
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    for(pii out: edges[curr]) {
      int nd = out.first;
      int nw = dp[curr] ^ out.second;
      if(dp[nd] == 2) {
        dp[nd] = nw;
        q.push(nd);
      }
      else if(dp[nd] != nw) {
        return false;
      }
    }
  }
  return true;
}

int solve(int len) {
  for(int i = 0; i < 2*s.size(); i++) edges[i].clear();
  for(int i = 0; i < 2*s.size(); i++) {
    dp[i] = 2;
  }
  for(int i = 0; i < s.size(); i++) {
    edges[i].push_back({s.size()-1-i, 0});
  }
  for(int i = 0; i < len; i++) {
    int j = len-1-i;
    int si = i + s.size();
    int sj = j + s.size();
    edges[si].push_back({sj, 0});
    edges[sj].push_back({si, 0});
  }
  int comps = 0;
  {
    int match = s.size()-1;
    for(int i = len-1; i >= 0; i--) {
      if(s[match] == '0') {
        edges[match].push_back({i + s.size(), 0});
        edges[i+s.size()].push_back({match, 0});
      }
      else if(s[match] == '1') {
        edges[match].push_back({i + s.size(), 1});
        edges[i+s.size()].push_back({match, 1});
      }
      match--;
    }
  }
  dp[s.size()] = 1;
  if(!bfs(s.size())) return 0;
  if(dp[0] == 0) return 0;
  dp[0] = 1;
  if(!bfs(0)) return 0;
  for(int i = 0; i + len < s.size(); i++) {
    if(s[i] == '0') {
      if(dp[i] == 1) return 0;
      dp[i] = 0;
      if(!bfs(i)) return 0;
    }
    else if(s[i] == '1') {
      if(dp[i] == 0) return 0;
      dp[i] = 1;
      if(!bfs(i)) return 0;
    }
  }
  ll ret = 1;
  for(int i = 0; i < s.size() + len; i++) {
    if(dp[i] != 2) continue;
    dp[i] = 0;
    ret *= 2;
    ret %= MOD;
    if(!bfs(i)) return 0;
  }
  return ret;
}

void solve() {
  cin >> s;
  ll ret = 0;
  for(int len = 1; len <= s.size(); len++) {
    ret += solve(len);
    ret %= MOD;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}