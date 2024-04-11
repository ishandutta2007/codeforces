//19D
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int tree_bottom = 1 << 18;

int n, x[200005], y[200005], cx[tree_bottom * 2 + 5], cy[tree_bottom * 2 + 5], t[200005], srt[200005], pos[200005], cnt, t1;
char s[10];

bool cmp(int i, int j) {return x[i] < x[j] || x[i] == x[j] && y[i] < y[j];}

void update(int i, int x, int y) {
  i += tree_bottom;
  cx[i] = x;
  cy[i] = y;
  for (i >>= 1; i; i >>= 1) {
    cx[i] = max(cx[i * 2], cx[i * 2 + 1]);
    cy[i] = max(cy[i * 2], cy[i * 2 + 1]);
  }
}

int getans(int v, int x, int y) {
  int t1;
  if (cx[v] < x || cy[v] < y) return -1;
  if (v > tree_bottom) return v;
  t1 = getans(v * 2, x, y);
  if (t1 != -1) return t1;
  return getans(v * 2 + 1, x, y);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s %d %d", &s, &x[i], &y[i]);
    t[i] = (s[0] == 'a') ? 0 : (s[0] == 'r') ? 1 : 2;
    srt[i] = i;
  }
  sort(srt + 1, srt + n + 1, cmp);
  
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (x[srt[i]] != x[srt[i - 1]] || y[srt[i]] != y[srt[i - 1]]) cnt++;
    pos[srt[i]] = cnt;
  }
  
  for (int i = 1; i <= n; i++) {
    if (t[i] == 2) {
      t1 = getans(1, x[i] + 1, y[i] + 1);
      if (t1 == -1) {
        puts("-1");
      } else {
        printf("%d %d\n", cx[t1], cy[t1]);
      }
    } else {
      if (t[i] == 0) {
        update(pos[i], x[i], y[i]);
      } else {
        update(pos[i], 0, 0);
      } 
    }
  }
  
  return 0;
}