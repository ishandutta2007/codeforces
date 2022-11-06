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
  int n;
  cin >> n;
  vector<int> v;
  v.push_back(0);
  for(int i = 0; i < n-1; ++i) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  int c,t;
  cin >> c >> t;
  int ans = 0;
  for (int i = c; i < t; ++i){
    ans += v[i];
  }
  cout << ans << endl;
  return 0;
}