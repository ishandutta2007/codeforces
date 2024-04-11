//12D
//
#include<cstdio>
#include<memory.h>
#include<algorithm>

using namespace std;

int n, x[500005], y[500005], z[500005], ord[500005], srt[500005], ans, t1, ta[500005];

bool cmpy(int i, int j) {return y[i] > y[j];}
bool cmp(int i, int j) {return x[i] > x[j] || x[i] == x[j] && (y[i] < y[j] || y[i] == y[j] && z[i] < z[j]);}

inline int lowbit(const int &i) {return i & -i;}

void insert(const int &i, const int &val) {
  int s = i;
  while (s <= n) {
    ta[s] = max(ta[s], val);
    s += lowbit(s);
  }
}

int getmax(const int &i) {
  int s = i, t = -1;
  while (s) {
    t = max(t, ta[s]);
    s -= lowbit(s);
  }
  return t;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &y[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &z[i]);
  for (int i = 1; i <= n; i++) srt[i] = i;
  sort(srt + 1, srt + n + 1, cmpy);
  ord[srt[1]] = 1;
  for (int i = 2; i <= n; i++) ord[srt[i]] = ord[srt[i - 1]] + (y[srt[i]] < y[srt[i - 1]]);
  sort(srt + 1, srt + n + 1, cmp);
  memset(ta, 128, sizeof(ta));
  ans = 0;
  for (int i = 1; i <= n; i++) {
    t1 = getmax(ord[srt[i]] - 1);
    ans += t1 > z[srt[i]];
    insert(ord[srt[i]], z[srt[i]]);
  }
  printf("%d\n", ans);
  
  return 0;
}