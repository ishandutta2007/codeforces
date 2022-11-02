#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 3005;

int n, h[N], r[N], r2[N];
double ans, hs[N];

double high(const int h1, const int r1, const int R1, const int h2, const int r2, const int R2) {
  if (R1 <= r2) return h1;
  if (R2 <= r1) return 0;
  
  double x1 = 0, x2 = 0;
  if (r2 >= r1) {
    x1 = 1.0 * (r2 - r1) * h1 / (R1 - r1); 
  }
  if (R2 >= R1) {
    x2 = h1 - 1.0 * (R1 - r2) * h2 / (R2 - r2);
  } else {
    x2 = 1.0 * (R2 - r1) * h1 / (R1 - r1) - h2;
  }
  return max(0.0, max(x1, x2));
}

int main() {  
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
	  scanf("%d %d %d", &h[i], &r[i], &r2[i]);
	  for (int j = 0; j < i; ++j) hs[i] = max(hs[i], hs[j] + high(h[j], r[j], r2[j], h[i], r[i], r2[i]));
	  ans = max(ans, hs[i] + h[i]);
	}
	printf("%.12lf\n", ans);
	return 0;
}