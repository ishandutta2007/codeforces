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
  int count[5];
  for(int i = 0; i < 5; ++i){
    cin >> count[i];
  }
  int k = 0;
  cin >> k;
  string size;
  for(int i = 0; i < k; ++i){
    cin >> size;
    int cur;
    if(size == "S"){
      cur = 0;
    } else if (size == "M"){
      cur = 1;
    } else if (size == "L"){
      cur = 2;
    } else if (size == "XL"){
      cur = 3;
    } else if (size == "XXL"){
      cur = 4;
    }
    int ans = cur;
    for(int i = 0; i < 5; ++i){
      int pos = cur + i;
      if(0 <= pos && pos < 5 && count[pos] > 0){
    ans = pos;
    break;
      }
      pos = cur - i;
      if(0 <= pos && pos < 5 && count[pos] > 0){
    ans = pos;
    break;
      }
    }
    count[ans]--;
    if(ans == 0) {
      cout << "S";
    }else if(ans == 1) {
      cout << "M";
    }else if(ans == 2) {
      cout << "L";
    }else if(ans == 3) {
      cout << "XL";
    }else if(ans == 4) {
      cout << "XXL";
    }
    cout << endl;
  }
}