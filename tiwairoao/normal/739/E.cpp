#include<cstdio>
const int MAXN = 2000;
double p[MAXN + 5], u[MAXN + 5];
double ans;
int n, a, b, cnt1, cnt2;
bool Check2(double x, double y) {
	cnt1 = cnt2 = ans = 0;
	for(int i=1;i<=n;i++) {
		int type = 0; double tmp = ans;
		if( ans + p[i] - x > tmp )
			tmp = ans + p[i] - x, type = 1;
		if( ans + u[i] - y > tmp )
			tmp = ans + u[i] - y, type = 2;
		if( ans + p[i] + u[i] - p[i]*u[i] - x - y > tmp )
			tmp = ans + p[i] + u[i] - p[i]*u[i] - x - y, type = 3;
		if( type & 1 ) cnt1++;
		if( type & 2 ) cnt2++;
		ans = tmp;
	}
	return cnt2 >= b;
}
bool Check1(double x) {
	double le = 0, ri = 1;
	for(int i=1;i<=50;i++) {
		double mid = (le + ri) / 2;
		if( Check2(x, mid) ) le = mid;
		else ri = mid;
	}
	Check2(x, le); ans += le*b;
	return cnt1 >= a;
}
int main() {
	scanf("%d%d%d", &n, &a, &b);
	for(int i=1;i<=n;i++)
		scanf("%lf", &p[i]);
	for(int i=1;i<=n;i++)
		scanf("%lf", &u[i]);
	double le = 0, ri = 1;
	for(int i=1;i<=50;i++) {
		double mid = (le + ri) / 2;
		if( Check1(mid) ) le = mid;
		else ri = mid;
	}
	Check1(le);
	printf("%lf\n", ans + le*a);
}