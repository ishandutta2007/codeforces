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
  vector<ll> v;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    ll l;
    cin >> l;
    v.push_back(l);
  }
  ll ans = n;
  for(int i = 0; i < n; ++i) {
    ans += (i+1) * (v[i] - 1);
  }
  cout << ans << endl;
}