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
int l[1000000];
char buf[1000000];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
  }
  scanf("\n%s", buf);
  int lhs = -1000000000;
  int rhs = 1000000000;
  for(int i = 4; i < n; i++) {
    if(buf[i] == buf[i-1]) continue;
    if(buf[i] == '1') {
      int pmt = l[i];
      pmt = max(pmt, l[i-1]);
      pmt = max(pmt, l[i-2]);
      pmt = max(pmt, l[i-3]);
      pmt = max(pmt, l[i-4]);
      lhs = max(lhs, pmt+1);
    }
    else {
      int pmt = l[i];
      pmt = min(pmt, l[i-1]);
      pmt = min(pmt, l[i-2]);
      pmt = min(pmt, l[i-3]);
      pmt = min(pmt, l[i-4]);
      rhs = min(rhs, pmt-1);
    }
  }
  printf("%d %d\n", lhs, rhs);
}