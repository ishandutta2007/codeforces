#include<cstdio>
#include<algorithm>

using namespace std;

struct pt {
  int i;
  double x, v;
} P[500000], Q[500000];

int main()
{
  int n;
  scanf("%d", &n);
  int ng = 0, ps = 0;
  double maxv = 0.0;
  bool ex = false;
  for(int i=0; i<n; ++i) {
    scanf("%lf%lf", &P[i].x, &P[i].v);
    if(P[i].v > 0) ps++;
    else if(P[i].v < 0) ng++;
    if(P[i].v < 0 && ps > 0) ex = true;
    Q[i].i = i;
    if(maxv < P[i].v) maxv = P[i].v;
    if(maxv < -P[i].v) maxv = -P[i].v;
  }
  if(!ex) { printf("-1\n"); return 0; }
  double lo = 0.0, hi = 2e9;
  for(int loop=0; loop<300; ++loop) {
    double mid = (hi+lo)/2;
    double mxx = -1e20;
    bool ok = false;
    for(int i=0; i<n && !ok; ++i) {
      if(P[i].v > 0) {
	if(P[i].x+mid*P[i].v>mxx) mxx=P[i].x+mid*P[i].v;
      } else {
	if(P[i].x+mid*P[i].v<=mxx) ok = true;
      }
    }
    if(ok) hi = mid; else lo = mid;
  }
  printf("%.15f\n", lo);
  return 0;
}