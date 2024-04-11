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

int n;
int present[200005];
bool handled[200005];
int l[200005];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
    present[l[i]]++;
  }
  int ret = 0;
  int insert = 1;
  int lhs = 0;
  while(insert <= n) {
    if(present[insert] >= 1) {
      insert++;
      continue;
    }
    while(true) {
      if(present[l[lhs]] == 1) {
        // unique
        lhs++;
        continue;
      }
      assert(present[l[lhs]]); // should appear
      if(insert < l[lhs]) { // improve
        ret++;
        present[l[lhs]]--;
        l[lhs] = insert;
        lhs++;
        insert++;
        break;
      }
      if(handled[l[lhs]]) { // must knock out, knock out now
        ret++;
        present[l[lhs]]--;
        l[lhs] = insert;
        lhs++;
        insert++;
        break;
      }
      handled[l[lhs]] = true;
      lhs++;
    }
  }

  // print answer
  printf("%d\n", ret);
  for(int i = 0; i < n; i++) {
    printf("%d", l[i]);
    if(i == n-1) printf("\n");
    else printf(" ");
  }
  return 0;
}