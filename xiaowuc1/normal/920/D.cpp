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

int l[5005];
int n, k, v;

int dp[5005];

bool use[5005];

int main() {
  scanf("%d%d%d", &n, &k, &v);
  for(int a = 1; a < k; a++) {
    dp[a] = -1;
  }
  int tot = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
    tot += l[i];
    for(int a = 0; a < k; a++) {
      if(dp[a] < 0 || dp[a] == i+1) continue;
      int na = (a + l[i]) % k;
      if(dp[na] <= 0)
        dp[na] = i+1;
    }
  }
  if(v == 0) {
    printf("YES\n");
    for(int i = 1; i < n; i++) {
      if(l[i] == 0) continue;
      printf("%d %d %d\n", (l[i] + k - 1) / k, i+1, 1);
    }
    return 0;
  }
  if(tot < v) {
    printf("NO\n");
    return 0;
  }
  if(v%k == 0) {
    printf("YES\n");
    for(int i = 1; i < n; i++) {
      if(l[i] == 0) continue;
      printf("%d %d %d\n", (l[i] + k - 1) / k, i+1, 1);
      l[0] += l[i];
      l[i] = 0;
    }
    printf("%d %d %d\n", v/k, 1, n);
    return 0;
  }
  if(dp[v%k] < 0) {
    printf("NO\n");
    return 0;
  }
  set<int> valid;
  valid.insert(dp[v%k]-1);
  int curr = 2*k + (v%k) - (l[dp[v%k]-1] % k);
  curr %= k;
  while(curr) {
    int next = dp[curr]-1;
    valid.insert(next);
    curr = (curr + k - l[dp[curr]-1]) % k;
    curr += k;
    curr %= k;
  }
  for(int out: valid) {
    use[out] = true;
  }
  int goodMergeInto = 0;
  while(goodMergeInto < n && !use[goodMergeInto]) goodMergeInto++;
  int badMergeInto = 0;
  while(badMergeInto < n && use[badMergeInto]) badMergeInto++;
  if(badMergeInto == n) {
    badMergeInto = -1;
  }
  // merge all use into goodmergeinto
  // merge all nonuse into badMergeInto
  vector<pipii> ret;
  // cnt x y
  for(int i = 0; i < n; i++) {
    if(i == goodMergeInto || i == badMergeInto) continue;
    int consume = (l[i] + k-1) / k;
    if(consume == 0) continue;
    if(use[i]) {
      ret.push_back(pipii(consume, pii(i+1, goodMergeInto+1)));
      l[goodMergeInto] += l[i];
      l[i] = 0;
    }
    else {
      ret.push_back(pipii(consume, pii(i+1, badMergeInto+1)));
      l[badMergeInto] += l[i];
      l[i] = 0;
    }
  }
  if(badMergeInto == -1) {
    badMergeInto = (goodMergeInto+1)%n;
  }
  // throw maximally
  int throws = l[badMergeInto] / k;
  if(throws) {
    ret.push_back(pipii(throws, pii(badMergeInto+1, goodMergeInto+1)));
    l[goodMergeInto] += throws * k;
    l[badMergeInto] -= throws * k;
  }
  // throw away
  throws = (l[goodMergeInto] - v) / k;
  if(throws) {
    ret.push_back(pipii(throws, pii(goodMergeInto+1, badMergeInto+1)));
  }
  printf("YES\n");
  for(pipii out: ret) {
    if(out.first == 0) continue;
    printf("%d %d %d\n", out.first, out.second.first, out.second.second);
  }
}