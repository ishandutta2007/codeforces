#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int list[200005];
int zeroPrefix[200005];
int onePrefix[200005];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &list[i]);
    zeroPrefix[i+1] = zeroPrefix[i];
    onePrefix[i+1] = onePrefix[i];
    if(list[i] == 1) {
      onePrefix[i+1]++;
    }
    else {
      zeroPrefix[i+1]++;
    }
  }
  long long left = 0;
  long long right = 0;
  for(int i = 0; i < n; i++) {
    if(list[i] == 1) {
      left += zeroPrefix[n] - zeroPrefix[i+1];
    }
  }
  for(int i = n-1; i >= 0; i--) {
    if(list[i] == 0) {
      right += onePrefix[i];
    }
  }
  cout << min(left, right) << endl;
}