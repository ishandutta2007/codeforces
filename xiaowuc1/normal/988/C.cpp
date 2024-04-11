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
typedef long double ld;
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

int numSeq;
int l[200005];

map<int, map<int, int>> dp;
// sum -> (sequence number -> index number)

void readSeq(int seqNum) {
  int k;
  scanf("%d", &k);
  int totalSum = 0;
  for(int i = 0; i < k; i++) {
    scanf("%d", &l[i]);
    totalSum += l[i];
  }
  for(int i = 0; i < k; i++) {
    int attainableSum = totalSum - l[i];
    dp[attainableSum][seqNum] = i+1;
  }
}

/*
read in a sequence
generate all the possible sums for the sequence conditioned on removing exactly one number
see if a given sum is attainable in two different ways
*/

int main() {
  scanf("%d", &numSeq);
  for(int i = 1; i <= numSeq; i++) {
    readSeq(i);
  }
  for(auto out: dp) {
    map<int, int> cand = out.second;
    // sequence number -> index number
    if(cand.size() < 2) continue;
    printf("YES\n");
    int printed = 0;
    for(auto out2: cand) {
      printf("%d %d\n", out2.first, out2.second);
      if(++printed == 2) break;
    }
    return 0;
  }
  printf("NO\n");
  return 0;
}