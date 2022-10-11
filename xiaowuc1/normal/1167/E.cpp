#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

int l[1000005];
bool prefSorted[1000005];
bool suffSorted[1000005];

int lastAppear[1000005];
int firstAppear[1000005];

int firstAppearMin[1000005];
int lastAppearMax[1000005];

void solve() {
  int n, maxV;
  cin >> n >> maxV;
  for(int i = 1; i <= maxV; i++) firstAppear[i] = 1e9;
  for(int i = 1; i <= maxV; i++) lastAppear[i] = -1;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    lastAppear[l[i]] = i;
    if(firstAppear[l[i]] == 1e9) firstAppear[l[i]] = i;
  }
  lastAppearMax[0] = -1;
  for(int i = 1; i <= maxV; i++) {
    lastAppearMax[i] = max(lastAppearMax[i-1], lastAppear[i]);
  }
  firstAppearMin[maxV+1] = 1e9;
  for(int i = maxV; i >= 1; i--) {
    firstAppearMin[i] = min(firstAppearMin[i+1], firstAppear[i]);
  }

  prefSorted[0] = true;
  prefSorted[1] = true;
  for(int i = 2; i <= maxV; i++) {
    if(!prefSorted[i-1]) break;
    if(firstAppear[i] >= lastAppearMax[i-1]) prefSorted[i] = true;
  }
  suffSorted[maxV+1] = true;
  suffSorted[maxV] = true;
  for(int i = maxV-1; i >= 1; i--) {
    if(!suffSorted[i+1]) break;
    if(lastAppear[i] < firstAppearMin[i+1]) suffSorted[i] = true;
  }
  ll ret = 0;
  for(int i = 1; i <= maxV; i++) {
    if(!prefSorted[i-1]) break;
    int lhs = i;
    int rhs = maxV+1;
    while(lhs != rhs) {
      int mid = (lhs+rhs)/2;
      // (can you delete [i, mid])
      if(!suffSorted[mid+1]) {
        lhs = mid+1;
        continue;
      }
      if(lastAppearMax[i-1] < firstAppearMin[mid+1]) {
        rhs = mid;
      }
      else {
        lhs = mid+1;
      }
    }
    ret += (maxV+1-lhs);
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}