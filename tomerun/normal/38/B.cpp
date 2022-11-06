#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cmath>
//#include "../myutil.hpp"

using namespace std;
const int INF = 1000000000;

bool b[8][8];
int dr[] = {1,2,2,1,-1,-2,-2,-1};
int dc[] = {2,1,-1,-2,-2,-1,1,2};


int main(){
  string s1,s2;
  cin >> s1 >> s2;
  int r1 = s1[0] - 'a';
  int c1 = s1[1] - '1';
  int r2 = s2[0] - 'a';
  int c2 = s2[1] - '1';
  b[r1][c1] = true;
  b[r2][c2] = true;
  for(int i = 0; i < 8; ++i){
    b[r1][i]= true;
    b[i][c1] = true;
    int kr = r2 + dr[i];
    int kc = c2 + dc[i];
    if(0 <= kr && kr < 8 && 0 <= kc && kc < 8){
      b[kr][kc] = true;
    }
  }
  int ans = 0;
  for(int i = 0; i < 8; ++i){
    for (int j = 0; j < 8; ++j){
      if(b[i][j]) continue;
      bool ok = true;
      for(int k = 0; k < 8; ++k) {
    int kr = i + dr[k];
    int kc = j + dc[k];
    if(kr == r1 && kc == c1 || kr == r2 && kc == c2){
      ok = false;
      break;
    }
      }
      if(ok) ++ans;
    }
  }
   cout << ans << endl;
  return 0;
}