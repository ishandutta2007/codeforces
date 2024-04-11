#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 1111111;

int a[N], b[N], pa[N], pb[N], len[N], v[N];
bool push[N];

void modify(int x, int l, int r, int ll, int rr, int p) {
  if (l >= ll && r <= rr) {
    v[x] = p;
    push[x] = true;
    return;
  }
  if (push[x]) {
    v[x+x] = v[x+x+1] = v[x];
    push[x+x] = push[x+x+1] = true;
    push[x] = false;
  }
  int y = (l+r) >> 1;
  if (ll <= y) modify(x+x, l, y, ll, rr, p);
  if (rr > y) modify(x+x+1, y+1, r, ll, rr, p);
}

int get(int x, int l, int r, int p) {
  if (l == r) return v[x];
  if (push[x]) {
    v[x+x] = v[x+x+1] = v[x];
    push[x+x] = push[x+x+1] = true;
    push[x] = false;
  }
  int y = (l+r) >> 1;
  if (p <= y) return get(x+x, l, y, p);
  return get(x+x+1, y+1, r, p);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i=1;i<=n;i++) scanf("%d", a+i);
  for (int i=1;i<=n;i++) scanf("%d", b+i);
  push[1] = true;
  v[1] = 0;
  for (int i=1;i<=m;i++) {
    int com;
    scanf("%d", &com);
    if (com == 1) {
      scanf("%d %d %d", pa+i, pb+i, len+i);
      modify(1, 1, n, pb[i], pb[i]+len[i]-1, i);
    } else {
      int pz;
      scanf("%d", &pz);
      int op = get(1, 1, n, pz);
      if (op == 0) printf("%d\n", b[pz]);
      else printf("%d\n", a[pz-pb[op]+pa[op]]);
    }
  }
  return 0;
}