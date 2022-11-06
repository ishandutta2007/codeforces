#include <vector>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstring>
//#include "myutil.hpp"

using namespace std;
typedef long long ll;
typedef vector<int> vi;
const ll INF = 1ll << 60;

int n;
bool g[100][100];
bool used[100];
int cycle = 0;

bool rec(int prev, int cur, vector<bool>& visited){
  //  cout << prev << " " << cur << endl;
  for (int i = 0; i < n; ++i) {
    if(i == prev || i == cur) continue;
    if (!g[cur][i]) continue;
    if(visited[i]) {
      ++cycle;
      if (cycle > 2) {
    return false;
      }
      continue;
    }
    used[i] = true;
    visited[i] = true;
    if(!rec(cur, i, visited)) {
      return false;
    }
    visited[i] = false;
  }
  return true;
}

bool solve(){
  vector<bool> visited(n);
  used[0] = true;
  bool res = rec(-1, 0, visited) && (cycle == 2);
  if(res) {
    for (int i = 0; i < n; ++i) {
      if(!used[i]){
    return false;
      }
    }
  }
  return res;
}

int main(){
  for (int i = 0; i < 100; ++i) {
    fill(g[i], g[i]+100, false);
  }
  fill(used, used + 100, false);
  int m;
  cin >> n >> m;
  for(int i = 0; i < m; ++i) {
    int f,t;
    cin >> f >> t;
    g[f-1][t-1] = g[t-1][f-1] = true;
  }
  cout << (solve() ? "FHTAGN!" : "NO") << endl;
}