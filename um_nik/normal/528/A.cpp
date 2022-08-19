#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = (int)2e5 + 200;
int w, h;
set<pii> xs, ys;
int a[N], b[N];
int x[2 * N][2];
int y[2 * N][2];
int xSz, ySz;

void init()
{
	scanf("%d%d", &w, &h);
	xs.insert(mp(-w, 0));
	ys.insert(mp(-h, 0));
	x[0][0] = 0;
	x[0][1] = w;
	y[0][0] = 0;
	y[0][1] = h;
	xSz = ySz = 1;
	return;
}

void createNewX(int l, int r)
{
	int ot = a[l];
	int nt = xSz++;
	xs.erase(mp(x[ot][0] - x[ot][1], ot));
	if (x[ot][0] == l)
		x[ot][0] = r;
	else
		x[ot][1] = l;
	x[nt][0] = l;
	x[nt][1] = r;
	for (int i = l; i < r; i++)
		a[i] = nt;
	xs.insert(mp(x[ot][0] - x[ot][1], ot));
	xs.insert(mp(x[nt][0] - x[nt][1], nt));
	return;
}

void query1()
{
	int l;
	scanf("%d", &l);
	int t = a[l];
	if (l - x[t][0] < x[t][1] - l)
		createNewX(x[t][0], l);
	else
		createNewX(l, x[t][1]);
	return;
}

void createNewY(int l, int r)
{
	int ot = b[l];
	int nt = ySz++;
	ys.erase(mp(y[ot][0] - y[ot][1], ot));
	if (y[ot][0] == l)
		y[ot][0] = r;
	else
		y[ot][1] = l;
	y[nt][0] = l;
	y[nt][1] = r;
	for (int i = l; i < r; i++)
		b[i] = nt;
	ys.insert(mp(y[ot][0] - y[ot][1], ot));
	ys.insert(mp(y[nt][0] - y[nt][1], nt));
	return;
}

void query2()
{
	int l;
	scanf("%d", &l);
	int t = b[l];
	if (l - y[t][0] < y[t][1] - l)
		createNewY(y[t][0], l);
	else
		createNewY(l, y[t][1]);
	return;
}


void query()
{
	char c;
	scanf(" %c", &c);
	if (c == 'V')
		query1();
	else
		query2();
	int X = xs.begin()->first;
	int Y = ys.begin()->first;
//	printf("%d %d\n", X, Y);
	printf("%I64d\n", (ll)X * Y);
	return;
}

int main()
{
	init();
	int q;
	scanf("%d", &q);
	while(q--)
		query();

	return 0;
}