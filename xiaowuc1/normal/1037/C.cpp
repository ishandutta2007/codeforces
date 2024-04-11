#include <algorithm>
#include <cassert>
// #include <chrono>
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
// #include <random>
#include <set>
#include <stack>
#include <string>
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
typedef pair<string, string> pss;
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef long double ld;

int n;
char a[2000000];
char b[2000000];

int main() {
  int n;
  scanf("%d\n%s%s", &n, a, b);
  int ret = 0;
  for(int i = 0; i < n;) {
    if(a[i] == b[i]) {
      i++;
      continue;
    }
    // end
    if(i+1 == n) {
      ret++;
      i++;
      continue;
    }
    if(a[i] == b[i+1] && a[i+1] == b[i]) {
      i += 2;
      ret++;
      continue;
    }
    i++;
    ret++;
  }
  printf("%d\n", ret);
}