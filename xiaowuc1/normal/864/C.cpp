#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>


/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);
*/
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;
typedef pair<int, ppiipii> pippiipii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;

int main() {
  int a, b, f, k;
  scanf("%d%d%d%d", &a, &b, &f, &k);
  // 0 to a and back to 0;
  // b is fuel capacity
  // f is fuel station loc
  int currFuel = b;
  int ret = 0;
  for(int i = 0; i < k; i++) {
    int from = 0;
    int to = a;
    if(i%2) {
      from = a;
      to = 0;
    }
    int dist = abs(from - f);
    if(dist > currFuel) {
      printf("-1\n");
      return 0;
    }
    currFuel -= dist;
    if(i == k-1) {
      if(currFuel < abs(to-f)) {
        ret++;
        currFuel = b;
      }
      if(currFuel < abs(to - f)) {
        printf("-1\n");
        return 0;
      }
    }
    else {
      int nextUp = 2 * abs(to - f);
      if(currFuel < nextUp) {
        currFuel = b;
        ret++;
      }
      currFuel -= abs(to - f);
    }
  }
  printf("%d\n", ret);
  return 0;
}