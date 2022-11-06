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
int n;
vi x;
vi y;
vi z;
int vp,vs;
int px,py,pz;
double t;

double len(double a, double b, double c){
  return sqrt(a*a + b*b + c*c);
}

double len2(double a, double b, double c){
  return (a*a + b*b + c*c);
}

bool canGo(double time, double x, double y, double z){
  return len2(px - x, py - y, pz - z) <= time * time * vp * vp + 1e-10;
}

vector<double> solveLine(int i){
  vector<double> ret;
  double dx = x[i+1] - x[i];
  double dy = y[i+1] - y[i];
  double dz = z[i+1] - z[i];
  double l = len(dx, dy, dz);
  double nextTime = t + l / vs;
  if (!canGo(nextTime, x[i+1], y[i+1], z[i+1])) {
    t += l / vs;
    return ret;
  }
  double left = 0.0;
  double right = 1.0;
  for(int j = 0; j < 1000; ++j){
    double mid = (left + right) / 2;
    if(canGo(t + l / vs * mid, x[i] + dx * mid, y[i] + dy * mid, z[i] + dz * mid)) {
      right = mid;
    } else {
      left = mid;
    }
    //    cout << mid << endl;
  }
  ret.push_back(t + l / vs * left);
  ret.push_back(x[i] + dx * left);
  ret.push_back(y[i] + dy * left);
  ret.push_back(z[i] + dz * left);
  return ret;
}

vector<double> solve(){
  for(int i = 0; i < n; ++i) {
    vector<double> result = solveLine(i);
    if(!result.empty()) {
      return result;
    }
  }
  return vector<double>();
}

int main(){
  scanf("%d", &n);
  t = 0.0;
  x.clear();
  y.clear();
  z.clear();
  int xi,yi,zi;
  for(int i = 0; i <= n; ++i) {
    scanf("%d %d %d", &xi, &yi, &zi);
    x.push_back(xi);
    y.push_back(yi);
    z.push_back(zi);
  }
  scanf("%d %d", &vp, &vs);
  scanf("%d %d %d", &px, &py, &pz);
  vector<double> result = solve();
  if(result.empty()) {
    printf("NO\n");
  } else {
    printf("YES\n");
    printf("%.10lf\n", result[0]);
    printf("%.10lf %.10lf %.10lf\n", result[1], result[2], result[3]);
  }
}