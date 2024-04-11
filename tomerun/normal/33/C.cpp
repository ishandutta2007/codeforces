#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cmath>
//#include "../myutil.hpp"

using namespace std;
const int INF = 1000000000;


int main(){
  int N;
  cin >> N;
  vector<int> v;
  v.reserve(N);
  for(int i = 0; i < N; ++i) {
    int num;
    cin >> num;
    v.push_back(num);
  }
  vector<int> maxPre(N+1);
  int accum = 0;
  for(int i = 0; i < N; ++i) {
    accum += v[i] * -2;
    maxPre[i+1] = max(maxPre[i], accum);
  }
  accum = 0;
  int maxD = maxPre[N];
  for(int i = 0; i < N; ++i) {
    accum += v[N-1-i] * -2;
    maxD = max(accum + maxPre[N-1-i], maxD);
  }
  int ans = maxD;
  for (int i = 0; i < N; ++i) {
    ans += v[i];
  }
  cout << ans;
  return 0;
}