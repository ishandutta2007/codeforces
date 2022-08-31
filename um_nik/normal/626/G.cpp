#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef pair<double, int> pdi;
#define mp make_pair

double eps = 1e-11;
bool eq(double x, double y)
{
	return fabs(x - y) < eps;
}
bool ls(double x, double y)
{
	return x < y && !eq(x, y);
}

bool cmp(const pdi &A, const pdi &B)
{
	if (eq(A.first, B.first))
		return A.second < B.second;
	return A.first < B.first;
}

struct Item
{
	pdi a;
	bool operator () (const pdi &A, const pdi &B)
	{
		if (eq(A.first, B.first))
			return A.second < B.second;
		return A.first < B.first;
	}
};

const int C1 = 3;
const int C2 = 7;
const int N = 300200;
double ans;
int n, m, q;
int a[N], b[N];
double p[N];
set<pdi, Item> ifAdd, ifRemove;

void deleteInfo(int id)
{
//	printf("delete info %d\n", id);
	if (b[id] > 0)
	{
		double x = (double)b[id] / (a[id] + b[id]) - (double)(b[id] - 1) / (a[id] + b[id] - 1);
		ifRemove.erase(mp(x * p[id], id));
	}
	if (b[id] < a[id])
	{
		double x = (double)b[id] / (a[id] + b[id]) - (double)(b[id] + 1) / (a[id] + b[id] + 1);
		ifAdd.erase(mp(x * p[id], id));
	}
}
void addInfo(int id)
{
//	printf("add info %d\n", id);
	if (b[id] > 0)
	{
		double x = (double)b[id] / (a[id] + b[id]) - (double)(b[id] - 1) / (a[id] + b[id] - 1);
		ifRemove.insert(mp(x * p[id], id));
	}
	if (b[id] < a[id])
	{
		double x = (double)b[id] / (a[id] + b[id]) - (double)(b[id] + 1) / (a[id] + b[id] + 1);
		ifAdd.insert(mp(x * p[id], id));
	}
}

void addOne(int id)
{
	if (m == 0 || a[id] == b[id]) throw;
	deleteInfo(id);
	double x = (double)b[id] / (a[id] + b[id]) - (double)(b[id] + 1) / (a[id] + b[id] + 1);
	ans -= x * p[id];
	b[id]++;
	m--;
	addInfo(id);
}
void removeOne(int id)
{
	if (b[id] == 0) throw;
	deleteInfo(id);
	double x = (double)b[id] / (a[id] + b[id]) - (double)(b[id] - 1) / (a[id] + b[id] - 1);
	ans -= x * p[id];
	b[id]--;
	m++;
	addInfo(id);
}

void deleteSome()
{
	for (int it = 0; it < C2 && !ifRemove.empty(); it++)
	{
		int id = ifRemove.begin()->second;
		removeOne(id);
	}
	return;
}

void takeForWin()
{
//	printf("add size = %d, rem size = %d\n", (int)ifAdd.size(), (int)ifRemove.size());
//	printf("ADD:\n");
//	for (pdi t : ifAdd)
//		printf("%.5lf %d\n", t.first, t.second);
	deleteSome();
	while(m > 0 && !ifAdd.empty())
	{
		int id = ifAdd.begin()->second;
		addOne(id);
	}
	return;
}

void addQuery(int id)
{
	ans -= p[id] * b[id] / (a[id] + b[id]);
	deleteInfo(id);
	a[id]++;
	addInfo(id);
	ans += p[id] * b[id] / (a[id] + b[id]);
	for (int it = 0; it < C1 && b[id] > 0; it++)
		removeOne(id);
	return;
}

void removeQuery(int id)
{
	ans -= p[id] * b[id] / (a[id] + b[id]);
	deleteInfo(id);
	a[id]--;
	addInfo(id);
	ans += p[id] * b[id] / (a[id] + b[id]);
	if (b[id] > a[id])
		removeOne(id);
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++)
		scanf("%lf", &p[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		b[i] = 0;
	for (int i = 0; i < n; i++)
		addInfo(i);
	ans = 0;
	takeForWin();
	while(q--)
	{
		int t, w;
		scanf("%d%d", &t, &w);
		w--;
		if (t == 1)
			addQuery(w);
		else
			removeQuery(w);
		takeForWin();
		printf("%.12lf\n", ans);
	}

	return 0;
}