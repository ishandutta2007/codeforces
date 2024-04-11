#include<cstdio>

int a[10000];
int main()
{
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i=0; i<n; ++i)
    scanf("%d", &a[i]);
  double lo=0, hi=1001;
  for(int i=0; i<500; ++i) {
    double mid = (hi+lo)/2;
    double x = 0;
    for(int j=0; j<n; ++j) {
      if(a[j] < mid)
	x += mid - a[j];
      else
	x -= (a[j] - mid) * (100 - k) / 100;
    }
    if(x <= 0) lo = mid; else hi = mid;
  }
  printf("%.9f\n", lo);
  return 0;
}