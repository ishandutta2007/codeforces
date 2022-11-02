//139E
#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;

const int ma = 100005, mb = 10005, me = 500005;

int a[ma], h[ma], l[ma], r[ma], b[mb], p[mb], times[me], event[me], st[me], srt[me], top, n, m, cnt[105];
double ans, po, ta[105];

bool cmp(int x, int y) {if (times[x] != times[y]) return times[x] < times[y]; return st[x] > st[y];}

inline int lowbit(const int &i) {return i & (-i);}

void change(const int &pos, const int &val) {
  cnt[pos] += val;
}

double getmuti() {
  double po = 1;
  for (int i = 1; i <= 99; i++) {
    po = po * pow((double)i / 100, cnt[i]);
  }
  return po;
}

int main() {
  scanf("%d %d", &n, &m);
  top = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d %d", &a[i], &h[i], &l[i], &r[i]);
    top++; times[top] = a[i] - h[i]; event[top] = l[i]; st[top] = 1; srt[top] = top;
    top++; times[top] = a[i] - 1; event[top] = l[i]; st[top] = -1; srt[top] = top;
    top++; times[top] = a[i] + 1; event[top] = r[i]; st[top] = 1; srt[top] = top;
    top++; times[top] = a[i] + h[i]; event[top] = r[i]; st[top] = -1; srt[top] = top;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &b[i], &p[i]);
    top++; times[top] = b[i]; event[top] = p[i]; st[top] = 0; srt[top] = top;
  }
  
  sort(srt + 1, srt + 1 + top, cmp);
  
  ans = 0; po = 0;
  
  for (int i = 1; i <= top; i++) {
    if (st[srt[i]] == 1) {
      change(100 - event[srt[i]], 1);
    } else if (st[srt[i]] == -1) {
      change(100 - event[srt[i]], -1);
    } else {
      if (cnt[0] == 0) {
        ans += event[srt[i]] * getmuti();
      }
    }
  }
  
  printf("%lf\n", ans);

  return 0;
}