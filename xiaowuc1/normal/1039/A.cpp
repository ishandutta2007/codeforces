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

int n;
ll t;
ll l[200005];
ll ret[200005];
ll lhs[200005];
int order[200005];

int main() {
  scanf("%d%lld", &n, &t);
  for(int i = 0; i < n; i++) {
    scanf("%lld", &l[i]);
    ret[i] = l[i] + t;
    lhs[i] = (ll)(4e18);
  }
  queue<pii> q;
  for(int i = 0; i < n; i++) {
    scanf("%d", &order[i]);
    if(--order[i] < i) {
      printf("No\n");
      return 0;
    }
    if(i > 0 && order[i] < order[i-1]) {
      printf("No\n");
      return 0; 
    }
    if(order[i] > i) {
      q.push(pii(i+1, order[i]));
      if(order[i] < n-1) {
        lhs[order[i]] = l[order[i]+1] + t;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    while(!q.empty() && q.front().first <= i) {
      if(q.front().second >= i) {
        ret[i-1] = l[i] + t;
        break;
      }
      else {
        q.pop();
      }
    }
  }
  for(int i = 1; i < n; i++) {
    ret[i] = max(ret[i], ret[i-1]+1);
  }
  for(int i = 0; i < n; i++) {
    if(ret[i] >= lhs[i]) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  for(int i = 0; i < n; i++) {
    printf("%lld", ret[i]);
    if(i == n-1) printf("\n");
    else printf(" ");
  }
}