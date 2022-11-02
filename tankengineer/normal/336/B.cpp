#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	int im;
	double r;
	scanf("%d%lf", &im, &r);
	double m = im;
	double sum = 0;
	for (int i = 0; i < im; ++i) {
		sum += 2 * r;
		if (i > 0) {
			sum += (2 + sqrt(2.0)) * r;
		}
		if (i + 1 < im) {
			sum += (2 + sqrt(2.0)) * r;
		}
		if (i - 1 > 0) {
			int t = i - 1;
			sum += 2 * sqrt(2.0) * r * t + r * (1 + t) * t;
		}
		if (i + 2 < im) {
			int t = im - i - 2;
			sum += 2 * sqrt(2.0) * r * t + r * (1 + t) * t;
		}
	}
	printf("%.12f\n", sum / m / m);
	return 0;
}