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


int ragetreemax[300005 * 4];
ll ragetreesum[300005 * 4];
int ragetreelazy[300005 * 4];
bool ragetreemustupdate[300005 * 4];

int tau[1000005];

void initTau() {
  for(int x = 1; x <= 1000000; x++) {
    for(int y = x; y <= 1000000; y += x) {
      tau[y]++;
    }
  }
}

int origList[300005];
int n;
void ragetreeinit(int idx, int lhs, int rhs) {
  if(lhs == rhs) {
    ragetreesum[idx] = origList[lhs];
    ragetreemax[idx] = origList[lhs];
  }
  else {
    int mid = (lhs+rhs)/2;
    ragetreeinit(2*idx, lhs, mid);
    ragetreeinit(2*idx+1, mid+1, rhs);
    ragetreemax[idx] = max(ragetreemax[2*idx], ragetreemax[2*idx+1]);
    ragetreesum[idx] = ragetreesum[2*idx] + ragetreesum[2*idx+1];
  }
}
void ragetreeinit() {
  ragetreeinit(1, 0, n-1);
}

void ragetreepushdown(int idx, int lhs, int rhs) {
  if(ragetreelazy[idx]) {
    ragetreelazy[2*idx] += ragetreelazy[idx];
    ragetreelazy[2*idx+1] += ragetreelazy[idx];
    ragetreelazy[idx] = 0;
  }
}

void ragetreepullup(int idx, int lhs, int rhs) {
  ragetreemax[idx] = max(ragetreemax[2*idx], ragetreemax[2*idx+1]);
  ragetreesum[idx] = ragetreesum[2*idx] + ragetreesum[2*idx+1];
  ragetreemustupdate[idx] = ragetreelazy[idx] > 0 || ragetreelazy[2*idx] > 0 || ragetreelazy[2*idx+1] > 0 || ragetreemustupdate[2*idx] || ragetreemustupdate[2*idx+1];
}

void ragetreeupdate(int idx, int tl, int tr, int lhs, int rhs) {
  if(ragetreemax[idx] <= 2) return;
  if(tl >= lhs && tr <= rhs) {
    ragetreelazy[idx]++;
  }
  else {
    ragetreepushdown(idx, tl, tr);
    int mid = (tl+tr)/2;
    if(mid >= lhs)
      ragetreeupdate(2*idx, tl, mid, lhs, rhs);
    if(mid+1 <= rhs)
      ragetreeupdate(2*idx+1, mid+1, tr, lhs, rhs);
    ragetreepullup(idx, tl, tr);
  }
}

void ragetreeupdate(int lhs, int rhs) {
  ragetreeupdate(1, 0, n-1, lhs, rhs);
}

ll ragetreequery(int idx, int tl, int tr, int lhs, int rhs) {
  if(tl >= lhs && tr <= rhs && ragetreelazy[idx] == 0 && !ragetreemustupdate[idx]) {
    return ragetreesum[idx];
  }
  else if(tl == tr) {
    int curr = ragetreesum[idx];
    while(ragetreelazy[idx]-- && curr > 2) {
      curr = tau[curr];
    }
    ragetreemax[idx] = curr;
    ragetreesum[idx] = curr;
    ragetreelazy[idx] = 0;
    ragetreemustupdate[idx] = false;
    return curr;
  }
  else {
    ragetreepushdown(idx, tl, tr);
    ll ret = 0;
    int mid = (tl+tr)/2;
    if(mid >= lhs)
      ret += ragetreequery(2*idx, tl, mid, lhs, rhs);
    if(mid+1 <= rhs)
      ret += ragetreequery(2*idx+1, mid+1, tr, lhs, rhs);
    ragetreepullup(idx, tl, tr);
    return ret;
  }
}

ll ragetreequery(int lhs, int rhs) {
  return ragetreequery(1, 0, n-1, lhs, rhs);
}

int main() {
  int q;
  scanf("%d%d", &n, &q);
  for(int i = 0; i < n; i++) {
    scanf("%d", &origList[i]);
  }
  ragetreeinit();
  initTau();
  while(q--) {
    int t, lhs, rhs;
    scanf("%d%d%d", &t, &lhs, &rhs);
    lhs--;
    rhs--;
    if(t == 1) {
      ragetreeupdate(lhs, rhs);
    }
    else {
      printf("%lld\n", ragetreequery(lhs, rhs));
    }
  }
}