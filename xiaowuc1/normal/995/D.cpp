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
typedef long double ld;

int val[1<<18];
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  ll s = 0;
  for(int i = 0; i < (1<<n); i++) {
    scanf("%d", &val[i]);
    s += val[i];
  }
  printf("%.9f\n", s / (double)(1 << n));
  while(q--) {
    int idx, v;
    scanf("%d%d", &idx, &v);
    s -= val[idx];
    val[idx] = v;
    s += val[idx];
    printf("%.9f\n", s / (double)(1 << n));
  }
}