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

int n, k;
char buf[1000000];
set<char> v;

char ret[1000000];

void printAnswer() {
  ret[k] = 0;
  printf("%s\n", ret);
  exit(0);
}

void dfs(int idx, bool beat) {
  if(idx == k) {
    if(beat) printAnswer();
    return;
  }
  for(char ch = idx >= n || beat ? 'a' : buf[idx]; ch <= 'z'; ch++) {
    if(!v.count(ch)) continue;
    ret[idx] = ch;
    dfs(idx+1, beat || idx >= n || ch > buf[idx]);
  }
}

int main() {  
  scanf("%d %d\n%s", &n, &k, buf);
  for(int i = 0; i < n; i++) {
    v.insert(buf[i]);
  }
  dfs(0, false);
}