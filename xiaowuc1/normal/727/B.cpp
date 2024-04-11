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

char buf[1005];

void solve() {
  ll numCents = 0;
  gets(buf);
  int len = strlen(buf);
  for(int i = 0; i < len;) {
    if(buf[i] >= 'a' && buf[i] <= 'z') {
      i++;
      continue;
    }
    int j = i;
    ll amt = 0;
    int lastPeriod = -1000;
    while(j < len && (buf[j] == '.' || (buf[j] >= '0' && buf[j] <= '9'))) {
      if(buf[j] == '.') {
        lastPeriod = j;
        j++;
        continue;
      }
      amt *= 10;
      amt += buf[j] - '0';
      j++;
    }
    if(j - lastPeriod != 3) amt *= 100;
    i = j;
    numCents += amt;
  }
  string ret = "";
  if(numCents % 100) {
    stringstream s;
    s << ".";
    if(numCents % 100 < 10) {
      s << "0";
    }
    s << numCents % 100;
    string temp;
    s >> ret;
  }
  numCents /= 100;
  vector<int> v;
  while(numCents > 0) {
    v.insert(v.begin(), numCents % 1000);
    numCents /= 1000;
  }
  if(v.size() == 0) v.push_back(0);
  for(int i = 0; i < v.size(); i++) {
    if(i == 0) printf("%d", v[i]);
    else printf("%03d", v[i]);
    if(i != v.size()-1) printf(".");
  }
  printf("%s\n", ret.c_str());
}

int main() {
  solve();
  return 0;
}