/**
4 0 0
1 1
2 2
2 0
-1 -1
**/
#include <bits/stdc++.h>
using namespace std;
struct point
{
	long long x, y;
	point() {}
	point(long long x, long long y): x(x), y(y) {}
	void get()
	{
		cin >> x >> y;
	}
};
point operator-(point a, point b)
{
	return point(a.x - b.x, a.y - b.y);
}
point operator^(point a, point b)
{
	return b - a;
}
long long crossP(point a, point b)
{
	return a.x * b.y - b.x * a.y;
}
int main()
{
	long long n;
	cin >> n;
	point O;
	O.get();
	point A[n];
	for (long long i = 0; i < n; i++)
		A[i].get();
	long long t = 0;
	for (long long i = 0; i < n; i++)
	{
		bool ok = true;
		for (long long j = i + 1; j < n; j++)
			if (crossP(O ^ A[i], O ^ A[j]) == 0)
				ok = false;
		t += ok;
	}
	cout << t;
	return 0;
}