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
const double PI = 2 * acos(0);
const int MOD = 1000000007;

int goal[505];

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> orig;
  for(int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    orig.push_back(t);
  }
  int k;
  scanf("%d", &k);
  for(int i = 0; i < k; i++) {
    scanf("%d", &goal[i]);
  }
  vector<char> retC;
  vector<int> retI;
  int offset = 0;
  for(int goalIndex = 0; goalIndex < k; goalIndex++) {
    int amtNeed = 0;
    int accu = 0;
    while(amtNeed < orig.size() && accu < goal[goalIndex]) {
      accu += orig[amtNeed++];
    }
    if(goal[goalIndex] != accu) {
      printf("NO\n");
      return;
    }
    int maxSeen = 0;
    for(int i = 0; i < amtNeed; i++) {
      maxSeen = max(maxSeen, orig[i]);
    }
    int goodIndex = -1;
    if(amtNeed == 1) goodIndex = 0;
    for(int i = 0; i < amtNeed; i++) {
      if(orig[i] != maxSeen) continue;
      if(i > 0 && orig[i] > orig[i-1]) {
        goodIndex = i;
      }
      if(i + 1 < amtNeed && orig[i] > orig[i+1]) {
        goodIndex = i;
      }
    }
    if(goodIndex == -1) {
      printf("NO\n");
      return;
    }
    while(amtNeed > 1) {
      amtNeed--;
      if(goodIndex > 0 && orig[goodIndex] > orig[goodIndex-1]) {
        stringstream ss;
        retC.push_back('L');
        retI.push_back(goodIndex+1+offset);
        orig[goodIndex] += orig[goodIndex-1];
        orig.erase(orig.begin() + goodIndex - 1);
        goodIndex--;
      }
      else {
        stringstream ss;
        retC.push_back('R');
        retI.push_back(goodIndex+1+offset);
        orig[goodIndex] += orig[goodIndex+1];
        orig.erase(orig.begin() + goodIndex + 1);
      }
    }
    orig.erase(orig.begin());
    offset++;
  }
  if(!orig.empty()) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  for(int i = 0; i < retC.size(); i++) {
    printf("%d %c\n", retI[i], retC[i]);
  }
}

int main() {
  solve();
  return 0;
}