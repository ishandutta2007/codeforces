#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int n;
ld a[100013], b[100013];
ld ans1[100013], ans2[100013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		double x;
		scanf("%lf",&x);
		a[i] = x;
	}
	for (int i=0;i<n;i++) {
		double x;
		scanf("%lf",&x);
		b[i] = x;
	}
	ld has1 = 0, has2 = 0;
	for (int i=0;i<n;i++) {
		ld sum = a[i]+b[i]+has1+has2;
		ld prod = a[i]+has1*has2;
		ld disc = sqrt(max((ld) 0,sum*sum-4*prod));
		ans1[i] = (sum-disc)/2-has1;
		ans2[i] = (sum+disc)/2-has2;
		has1+=ans1[i];
		has2+=ans2[i];
	}
	for (int i=0;i<n;i++) printf("%1.9f ",(double) ans1[i]);
	printf("\n");
	for (int i=0;i<n;i++) printf("%1.9f ",(double) ans2[i]);
	printf("\n");

	return 0;
}