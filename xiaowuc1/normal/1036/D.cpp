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

queue<ll> lhs;
queue<ll> rhs;

void load(queue<ll>& q) {
  int n;
  scanf("%d", &n);
  while(n--) {
    ll t;
    scanf("%lld", &t);
    q.push(t);
  }
}

void gg() {
  printf("-1\n");
  exit(0);
}

int main() {
  load(lhs);
  load(rhs);
  int ret = 0;
  while(!lhs.empty() || !rhs.empty()) {
    if(lhs.empty() || rhs.empty()) {
      gg();
    }
    ll go = lhs.front() - rhs.front();
    lhs.pop();
    rhs.pop();
    ret++;
    while(go) {
      if(go < 0) {
        if(lhs.empty()) {
          gg();
        }
        go += lhs.front();
        lhs.pop();
      }
      else {
        if(rhs.empty()) {
          gg();
        }
        go -= rhs.front();
        rhs.pop();
      }
    }
  }
  printf("%d\n", ret);
}