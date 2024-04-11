#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int find(int lhs, int rhs, int goal) {
  if(lhs == rhs) return lhs;
  int mid = (lhs + rhs) / 2;
  printf("1 %d 1", (mid-lhs+1));
  for(int i = lhs; i <= mid; i++) printf(" %d", i);
  printf("\n"); fflush(stdout);
  int want;
  scanf("%d", &want); assert(want > 0);
  if(want == goal) return find(lhs, mid, goal);
  else return find(mid+1, rhs, goal);
}

void solve() {
  int n;
  scanf("%d", &n);
  printf("1 %d", n-1);
  for(int i = 1; i <= n; i++) {
    printf(" %d", i);
  }
  printf("\n"); fflush(stdout);
  int want;
  scanf("%d", &want); assert(want > 0);
  int leaf = find(2, n, want);
  printf("1 %d %d", n-1, leaf);
  for(int i = 1; i <= n; i++) {
    if(i == leaf) continue;
    printf(" %d", i);
  }
  printf("\n"); fflush(stdout);
  scanf("%d", &want); assert(want > 0);
  printf("-1 %d\n", want); fflush(stdout);
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL); cout.tie(NULL);
  int t;
  scanf("%d", &t);
  while(t--) solve();
}