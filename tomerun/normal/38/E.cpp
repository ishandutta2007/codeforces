#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cmath>
//#include "../myutil.hpp"

typedef long long ll;
using namespace std;
const ll INF = 1ll << 60;
const double EPS = 1e-8;
int n;
ll dp[3000];

struct M{
  int x;
  int c;
};

bool operator<(const M& l, const M& r){
  return l.x < r.x;
}

int main(){
  cin >> n;
  vector<M> vm;
  for (int i = 0; i < n; ++i){
    int x, c;
    cin >> x >> c;
    M m = {x,c}; 
    vm.push_back(m);
  }
  sort(vm.begin(), vm.end());
  dp[0] = vm[0].c;
  for(int i = 1; i < n; ++i){
    ll m = INF;
    for(int j = 0; j < i; ++j){
      m = min(m, dp[j]);
    }
    dp[i] = m + vm[i].c;
    for(int j = 0; j < i; ++j){
      dp[j] += vm[i].x - vm[j].x;
    }
  }
  ll ans = INF;
  for(int i = 0; i < n; ++i){
    //    cout << dp[i] << " ";
    ans = min(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}