//15A
#include<cstdio>
#include<algorithm>
using namespace std;

int n, t, ans, srt[1005], l[1005], r[1005];

bool cmp(int i, int j) {return l[i] < l[j];}

int main() {
  scanf("%d %d", &n, &t);
  ans = 2;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &l[i], &r[i]);
    srt[i] = i;
  }
  sort(srt + 1, srt + n + 1, cmp);
  for (int i = 2; i <= n; i++) {
    if (l[srt[i - 1]] * 2 + r[srt[i - 1]] + t * 2 < l[srt[i]] * 2 - r[srt[i]]) ans += 2;
    if (l[srt[i - 1]] * 2 + r[srt[i - 1]] + t * 2 == l[srt[i]] * 2 - r[srt[i]]) ans += 1;    
  }
  printf("%d\n", ans);
  return 0;
}