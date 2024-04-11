#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, k, x[N], ord[N], y;
double hls, k1s, kns, mds, dist[N], ans;

bool cmp(int i, int j) {return x[i] < x[j];}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n + 1; ++i) {
    scanf("%d", &x[i]);
    ord[i] = i;
  }
  scanf("%d", &y);
  sort(ord + 1, ord + n + 1, cmp);
  for (int i = 1; i <= n; ++i) {
    dist[i] = sqrt((x[ord[i]] - x[n + 1]) * 1.0 * (x[ord[i]] - x[n + 1]) + y * 1.0 * y);
    //printf("%d ", x[ord[i]]);
  }
  //printf("\n");
  for (int i = 1; i <= n; ++i) {
    if (ord[i] == k) {
      k = i;
      break;
    }
  }
  if (n == 1) {
    printf("%.12lf\n", dist[1]);
    return 0;
  }
  hls = x[ord[n]] - x[ord[1]];
  k1s = x[ord[k]] - x[ord[1]];
  kns = x[ord[n]] - x[ord[k]];
  if (k == n + 1) {
    ans = hls + min(dist[1], dist[n]);
  } else {
    ans = min(hls + k1s + dist[n], hls + kns + dist[1]);
    for (int i = 1; i < n; ++i) {
      //printf("%d %.12lf\n", i, ans);      
      if (i < k) {
        mds = min(hls + dist[1], hls + dist[i]);
        ans = min(ans, mds + dist[n] + x[ord[i]] - x[ord[i + 1]] + x[ord[k]] - x[ord[i + 1]]);
        ans = min(ans, mds + dist[i + 1] + x[ord[i]] - x[ord[i + 1]] + x[ord[n]] - x[ord[k]]);
      } else {
        mds = min(hls + dist[n], hls + dist[i + 1]);
        ans = min(ans, mds + dist[1] + x[ord[i]] - x[ord[i + 1]] - x[ord[k]] + x[ord[i]]);
        ans = min(ans, mds + dist[i] + x[ord[i]] - x[ord[i + 1]] + x[ord[k]] - x[ord[1]]);
      }
      //printf("%d %.12lf\n", i, ans);
    }
  }
  printf("%.12lf\n", ans);
  //scanf("%d", &n);
  return 0;
}