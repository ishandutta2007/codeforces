#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500005;
const int MAXX = 1000005;

int n, k, a[MAXN], cnt[MAXX], cntDiff;

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  int l = 0;
  int bestL = -1, bestR = -1;
  for(int r = 0; r < n; ++r) {
    if (cnt[a[r]] == 0)
      ++cntDiff;
    ++cnt[a[r]];
    while (cntDiff > k) {
      --cnt[a[l]];
      if (cnt[a[l]] == 0)
        --cntDiff;
      ++l;
    }

    if (r - l >= bestR - bestL) {
      bestL = l;
      bestR = r;
    }
  }

  printf("%d %d\n", bestL + 1, bestR + 1);

  return 0;
}