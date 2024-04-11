#define y1 yy1
#include <bits/stdc++.h>
#undef y1
using namespace std;
 
const int Maxn = 200005;
int n, m, ct, line_ct, ord[Maxn];
vector <int> Start[Maxn], End[Maxn];
double ans, x[Maxn], y[Maxn];
vector <pair <double, double > > tmp_Ve;
pair <double, double> P;
struct line
{
	double x1, y1, x2, y2;
} L[Maxn];
double get_dis(int a, int b)
{
	return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}
double get_dis(pair <double, double> p1, pair <double, double> p2 = make_pair(0, 0))
{
	return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}
double S(pair <pair <double, double>, pair <double, double> > l)
{
	return fabs(l.first.first * l.second.second - l.first.second * l.second.first) / 2;
}
pair <double, double> cross(int a, pair <double, double> point = P)
{
	if (L[a].x1 == L[a].x2) return make_pair(L[a].x1, point.second / (double) point.first * L[a].x1);
	pair <double, double> l1, l2, result;
	l1.first = (L[a].y2 - L[a].y1) / (double) (L[a].x2 - L[a].x1);
	l1.second = L[a].y1 - l1.first * L[a].x1;
	if (!point.first) return make_pair(0, l1.second);
	l2.first = point.second / (double) point.first;
	l2.second = point.second - l2.first * point.first;
	if (abs(l1.first - l2.first) <= 1e-14) return min(make_pair(L[a].x1, L[a].y1), make_pair(L[a].x2, L[a].y2));
	result.first = (l2.second - l1.second) / (l1.first - l2.first);
	result.second = l1.second + result.first * l1.first;
	return result;
}
struct cmp
{
	bool operator () (const int a, const int b) const
	{
		return make_pair(get_dis(cross(a)), a) < make_pair(get_dis(cross(b)), b);
	}
};
set <int, cmp> Se;
set <int, cmp> :: iterator It[Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		for (int j = 1; j <= m; j++)
			ct++, scanf("%lf%lf", &x[ct], &y[ct]), ord[ct] = ct;
		x[ct + 1] = x[ct - m + 1], y[ct + 1] = y[ct - m + 1];
		for (int j = ct - m + 1; j <= ct; j++)
		{
			int k = j == ct ? ct - m + 1 : j + 1;
			tmp_Ve.push_back(make_pair(x[j], y[j]));
			L[0] = (line){x[j], y[j], x[k], y[k]};
			pair <double, double> p = cross(0, make_pair(-1, 0));
			if (p.first < 0)
			{
				if (y[j] <= 0 && y[k] >= 0)
				{
					tmp_Ve.push_back(make_pair(p.first, -1e-14));
					tmp_Ve.push_back(make_pair(p.first, 1e-14));
				}
				else if (y[j] >= 0 && y[k] <= 0)
				{
					tmp_Ve.push_back(make_pair(p.first, 1e-14));
					tmp_Ve.push_back(make_pair(p.first, -1e-14));
				}
			}
		}
		ct -= m;
		m = tmp_Ve.size();
		for (auto now : tmp_Ve)
			x[++ct] = now.first, y[ct] = now.second, ord[ct] = ct;
		tmp_Ve.clear();
		for (int j = ct; j >= ct - m + 1; j--)
		{
			int k = j == ct ? ct - m + 1 : j + 1;
			if (abs(y[j]) + abs(y[k]) <= 1e-13)
				continue;
			if (abs(x[j]) + abs(x[k]) <= 1e-13)
				continue;
			L[++line_ct] = (line){x[j], y[j], x[k], y[k]};
			if (make_pair(atan2(y[j], x[j]), get_dis(j, 0)) < make_pair(atan2(y[k], x[k]), get_dis(k, 0)))
			{
				Start[j].push_back(line_ct);
				End[k].push_back(line_ct);
			}
			else
			{
				Start[k].push_back(line_ct);
				End[j].push_back(line_ct);
			}
		}
	}
	sort(ord + 1, ord + 1 + ct, [](int a, int b){return make_pair(atan2(y[a], x[a]), get_dis(a, 0)) < make_pair(atan2(y[b], x[b]), get_dis(b, 0));});
	for (int i = 1; i <= ct; i++)
	{
		P = make_pair(x[ord[i]], y[ord[i]]);
		if (!P.second) P.second += P.first < 0 ? -1e-11 : 1e-11;
		if (P.second < 0) P.first += 1e-11;
		if (P.second > 0) P.first -= 1e-11;
		for (auto now : Start[ord[i]])
			It[now] = Se.insert(now).first;
		for (auto now : End[ord[i]])
			Se.erase(It[now]);
		if (Se.size() > 1)
		{
			int l1 = *Se.begin(), l2 = *(++Se.begin());
			pair <double, double> tmp1 = cross(l2), tmp2 = cross(l1);
			pair <double, double> tmp_P = make_pair(x[ord[i + 1]], y[ord[i + 1]]);
			if (S(make_pair(tmp1, cross(l2, tmp_P))) - S(make_pair(tmp2, cross(l1, tmp_P))) < -1e-9)
			{
				return 0;
			}
			ans += S(make_pair(tmp1, cross(l2, tmp_P))) - S(make_pair(tmp2, cross(l1, tmp_P)));
		}
	}
	printf("%.15lf", ans);
	return 0;
}