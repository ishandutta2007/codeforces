#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>

using namespace std;

const int N = 444444;

int a[N], b[N], s[N], inter[N], inside[N], p[N], id[N];
int t;

void modify(int x, int v) {
  while (x <= t) {
    s[x] += v;
    x = (x | (x-1)) + 1;
  }
}

int find(int x) {
  int v = 0;
  while (x > 0) {
    v += s[x];
    x &= x-1;
  }
  return v;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i=1;i<=n;i++) {
    scanf("%d %d", a+i, b+i);
    if (a[i] > b[i]) { int tmp = a[i]; a[i] = b[i]; b[i] = tmp; }
  }
  for (int i=1;i<=n;i++) {
    p[a[i]] = b[i];
    p[b[i]] = a[i];
    id[a[i]] = i;
    id[b[i]] = i;
  }
  t = 2*n;
  for (int i=1;i<=t;i++) s[i] = 0;
  for (int i=1;i<=t;i++) {
    if (p[i] < i) {
      inside[id[i]] = find(i) - find(p[i]-1);
      modify(p[i], 1);
    }
  }
  for (int i=1;i<=n;i++) inter[i] = (b[i]-a[i]-1) - 2*inside[i];
  long long ans = (long long)n*(n-1)*(n-2)/6;
  long long cnt1 = 0, cnt2 = 0;
  for (int i=1;i<=n;i++) {
    cnt1 += (long long)inter[i] * (n-inter[i]-1);
    cnt2 += (long long)inside[i] * (n-inter[i]-inside[i]-1);
  }
  ans -= (cnt1/2 + cnt2);
  cout << ans << endl;
  return 0;
}