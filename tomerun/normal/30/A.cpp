#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cmath>

using namespace std;

int a, b, n;

void solve(){
  for(int i = -1000; i <= 1000; ++i){
    int v = a;
    for(int j = 0; j < n; ++j){
      v *= i;
      if(abs(v) > abs(b)){
	break;
      }
    }
    if(v == b){
      cout << i;
      return;
    }
  }
  cout << "No solution";
}

int main(){
  cin >> a >> b >> n;
  solve();
  return 0;
}