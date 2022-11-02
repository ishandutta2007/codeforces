#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int m, n, k, t1, t2, t[105], days[105], cost[105], loc[105], times[105], end, cnt[47205], f[47205], pre[105][47205], w[105][47205], stack[105], ans, sat[105], 
    ent[105], ord[105];
char s[105][35], tk[20], name[105][35], tims[105][20];
bool useable[24 * 60 + 5];

bool cmp(const int i, const int j) {return cnt[times[i]] < cnt[times[j]] ;}

int main() {
  scanf("%d %d %d", &m, &n, &k);
  gets(s[0]);
  for (int i = 1; i <= m; ++i) gets(s[i]);
  for (int i = 1; i <= m; ++i) scanf("%d", &t[i]);
  gets(tk);
  for (int i = 1; i <= 4; ++i) {
    gets(tk);
    t1 = ((tk[0] - '0') * 10 + (tk[1] - '0')) * 60 + (tk[3] - '0') * 10 + (tk[4] - '0');
    t2 = ((tk[6] - '0') * 10 + (tk[7] - '0')) * 60 + (tk[9] - '0') * 10 + (tk[10] - '0');
    for (int j = t1; j <= t2; ++j) useable[j] = true;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%s %d %s %d", &name[i], &days[i], &tims[i], &cost[i]);
    ord[i] = i;
    times[i] = (days[i] - 1) * 24 * 60 + ((tims[i][0] - '0') * 10 + (tims[i][1] - '0')) * 60 + (tims[i][3] - '0') * 10 + (tims[i][4] - '0');
    for (int j = 1; j <= m; ++j) {
      if (strcmp(name[i], s[j]) == 0) {
        loc[i] = j;
      }
    }
  }
  end = 31 * 24 * 60;
  for (int i = 0; i <= end; ++i) {
    cnt[i] = useable[i % (24 * 60)] ? 0 : 1;
    if (i > 0) cnt[i] += cnt[i - 1];
    if (!useable[i % (24 * 60)]) f[cnt[i]] = i;
  }
  sort(ord + 1, ord + 1 + n, cmp);
  for (int i = 1; i <= n; ++i) {
    for (int j = cnt[end]; j >= 1; --j) {
      w[i][j] = w[i - 1][j];
      pre[i][j] = -1;
    }
    if (loc[ord[i]] == 0) continue;
    for (int j = cnt[end]; j >= 1; --j) {
      int time_end = j + t[loc[ord[i]]] - 1;
      if (time_end > cnt[end]) continue;
      //questions!!!!!
      if (f[time_end] + 1 <= times[ord[i]]) {
        if (w[i][time_end + 1] < w[i - 1][j] + cost[ord[i]]) {
          w[i][time_end + 1] = w[i - 1][j] + cost[ord[i]];
          pre[i][time_end + 1] = ord[i];
        }
      }
    }
  }
  ans = 1;
  for (int j = 1; j <= cnt[end]; ++j) {
    if (w[n][j] > w[n][ans]) ans = j;
  }
  t1 = 0;
  printf("%d\n", w[n][ans]);
  t2 = n;
  while (pre[t2][ans] == -1) --t2;
  while (pre[t2][ans]) {
    stack[++t1] = pre[t2][ans];
    ent[t1] = f[ans - 1];
    ans = ans - t[loc[pre[t2][ans]]];
    --t2;
    while (pre[t2][ans] == -1) --t2;
    sat[t1] = f[ans];
  }
  printf("%d\n", t1);
  int t3 = t1;
  for (int i = t3; i >= 1; --i) {
    t1 = sat[i] / (24 * 60) + 1;
    t2 = sat[i] % (24 * 60);
    printf("%d %d ", stack[i], t1);
    printf("%d%d:%d%d ", t2 / 60 / 10, t2 / 60 % 10, t2 % 60 / 10, t2 % 60 % 10);
    t1 = ent[i] / (24 * 60) + 1;
    t2 = ent[i] % (24 * 60);    
    printf("%d ", t1);
    printf("%d%d:%d%d\n", t2 / 60 / 10, t2 / 60 % 10, t2 % 60 / 10, t2 % 60 % 10);     
  }
  return 0;
}