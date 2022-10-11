#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;
bool g[105][105];

int main() {
  int k;
  scanf("%d", &k);
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < i; j++) {
      int a = 0;
      for(int x = 0; x < 100; x++) {
        if(g[i][x] && g[x][j]) {
          a++;
        }
      }
      if(a <= k) {
        k -= a;
        g[i][j] = true;
        g[j][i] = true;
      }
    }
  }
  printf("100\n");
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      if(g[i][j]) printf("1");
      else printf("0");
    }
    printf("\n");
  }
}