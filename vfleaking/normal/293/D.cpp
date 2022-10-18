#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxXL = 1000000;

const int MaxN = 100000;

inline s64 floor(s64 a, s64 b)
{
	if (b < 0)
		a = -a, b = -b;
	if (a > 0)
		return a / b;
	return -((-a + b - 1) / b);
}
inline s64 ceil(s64 a, s64 b)
{
	return -floor(-a, b);
}

double calc(int n, int *px, int *py)
{
	s64 area = 0;
	for (int i = 0; i < n; i++)
		area += (s64)px[i] * py[i + 1] - (s64)py[i] * px[i + 1];
	if (area < 0)
		reverse(px + 1, px + n), reverse(py + 1, py + n);

	static int h[MaxXL * 2 + 1];
	fill(h, h + MaxXL * 2 + 1, 0);
	for (int i = 0; i < n; i++)
	{
		if (px[i] < px[i + 1])
		{
			for (int x = px[i]; x < px[i + 1]; x++)
				h[x + MaxXL] -= py[i] + ceil((s64)(py[i + 1] - py[i]) * (x - px[i]), px[i + 1] - px[i]) - 1;
			if (px[i + 1] >= px[(i + 2) % n])
				h[px[i + 1] + MaxXL] -= py[i + 1] - 1;
		}
		else if (px[i] > px[i + 1])
		{
			for (int x = px[i]; x > px[i + 1]; x--)
				h[x + MaxXL] += py[i] + floor((s64)(py[i + 1] - py[i]) * (x - px[i]), px[i + 1] - px[i]);
			if (px[i + 1] <= px[(i + 2) % n])
				h[px[i + 1] + MaxXL] += py[i + 1];
		}
	}

	s64 cnt = 0;
	double sum1 = 0;
	double sum2 = 0;
	for (int x = -MaxXL; x <= MaxXL; x++)
	{
		cnt += h[x + MaxXL];
		sum1 += (double)x * h[x + MaxXL];
		sum2 += (double)x * x * h[x + MaxXL];
	}
	return (sum2 - sum1 * sum1 / cnt) / (cnt - 1);
}

int main()
{
	int n;
	static int px[MaxN + 1], py[MaxN + 1];

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d %d", &px[i], &py[i]);
	px[n] = px[0], py[n] = py[0];

	double res = 0;
	res += calc(n, px, py);
	res += calc(n, py, px);

	printf("%.10f\n", res);

	return 0;
}