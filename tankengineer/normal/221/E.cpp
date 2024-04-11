#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, a[N], b[N], posa[N], posb[N], dif[N], ans, ord[N], t1;

multiset<int> rig, lef;

int abss(const int i) {return i < 0 ? -i : i;}

bool cmp(int i, int j) {return dif[i] < dif[j];}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    posa[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    posb[b[i]] = i;
  }
  ans = n;
  for (int i = 1; i <= n; ++i) {
    ans = min(ans, abss(posa[i] - posb[i]));
    dif[i] = posb[i] - posa[i];
    if (dif[i] > 0) {
      rig.insert(dif[i]);
    } else {
      lef.insert(-dif[i]);
    }
    ord[i] = i;
  }
  sort(ord + 1, ord + 1 + n, cmp);
  t1 = 1;
  printf("%d\n", ans);
  for (int i = 2; i <= n; ++i) {
    lef.erase(lef.find(posa[b[i - 1]] - i + 1));
    rig.insert(n - posa[b[i - 1]] + i - 1);
    while (rig.size() > 0 && *rig.begin() - i + 1 == 0) {
      rig.erase(rig.find(*rig.begin()));
      lef.insert((int)(-i + 1));
    }
    ans = min(*lef.begin() + i - 1, rig.size() > 0 ? *rig.begin() - i + 1 : n + 1);
    printf("%d\n", ans);
  }
  return 0;
}