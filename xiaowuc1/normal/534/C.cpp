#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// DID YOU FIX GLOBAL STATE

typedef long long ll;
typedef pair<int, int> pii;

int n;
int d[200005];

/*
(N-1) -> D valid sums
value x is invalid iff the interval (N-1 + x) -> (D+x) does not contain A

D+x < A
N-1+x > A


(5, 12)
x there are such that (5, 12) + x < 20

(L, R) -> A
lowInvalid = A - R - 1
A = 20

(L, R) -> A
x such that (L, R) + x > A
minimum x (A - L + 1)
maximum x d[i]
d[i] - (A - L + 1) + 1
d[i] - A + L - 1 + 1
d[i] - A + L
*/

int main() {
  scanf("%d", &n);
  ll desiredSum;
  scanf("%lld", &desiredSum);
  ll totalSum = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
    totalSum += d[i];
  }
  for(int i = 0; i < n; i++) {
    ll lowest = n-1;
    ll highest = totalSum - d[i];
    ll lowInvalid = max(0LL, desiredSum - highest - 1);
    ll highInvalid = max(0LL, d[i] - desiredSum + lowest);
    printf("%lld ", lowInvalid + highInvalid);
  }
  printf("\n");
  return 0;
}