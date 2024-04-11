#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int a[200013];

double res[200013];
double maxsum() {
	double ans = 0;
	double cur = 0;
	for (int i=1;i<=n;i++) {
		cur+=res[i];
		if (cur<0) cur = 0;
		ans = max(ans,cur);
	}
	return ans;
}
double check(double K) {
	for (int i=1;i<=n;i++) res[i] = a[i]-K;
	double ans = 0;
	ans = max(ans,maxsum());
	for (int i=1;i<=n;i++) res[i] = -res[i];
	ans = max(ans,maxsum());
	return ans;
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	double low = -10000;
	double high = 10000;
	for (int i=0;i<200;i++) {
		double one = check((2*low+high)/3);
		double two = check((low+2*high)/3);
		if (one>two) low = (2*low+high)/3;
		else high = (low+2*high)/3;
	}
	printf("%1.9f\n",check(low));

	return 0;
}