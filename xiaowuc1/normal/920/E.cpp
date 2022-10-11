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

int n, m;
set<int> bad[200005];
vector<int> ret;
vector<pii> order;

bool seen[200005];
vector<int> explicitFree;

void solve(int cand) {
  if(seen[cand]) return;
  int sz = 0;
  seen[cand] = true;
  queue<int> q;
  q.push(cand);
  while(!q.empty()) {
    int curr = q.front();
    sz++;
    q.pop();
    vector<int> nexp;
    for(int out: explicitFree) {
      if(seen[out]) continue;
      if(bad[curr].count(out)) {
        nexp.push_back(out);
      }
      else {
        seen[out] = true;
        q.push(out);
      }
    }
    explicitFree = nexp;
  }
  ret.push_back(sz);
}

int main() {
  scanf("%d%d", &n, &m);
  while(m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    bad[a].insert(b);
    bad[b].insert(a);
  }
  for(int i = 1; i <= n; i++) {
    explicitFree.push_back(i);
    order.push_back(pii(bad[i].size(), i));
  }
  sort(order.begin(), order.end());
  for(pii out: order) {
    solve(out.second);
  }
  printf("%d\n", ret.size());
  sort(ret.begin(), ret.end());
  for(int i = 0; i < ret.size(); i++) {
    printf("%d", ret[i]);
    if(i == ret.size()-1) printf("\n");
    else printf(" ");
  }
  return 0;
}