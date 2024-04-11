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

bool canReach[3005][3005];
vector<int> edges[3005];
int q[3005];

int n, m, qq;

const int MAX_DEPTH = 13;

int to[MAX_DEPTH][3005];

int ret[400005];

void resolveQueries(int dest, vector<pipii>& v) {
  // pipii is <from location, <index to ret, value inside>>
  memset(to, 0, sizeof(to));
  to[0][n+1] = n+1;
  for(int i = 1; i <= n; i++) {
    for(int out: edges[i]) {
      if(canReach[out][dest]) {
        to[0][i] = out;
        break;
      }
    }
  }
  to[0][dest] = n+1;
  for(int d = 1; d < MAX_DEPTH; d++) {
    for(int i = 1; i <= n+1; i++) {
      to[d][i] = to[d-1][to[d-1][i]];
    }
  }
  for(pipii out: v) {
    if(to[MAX_DEPTH-1][out.first] != n+1) {
      ret[out.second.first] = -1;
      continue;
    }
    int currLoc = out.first;
    int need = out.second.second;
    for(int a = MAX_DEPTH-1; a >= 0; a--) {
      if((1<<a) <= need) {
        need -= (1<<a);
        currLoc = to[a][currLoc];
      }
    }
    if(currLoc > n) currLoc = -1;
    ret[out.second.first] = currLoc;
  }
}

void initReach() {
  for(int i = 1; i <= n; i++) {
    int ql = 0;
    int qr = 0;
    q[qr++] = i;
    canReach[i][i] = true;
    while(ql < qr) {
      int curr = q[ql++];
      for(int out: edges[curr]) {
        if(!canReach[i][out]) {
          canReach[i][out] = true;
          q[qr++] = out;
        }
      }
    }
  }
}

vector<pipii> queries[3005];

int main() {
  scanf("%d%d%d", &n, &m, &qq);
  while(m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    edges[a].push_back(b);
  }
  for(int i = 1; i <= n; i++) {
    sort(edges[i].begin(), edges[i].end());
  }
  initReach();
  for(int i = 0; i < qq; i++) {
    int a, b, d;
    scanf("%d%d%d", &a, &b, &d);
    queries[b].push_back(pipii(a, pii(i, d-1)));
  }
  for(int i = 1; i <= n; i++) {
    if(queries[i].size()) {
      resolveQueries(i, queries[i]);
    }
  }
  for(int i = 0; i < qq; i++) {
    printf("%d\n", ret[i]);
  }
}