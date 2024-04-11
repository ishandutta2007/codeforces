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

using namespace std;
const int INF = 1000000000;



int main(){
  int n,l;
  cin >> n >> l;
  int ans = 0;
  vector<int> a;
  for(int i = 0; i < n; ++i){
    int ai;
    cin >> ai;
    a.push_back(ai);
  }
  for(int i = l; i <= 100; ++i){
    int sum = 0;
    for(int j = 0; j < n; ++j) {
      sum += a[j] / i * i;
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}