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

int n, k;
int ratingToId[105];

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; i++) {
    int rating;
    scanf("%d", &rating);
    ratingToId[rating] = i;
  }
  vector<int> reps;
  for(int i = 1; i <= 100; i++) {
    if(ratingToId[i]) {
      reps.push_back(ratingToId[i]);
    }
  }
  if(reps.size() < k) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  for(int i = 0; i < k; i++) {
    printf("%d", reps[i]);
    if(i == k-1) printf("\n");
    else printf(" ");
  }
  return 0;
}