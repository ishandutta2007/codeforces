//23C
#include<cstdio>
#include<algorithm>

using namespace std;

int t, n, a[200005], b[200005], srt[200005];

bool cmp(int i, int j) {return a[i] < a[j];}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i < n * 2; i++) {
      scanf("%d %d", &a[i], &b[i]);
      srt[i] = i;
    }
    sort(srt + 1, srt + n + n, cmp);
    puts("YES");
    for (int i = 2; i < n * 2 - 1; i += 2) {
      printf("%d ", srt[b[srt[i]] > b[srt[i - 1]] ? i : i - 1]);
    }
    printf("%d\n", srt[n * 2 - 1]);
  }
  return 0;
}