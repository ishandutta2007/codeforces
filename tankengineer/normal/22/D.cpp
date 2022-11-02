//22D
#include<cstdio>
#include<algorithm>

using namespace std;

int n, st[1005], ed[1005], srt[1005], ans, last, t[1005];

bool cmp(int i, int j) {return ed[i] < ed[j];}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &st[i], &ed[i]);
    if (st[i] > ed[i]) {
      st[i] ^= ed[i]; ed[i] ^= st[i]; st[i] ^= ed[i];
    }
    srt[i] = i;
  }
  sort(srt, srt + n, cmp);
  last = -100000; ans = 0;
  for (int i = 0; i < n; i++) {
    if (st[srt[i]] > last) {
      t[ans++] = last;
      last = ed[srt[i]];
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i < ans; i++) {
    printf("%d ", t[i]);
  }
  printf("%d\n", last);
  return 0;
}