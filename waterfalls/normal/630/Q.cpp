#include <bits/stdc++.h>
using namespace std;

int l[10];

const double PI = 2*acos(0.0);

int main() {
	for (int i=3;i<=5;i++) scanf("%d",&l[i]);
	double ans = 0;
	for (int i=3;i<=5;i++) {
		double area = (l[i]/tan(PI/i)/2)*l[i]*i/2;
		double height = sqrt(l[i]*l[i]-(l[i]/sin(PI/i)/2)*(l[i]/sin(PI/i)/2));
		ans+=area*height/3;
	}
	printf("%1.12f\n",ans);

	return 0;
}