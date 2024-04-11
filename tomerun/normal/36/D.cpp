#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <fstream>
//#include "../myutil.hpp"

using namespace std;
const int INF = 1000000000;

fstream input("input.txt");

int k;

bool solve(int h, int w){
  int deg = min(h/(k+1),w/(k+1));
  int hr = h - deg*(k+1);
  int wr = w - deg*(k+1);
  if(hr == 0 || wr == 0){
    return true;
  }
  if(k == 1) {
    return (hr+wr) % 2 != 0;
  }
  return deg % 2 == 0 ? (hr+wr) % 2 != 0 : (hr+wr) % 2 == 0;
}

int main(){
  FILE* pf = fopen("output.txt", "a");
  fclose(pf);
  int t;
  input >> t >> k;
  int h,w;
  fstream output("output.txt");
  output.setf(ios::fixed);
  for(int i = 0; i < t; ++i) {
    input >> h >> w;
    output << (solve(h,w) ? '+' : '-') << endl;
  }
  return 0;
}