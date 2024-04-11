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
typedef vector<ll> vi;
const ll INF = 1 << 30;
int N,M;
ll L[1500][1500];

int main(){
  cin >> N >> M;
  int v;
  for(int i = 0; i < N; ++i){
    ll sum = 0;
    for(int j = 0; j < M; ++j){
      scanf("%d", &v);
      sum += v;
      L[i][j] = sum;
    }
  }
  vi cur(L[0], L[M]);
  vi next(M);
  for(int i = 1; i < N; ++i){
    if(i % 2 == 0) {
      next[0] = -INF;
      ll opt = -INF;
      for(int j = 1; j < M; ++j){
    opt = max(opt, cur[j-1]);
    next[j] = L[i][j] + opt;
      }
    }else{
      next[M-1] = -INF;
      ll opt = -INF;
      for(int j = M-2; j >= 0; --j){
    opt = max(opt, cur[j+1]);
    next[j] = L[i][j] + opt;
      }
    }
    swap(cur, next);
//     for(int j = 0; j< M; ++j){
//       cout << cur[j] << " ";
//     }
//     cout << endl;
  }
  ll ans = -INF;
  for(int i = 0; i < M; ++i){
    ans = max(ans, cur[i]);
  }
  cout << ans << endl;
  return 0;
}