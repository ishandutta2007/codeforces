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

const double PI = 2 * acos(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

const int MOD = 1000000007;

int n;
char buf[100005];

int valid() {
  int len = strlen(buf);
  if(buf[0] != '1') return -1;
  for(int i = 1; i < len; i++) {
    if(buf[i] != '0') return -1;
  }
  return len-1;
}

void solve() {
  int n;
  scanf("%d\n", &n);
  int numZero = 0;
  string pref = "";
  for(int i = 0; i < n; i++) {
    scanf("%s", buf);
    if(buf[0] == '0') {
      printf("0\n");
      return;
    }
    int add = valid();
    if(add == -1) {
      pref = string(buf);
    }
    else {
      numZero += add;
    }
  }
  if(pref.size() == 0) {
    pref = "1";
  }
  printf("%s", pref.c_str());
  while(numZero--) printf("0");
  printf("\n");
}

int main() {
  solve();
  return 0;
}