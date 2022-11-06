#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
typedef long long ll;

int n,a,d;
int t[100000];
int v[100000];

double calcTime(double mv){
  double dist = mv * mv / a / 2;
  if (dist >= d) {
    return sqrt(2.0*d/a);
  } else {
    return mv / a + (d - dist) / mv;
  }
}

int main(){
  scanf("%d %d %d", &n, &a, &d);
  double prev = 0.0;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", t+i, v+i);
    double time = t[i] + calcTime(v[i]);
    if (time < prev) {
      time = prev;
    }
    printf("%.8lf\n", time);
    prev = time;
  }
  return 0;
}