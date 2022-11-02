#include<cstdio>
#include<cmath>

using namespace std;

double dist(double dx, double dy, double dz)
{
  return sqrt(dx*dx +dy*dy + dz*dz);
}

int main()
{
  double x[100], y[100], z[100];
  int n;

  double X=0, Y=0, Z=0;

  scanf("%d", &n);
  for(int i=0; i<n; ++i) {
    scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
    X += x[i];
    Y += y[i];
    Z += z[i];
  }
  X /= n;
  Y /= n;
  Z /= n;

  double P = 0.1;
  for(int i=0; i<50000; ++i) {
    int f = 0;
    double d = dist(X-x[0], Y-y[0], Z-z[0]);

    for(int j=1; j<n; ++j) {
      double e = dist(X-x[j], Y-y[j], Z-z[j]);
      if(d < e) {
	d = e;
	f = j;
      }
    }

    X += (x[f]-X)*P;
    Y += (y[f]-Y)*P;
    Z += (z[f]-Z)*P;
    P *= 0.9993;
  }

  printf("%.9f %.9f %.9f\n", X, Y, Z);
  return 0;
}