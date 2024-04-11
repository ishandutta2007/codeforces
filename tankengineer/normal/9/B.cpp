//CF 9B
#include<stdio.h>
#include<math.h>

int n, ans;
long long v1, v2, x[105], tx, ty;
double dist[105];

int main() {
  scanf("%d %I64d %I64d", &n, &v1, &v2);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x[i]);
  }
  scanf("%I64d %I64d", &tx, &ty);
  for (int i = 2; i <= n; i++) {
    dist[i] = (double)x[i] / v1 + sqrt(ty * ty + (tx - x[i]) * (tx - x[i])) / v2;
  }
  ans = n; 
  for (int i = 2; i <= n; i++) {
    if (dist[ans] > dist[i] || fabs(dist[ans] - dist[i]) <= 1e-7 && (x[ans] - tx) * (x[ans] - tx) > (x[i] - tx) * (x[i] - tx)) { 
       ans = i;
    }
  } 
  
  printf("%d\n", ans);
  return 0;
}