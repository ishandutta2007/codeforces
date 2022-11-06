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
  int cur = 0;
  for(int i = 1; i < n; ++i){
    cur = (cur + i) % n;
    cout << cur+1 << " ";
  }
  cout << endl;
}