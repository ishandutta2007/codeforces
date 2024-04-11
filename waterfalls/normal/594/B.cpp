#include <bits/stdc++.h>
using namespace std;

const double PI = 2*acos(0.0);

int n,r,v,s,f;

int main() {
	scanf("%d%d%d",&n,&r,&v);
	for (int i=0;i<n;i++) {
		scanf("%d%d",&s,&f);
		double x = f-s;
		double low1 = 0, low2 = 0;
		double high1 = 2e9, high2 = 2e9;
		for (int rep=0;rep<60;rep++) {
			double mid = (low1+high1)/2;
			double ang = v*mid/r;
			if (r*(ang-sin(ang))>x/2) high1 = mid;
			else low1 = mid;
			mid = (low2+high2)/2;
			ang = v*mid/r+PI;
			if (r*(ang-sin(ang)-PI)>x/2) high2 = mid;
			else low2 = mid;
		}
		printf("%1.9f\n",min(high1,high2)*2);
	}

	return 0;
}