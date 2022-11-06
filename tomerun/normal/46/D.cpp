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
int L,B,F,N;

struct Car{
  int pos;
  int len;
  int index;
};

ostream& operator<<(ostream& stm, Car& car) {
  stm << car.pos << " " << car.len << " " << car.index << endl;
  return stm;
}

int main(){
  cin >> L >> B >> F >> N;
  vector<Car> parked;
  int type;
  int prop;
  for(int i = 0; i < N; ++i){
//     cout << i << ":" << endl;
//     for(int j = 0; j < parked.size(); ++j){
//       cout << parked[j];
//     }
//     cout << endl;
    cin >> type >> prop;
    if(type == 1) {
      int lot = -1;
      int insp = -1;
      if(parked.empty()){
    if (prop <= L){
      lot = 0;
      insp = 0;
    }
      }else {
    if(parked[0].pos >= prop + F) {
      lot = 0;
      insp = 0;
    }else{
      for(int j = 0; j < parked.size() - 1; ++j){
        if (parked[j+1].pos - (parked[j].pos + parked[j].len) >= prop + B + F) {
          lot = parked[j].pos + parked[j].len + B;
          insp = j+1;
          break;
        }
      }
    }
    if(lot == -1 && parked.back().pos + parked.back().len + B <= L - prop) {
      lot = parked.back().pos + parked.back().len + B;
      insp = parked.size();
    }
      }
      cout << lot << endl;
      if(lot >= 0) {
    Car ins = {lot, prop, i+1};
    parked.insert(parked.begin() + insp, ins);
      }
    }else{
      for(int j = 0; j < parked.size(); ++j){
    if(parked[j].index == prop) {
      parked.erase(parked.begin() + j);
      break;
    }
      }
    }
  }
}