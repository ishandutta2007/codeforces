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
int a,b,c,d,e,f;

bool solve(){
  if(a*c*e < b*d*f) return true;
  if(a == 0) {
    if(b != 0 && d != 0) return true;
  }
  if(c == 0) {
    if(d != 0) return true;
  }
  if(e == 0) {
    if(f != 0 && b != 0 && d != 0) return true;
  }
  return false;
}

int main(){
  cin >> a >> b >> c >> d >> e >> f;
  cout << (solve() ? "Ron" : "Hermione") << endl;

}