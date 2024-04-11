#include <bits/stdc++.h>
using namespace std;

int n,x0,y0;
double x[100013], y[100013];
double minr = 1e200, maxr = 0;
const double PI = 2*acos(0.0);

double sq(double x) { return x*x; }

int main() {
	scanf("%d%d%d",&n,&x0,&y0);
	for (int i=0;i<n;i++) {
		scanf("%lf%lf",&x[i],&y[i]);
		x[i]-=x0; y[i]-=y0;
		minr = min(minr,sq(x[i])+sq(y[i]));
		maxr = max(maxr,sq(x[i])+sq(y[i]));
	}
	for (int i=0;i<n;i++) {
		int j = (i+1)%n;
		double dist = sq(x[i]*y[j]-x[j]*y[i]);
		dist/=sq(x[i]-x[j])+sq(y[i]-y[j]);
		if (x[i]*(x[i]-x[j])+y[i]*(y[i]-y[j])<0) continue;
		if (x[j]*(x[j]-x[i])+y[j]*(y[j]-y[i])<0) continue;
		minr = min(minr,dist);
	}
	printf("%1.9f\n",maxr*PI-minr*PI);

	return 0;
}