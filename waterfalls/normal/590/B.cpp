#include <bits/stdc++.h>
using namespace std;

double x1,y1,x2,y2,vmax,t,vx,vy,wx,wy;

bool check(double T) {
	double x = x2;
	x-=vx*min(t,T);
	if (T>=t) x-=wx*(T-t);
	double y = y2;
	y-=vy*min(t,T);
	if (T>=t) y-=wy*(T-t);
	double go = sqrt(x*x+y*y);
	return T*vmax>=go;
}

int main() {
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&vmax,&t,&vx,&vy,&wx,&wy);
	x2-=x1;
	y2-=y1;
	double low = 0;
	double high = 1;
	while (!check(high)) {
		low = high;
		high*=2;
	}
	while (high-low>1e-8) {
		if (check((low+high)/2)) high = (low+high)/2;
		else low = (low+high)/2;
	}
	printf("%1.9f\n",high);

	return 0;
}