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
set<int> edges[1000000];

int q[1000000];
int seen[1000000];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    edges[x].insert(y);
    edges[y].insert(x);
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", &q[i]);
  }
  if(q[0] != 1) {
    printf("No\n");
    return 0;
  }
  int nextCand = 0;
  for(int i = 0; i < n; i++) {
    nextCand = max(nextCand, i+1);
    while(nextCand < n && edges[q[i]].count(q[nextCand])) {
      seen[q[i]]++;
      seen[q[nextCand]]++;
      nextCand++;
    }
    if(seen[q[i]] != edges[q[i]].size()) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
}