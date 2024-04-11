#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const double eps = 1e-8, Pi = acos(-1.0);
int n;
double a, x[Maxn], y[Maxn], dis[Maxn];
pair <double, double> pos[Maxn];
priority_queue <double, vector <double>, greater <double> > Pr;
bool check(double r)
{
	int m = 0;
	for (int i = 1; i <= n; i++)
	{
		double l = sqrt((x[i] - a) * (x[i] - a) + y[i] * y[i]);
		if (l > dis[i] + r || dis[i] > l + r || r > dis[i] + l) continue;
		double p = atan2(y[i], x[i] - a);
		double range = acos((l * l + r * r - dis[i] * dis[i]) / (2 * l * r));
		double L = p - range, R = p + range;
		if (L < -Pi) L += 2 * Pi;
		if (L > Pi) L -= 2 * Pi;
		if (R < -Pi) R += 2 * Pi;
		if (R > Pi) R -= 2 * Pi;
		if (L > R) swap(L, R);
		pos[++m] = make_pair(L, R);
	}
	sort(pos + 1, pos + 1 + m);
	while (!Pr.empty()) Pr.pop();
	for (int i = 1; i <= m; i++)
	{
		while (!Pr.empty() && Pr.top() < pos[i].first) Pr.pop();
		if (!Pr.empty() && Pr.top() <= pos[i].second) return true;
		Pr.push(pos[i].second);
	}
	return false;
}
int main()
{
	scanf("%d%lf", &n, &a);
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", &x[i], &y[i]), dis[i] = sqrt((x[i] + a) * (x[i] + a) + y[i] * y[i]);
	double l = 0, r = 2 * a;
	while (r - l >= eps)
	{
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	printf("%.10lf", l);
	return 0;
}