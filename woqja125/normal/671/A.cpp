#include <stdio.h>
#include <math.h>
#include <algorithm>
int x[100001], y[100001];
struct D
{
	int n;
	double d;
	bool operator<(const D &A) const{ return d<A.d; }
} da[100001], db[100001];
double min(double a, double b){ return a>b?b:a; }
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int n, ax, ay, bx, by, cx, cy;
	int i;
	scanf("%d%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy, &n);
	double ans = 0;
	for(i=1; i<=n; i++)
	{
		scanf("%d%d", x+i, y+i);
		ans += 2*sqrt(1ll*(x[i]-cx)*(x[i]-cx) + 1ll*(y[i]-cy)*(y[i]-cy));
		da[i].n = db[i].n = i;
		da[i].d = -sqrt(1ll*(x[i]-cx)*(x[i]-cx) + 1ll*(y[i]-cy)*(y[i]-cy)) + sqrt(1ll*(x[i]-ax)*(x[i]-ax) + 1ll*(y[i]-ay)*(y[i]-ay));
		db[i].d = -sqrt(1ll*(x[i]-cx)*(x[i]-cx) + 1ll*(y[i]-cy)*(y[i]-cy)) + sqrt(1ll*(x[i]-bx)*(x[i]-bx) + 1ll*(y[i]-by)*(y[i]-by));
	}
	std::sort(da+1, da+1+n);
	std::sort(db+1, db+1+n);
	if(da[1].n == db[1].n)
	{
		double a = da[1].d + db[2].d;
		double t = da[2].d + db[1].d; a = min(t, a);
		a = min(da[1].d, a);a = min(db[1].d, a);
		printf("%.10f", ans+a);
	}
	else
	{
		if(da[1].d <= 0 && db[1].d <= 0) printf("%.10f", ans+da[1].d+db[1].d);
		else printf("%.10f", ans + min(da[1].d, db[1].d));
	}
	return 0;
}