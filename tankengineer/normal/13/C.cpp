//13C
#include<cstdio>
#include<algorithm>
using namespace std;

int n, srt[5005], v[5005], ord[5005], q[5005];
long long f[5005], mins[5005], ans;

inline long long abs(long long a) {return a < -a ? -a : a;}
bool cmp(int i, int j) {return v[i] < v[j];}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    srt[i] = i;
  }
  sort(srt + 1, srt + n + 1, cmp);
  ord[srt[1]] = 1; q[1] = v[srt[1]];
  for (int i = 2; i <= n; i++) {
    ord[srt[i]] = ord[srt[i - 1]] + (v[srt[i]] > v[srt[i - 1]]);
    q[ord[srt[i]]] = v[srt[i]];
  }
  for (int i = 1; i <= ord[srt[n]]; i++) {
    f[i] = abs(v[1] - q[i]);
    mins[i] = f[i];
    if (i > 1) mins[i] = min(mins[i], mins[i - 1]);
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= ord[srt[n]]; j++) {
      f[j] = mins[j] + abs(v[i] - q[j]);
      mins[j] = f[j];
      if (j > 1) mins[j] = min(mins[j], mins[j - 1]);
    }
  }
  ans = f[1];
  for (int i = 1; i <= ord[srt[n]]; i++) {
    if (f[i] < ans) ans = f[i];
  }
  printf("%I64d\n", ans);
  return 0;
}