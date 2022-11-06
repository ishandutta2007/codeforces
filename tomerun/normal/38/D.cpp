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
const double EPS = 1e-8;

int n;
int x[100];
int y[100];
int a[100];
int w[100];

int solve(){
  for(int i = 0; i < n; ++i){
    int sw = 0;
    double sx = 0;
    double sy = 0;
    for(int j = i; j > 0; --j) {
      sw += w[j];
      sx += w[j] * (x[j] + a[j] / 2.0);
      sy += w[j] * (y[j] + a[j] / 2.0);
      double cx = sx / sw;
      double cy = sy / sw;
      //      cout << i << " " << j << " " << cx << " " << cy << endl;
      if(cx + EPS < x[j-1] || x[j-1] + a[j-1] < cx - EPS || cy + EPS < y[j-1] || y[j-1] + a[j-1] < cy - EPS){
    return i;
      }
    }
  }
  return n;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x[i] = min(x1, x2);
    y[i] = min(y1, y2);
    a[i] = abs(x2 - x1);
    w[i] = a[i]*a[i]*a[i];
  }
  cout << solve() << endl;
  return 0;
}