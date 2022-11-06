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

int main(){
  FILE* pf = fopen("output.txt", "a");
  fclose(pf);
  int N;
  string str;
  input >> N >> str;
  int pos = 0;
  while(str[pos] != '1') ++pos;
  int pos1 = pos;
  ++pos;
  while(str[pos] != '1') ++pos;
  int pos2 = pos;
  int interval = pos2 - pos1;
  ++pos;
  bool result = true;
  bool end = false;
  //  cerr << pos1 << " " << pos2 << " " << interval << endl;
  for(int c = 1; pos < N; ++pos, ++c){
    if(c % interval == 0) {
      if(str[pos] == '0') {
    end = true;
      } else {
    if(end) {
      result = false;
      break;
    }
      }
    } else{
      if(str[pos] == '1') {
    result = false;
    break;
      }
    }
  }
  fstream output("output.txt");
  output << (result ? "YES" : "NO") << endl;
  return 0;
}