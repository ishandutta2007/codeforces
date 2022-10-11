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

int amt[105];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    amt[t]++;
  }
  vector<int> ret;
  for(int i = 0; i <= 100; i++) {
    if(2*amt[i] == n) {
      ret.push_back(i);
    }
  }
  if(ret.size() != 2) {
    printf("NO\n");
  }
  else {
    printf("YES\n%d %d\n", ret[0], ret[1]);
  }
}