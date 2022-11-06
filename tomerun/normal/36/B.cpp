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
bool rule[3][3];
int k;
int n;
int size;

bool black(int r, int c, int d, int len){
  if(d == k) return false;
  int l = len / n;
  int rr = r / l;
  int cc = c / l;
  if(rule[rr][cc]) {
    return true;
  }else {
    return black(r % l, c % l, d+1, len / n);
  }
}

int main(){
  FILE* pf = fopen("output.txt", "a");
  fclose(pf);
  input >> n >> k;
  string line;
  for(int i = 0; i < n; ++i) {
    input >> line;
    for(int j = 0; j < n; ++j) {
      rule[i][j] = line[j] == '*';
    }
  }
  fstream output("output.txt");
  size = 1;
  for(int i = 0; i < k; ++i) {
    size *= n;
  }
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j){
      output << (black(i, j, 0, size) ? '*' : '.');
    }
    output << endl;
  }
  return 0;
}