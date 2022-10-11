#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <memory>
#include <complex>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int l[500000];
int arr[1000005];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
  }
  int left = 0;
  int retL = 0;
  int retR = -1;
  int amt = 0;
  for(int i = 0; i < n; i++) {
    if(++arr[l[i]] == 1) amt++;
    while(amt > k) {
      if(--arr[l[left++]] == 0) {
        amt--;
      }
    }
    if(i - left > retR - retL) {
      retL = left;
      retR = i;
    }
  }
  printf("%d %d\n", ++retL, ++retR);
  return 0;
}