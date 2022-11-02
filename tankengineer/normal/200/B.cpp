#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	double ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		double t1;
		scanf("%lf", &t1);
		ans += t1;
	}
	ans /= n;
	printf("%.6f\n", ans);
	return 0;
}