#include <bits/stdc++.h>
using namespace std;

int n,r;

const double PI = 2*acos(0.0);

int main() {
	scanf("%d%d",&n,&r);
	double x = cos(PI/n);
	double y = sin(PI/n);
	double x2 = cos(PI+2*PI/n);
	double y2 = sin(PI+2*PI/n);
	double m = (y-y2)/(x-x2);
	double b = y2-m*x2;
	printf("%1.9f\n",y*(-b/m)*n*r*r);

	return 0;
}