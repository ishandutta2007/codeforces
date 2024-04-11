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

int p[1000005];
int find(int x) {
  return p[x] == x ? x : (p[x] = find(p[x]));
}

void merge(int x, int y) {
  p[find(x)] = find(y);
}

int l[1000005];
vector<int> amts[1000005];

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
    p[i] = i;
  }
  for(int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    merge(a, b);
  }
  for(int i = 0; i < n; i++) {
    amts[find(i)].push_back(l[i]);
  }
  for(int i = 0; i < n; i++) {
    sort(amts[i].begin(), amts[i].end());
  }
  for(int i = 0; i < n; i++) {
    int index = find(i);
    printf("%d", amts[index][amts[index].size()-1]);
    amts[index].pop_back();
    if(i == n-1) printf("\n");
    else printf(" ");
  }
}

int main() {
  solve();
  return 0;
}