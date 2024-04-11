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
typedef long double ld;
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

/*
i, j, k

j-i == 2^d
k-j == 2^d
k-i == 2^(d+1)

d <= e
2^d + 2^e == 2^f
2^d (1 + 2^(e-d)) == 2^f
e == d

(i, j, k) is valid

fix middle element
loop over values of 2^d
check if (middle element - 2^d) exists and (middle element + 2^d) exists

*/

int n;
set<ll> v;
ll l[200005];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%lld", &l[i]);
    v.insert(l[i]);
  }
  vector<ll> r;
  for(int i = 0; i < n; i++) {
    for(int d = 0; d <= 33; d++) {
      vector<ll> c;
      c.push_back(l[i]);
      if(v.count(l[i] - (1LL << d))) {
        c.push_back(l[i] - (1LL << d));
      }
      if(v.count(l[i] + (1LL << d))) {
        c.push_back(l[i] + (1LL << d));
      }
      if(c.size() > r.size()) {
        r = c;
      }
    }
  }
  printf("%d\n", (int)r.size());
  for(int i = 0; i < r.size(); i++) {
    printf("%lld", r[i]);
    if(i == r.size()-1) printf("\n");
    else printf(" ");
  }
  return 0;
}