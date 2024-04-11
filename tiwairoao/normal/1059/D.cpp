#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
double x[MAXN + 5], y[MAXN + 5];
int n, cnt1 = 0, cnt2 = 0;
bool Check(double m) {
	if( fabs(y[1]-m) > m ) return false;
	double del = sqrt(2*m*y[1]-y[1]*y[1]);
	double le = x[1] - del, ri = x[1] + del;
	for(int i=2;i<=n;i++) {
		if( fabs(y[i]-m) > m ) return false;
		del = sqrt(2*m*y[i]-y[i]*y[i]);
		le = max(le, x[i] - del), ri = min(ri, x[i] + del);
	}
	return le <= ri;
}
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		scanf("%lf%lf", &x[i], &y[i]);
		if( y[i] > 0 ) cnt1++;
		if( y[i] < 0 ) cnt2++;
	}
	if( cnt1 && cnt2 ) {
		printf("-1\n");
		return 0;
	}
	if( cnt2 ) {
		for(int i=1;i<=n;i++)
			y[i] = -y[i];
	}
	double le = 0, ri = 1E18;
	for(int i=1;i<=128;i++) {
		double mid = (le + ri) / 2;
		if( Check(mid) ) ri = mid;
		else le = mid;
	}
	printf("%.7lf\n", le);
}