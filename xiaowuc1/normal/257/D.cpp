#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>

#define PI 2*atan2(1,0)

using namespace std;

int main() {
  long long list[100005];
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for(int i = 0; i < n; i++) {
    int curr;
    scanf("%d", &curr);
    list[i] = (long long)curr;
    sum += curr;
  }
  char ret[100005];
  long long curr = 0;
  for(int i = n-1; i >= 0; i--) {
    if(curr >= 0) {
      curr -= list[i];
      ret[i] = '-';
    }
    else {
      curr += list[i];
      ret[i] = '+';
    }
  }
  if(curr < 0) {
    for(int i = 0; i < n; i++) {
      if(ret[i] == '+') {
	ret[i] = '-';
      }
      else {
	ret[i] = '+';
      }
    }
  }
  for(int i = 0; i < n; i++) {
    printf("%c", ret[i]);
  }
  return 0;
}