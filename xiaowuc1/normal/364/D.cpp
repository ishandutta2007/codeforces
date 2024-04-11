#include <iostream>
#include <memory>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <ctime>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <random>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<int, pipii> pipipii;

// https://dmoj.ca/problem/ccc17s5

ll l[1000005];
ll ret;
int n;

ll gcd(ll a, ll b) {
  return a%b==0 ? b : gcd(b, a%b);
}

ll factors[100000];
ll win[100000];
int factorCount = 0;

void solve(int idx) {
  factorCount = 0;
  memset(win, 0, sizeof(win));
  for(int i = 1; i * 1LL * i <= l[idx]; i++) {
    if(l[idx]%i == 0) {
      factors[factorCount++] = i;
      ll amt = l[idx] / i;
      if(amt != i) {
        factors[factorCount++] = amt;
      }
    }
  }
  sort(factors, factors+factorCount);
  for(int i = 0; i < n; i++) {
    ll goal = gcd(l[i], l[idx]);
    int lhs = 0;
    int rhs = (factorCount-1);
    while(lhs != rhs) {
      int mid = (lhs+rhs)/2;
      if(factors[mid] == goal) {
        lhs = mid;
        rhs = mid;
      }
      else if(factors[mid] < goal) {
        lhs = mid+1;
      }
      else {
        rhs = mid-1;
      }
    }
    assert(factors[lhs] == goal);
    win[lhs]++;
  }
  for(int a = 0; a < factorCount; a++) {
    if(factors[a] <= ret) continue;
    for(int b = a+1; 2*win[a] < n && b < factorCount; b++) {
      if(factors[b] % factors[a] == 0) {
        win[a] += win[b];
      }
    }
    if(2*win[a] >= n) {
      ret = factors[a];
    }
  }
}

int main() {
  mt19937 mt_rand(0);
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%lld", &l[i]);
  }
  sort(l, l+n);
  ret = 1;
  for(int iter = 0; iter < 6; iter++) {
    solve(mt_rand() % n);
  }
  printf("%lld\n", ret);
}