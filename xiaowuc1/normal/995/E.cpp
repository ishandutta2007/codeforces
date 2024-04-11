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

map<int, int> rev;
map<int, int> uPar;
map<int, int> vPar;

int connection;

inline int modpow(ll b, ll e, ll m) {
  ll r = 1;
  while(e) {
    if(e%2) {
      r*=b;
      r%=m;
    }
    b*=b;
    b%=m;
    e/=2;
  }
  return r;
}

int p;

inline int getRev(int k) {
  if(!rev.count(k)) {
    rev[k] = modpow(k, p-2, p);
  }
  return rev[k];
}

void gen(vector<int>& x, map<int, int>& currM, map<int, int>& otherM) {
  vector<int> nextV;
  if(connection >= 0) return;
  for(int out: x) {
    int nd = (out+1)%p;
    if(!currM.count(nd)) {
      currM[nd] = out;
      nextV.push_back(nd);
    }
    if(otherM.count(nd)) {
      connection = nd;
      return;
    }
    nd = (out+p-1)%p;
    if(!currM.count(nd)) {
      currM[nd] = out;
      nextV.push_back(nd);
    }
    if(otherM.count(nd)) {
      connection = nd;
      return;
    }
    nd = getRev(out);
    if(!currM.count(nd)) {
      currM[nd] = out;
      nextV.push_back(nd);
    }
    if(otherM.count(nd)) {
      connection = nd;
      return;
    }
  }
  x.clear();
  for(int out: nextV) {
    x.push_back(out);
  }
}

int main() {
  int u, v;
  scanf("%d%d%d", &u, &v, &p);
  if(u == v) {
    printf("2\n1 2\n");
    return 0;
  }
  connection = -1;
  vector<int> us;
  vector<int> vs;
  uPar[u] = u;
  vPar[v] = v;
  us.push_back(u);
  vs.push_back(v);
  while(connection == -1) {
    gen(us, uPar, vPar);
    gen(vs, vPar, uPar);
  }
  stack<int> lhs;
  vector<int> rhs;
  {
    int uCurr = connection;
    while(uCurr != u) {
      int uu = uPar[uCurr];
      if((uu+1)%p == uCurr) {
        lhs.push(1);
      }
      else if((uu+p-1)%p == uCurr) {
        lhs.push(2);
      }
      else {
        lhs.push(3);
      }
      uCurr = uu;
    }
  }
  {
    int vCurr = connection;
    while(vCurr != v) {
      int vv = vPar[vCurr];
      if((vv+1)%p == vCurr) {
        rhs.push_back(2);
      }
      else if((vv+p-1)%p == vCurr) {
        rhs.push_back(1);
      }
      else {
        rhs.push_back(3);
      }
      vCurr = vv;
    }
  }
  vector<int> ret;
  while(!lhs.empty()) {
    ret.push_back(lhs.top());
    lhs.pop();
  }
  for(int out: rhs) {
    ret.push_back(out);
  }
  printf("%d\n", ret.size());
  for(int i = 0; i < ret.size(); i++) {
    printf("%d", ret[i]);
    if(i == ret.size()-1) printf("\n");
    else printf(" ");
  }
}