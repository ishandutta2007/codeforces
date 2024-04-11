#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long s64;

const int MaxN = 1000;
const int MaxT = 1560;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

struct task
{
	int a, b;
	int s, t;
	double p;

	friend inline bool operator<(const task &lhs, const task &rhs)
	{
		return lhs.t * lhs.p * (1 - rhs.p) < rhs.t * rhs.p * (1 - lhs.p);
	}
};

struct f_t
{
	s64 score;
	double time;

	friend inline bool operator>(const f_t &lhs, const f_t &rhs)
	{
		if (lhs.score != rhs.score)
			return lhs.score > rhs.score;
		return lhs.time < rhs.time;
	}
};

int main()
{
	int n, totT;
	static task a[MaxN];

	cin >> n >> totT;
	for (int i = 0; i < n; i++)
		scanf("%d %d %d %d %lf", &a[i].a, &a[i].b, &a[i].s, &a[i].t, &a[i].p);

	sort(a, a + n);

	const int B = 1000000;

	static f_t f[MaxT + 1];
	for (int i = 0; i < n; i++)
		for (int j = totT; j >= 0; j--)
		{
			if (j >= a[i].s)
			{
				f_t cur = f[j - a[i].s];
				cur.score += (s64)a[i].a * B;
				cur.time += a[i].s;
				relax(f[j], cur);
			}
			if (j >= a[i].s + a[i].t)
			{
				f_t cur = f[j - a[i].s - a[i].t];
				cur.score += (s64)a[i].a * B + a[i].b * (s64)floor((1 - a[i].p) * B + 0.5);
				cur.time = (a[i].s + cur.time) * a[i].p + j * (1 - a[i].p);
				relax(f[j], cur);
			}
		}

	f_t res = f[0];
	for (int j = 1; j <= totT; j++)
		relax(res, f[j]);
	printf("%.10f %.10f\n", (double)res.score / B, res.time);

	return 0;
}