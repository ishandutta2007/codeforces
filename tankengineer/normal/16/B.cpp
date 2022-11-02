//16B
#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, srt[22], a[22], b[22], ans, t1;

bool cmp(int i, int j) {return b[i] > b[j];}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &a[i], &b[i]);
    srt[i] = i;
  }
  sort(srt + 1, srt + m + 1, cmp);
  
  for (int i = 1; i <= m; i++) {
    t1 = min(n, a[srt[i]]);
    n -= t1;
    ans += t1 * b[srt[i]];
  }
  
  printf("%d\n", ans);
  
  return 0;
}