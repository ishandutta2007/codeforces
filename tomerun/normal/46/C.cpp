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

int main(){
  int n;
  cin >> n;
  string str;
  cin >> str;
  int hc = 0;
  for(int i = 0; i < n; ++i){
    if (str[i] == 'H') ++hc;
  }
  int ans = n;
  for(int i = 0; i < n; ++i){
    int tc = 0;
    for(int j = 0; j < hc; ++j){
      if(str[(i+j)%n] == 'T') ++tc;
    }
    ans = min(ans, tc);
  }
  cout << ans << endl;
}