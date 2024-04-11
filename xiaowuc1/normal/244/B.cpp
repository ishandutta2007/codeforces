#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  set<long long> ret;
  for(int i = 1; i <= 9; i++) {
    for(int j = 0; j <= 9; j++) {
      for(int len = 1; len <= 10; len++) {
	for(int mask = 0; mask < 1 << len; mask++) {
	  long long curr = 0;
	  for(int k = 0; k < len; k++) {
	    curr *= 10;
	    if((mask&(1<<k))!=0) {
	      curr += i;
	    }
	    else {
	      curr += j;
	    }
	  }
	  if(curr <= n && curr > 0) {
	    ret.insert(curr);
	  }
	}
      }
    }
  }
  printf("%d\n", ret.size());
}