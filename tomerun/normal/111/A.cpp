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
  ll n,x,y;
  cin >> n >> x >> y;
  ll sum = (y - (n-1))*(y - (n-1)) + n-1;
  if (sum >= x && y >= n) {
    printf("%lld", y - (n-1));
    for (int i  = 0; i < n-1; ++i) {
      printf(" 1");
    }
    printf("\n");
  } else {
    printf("-1\n");
  }
}