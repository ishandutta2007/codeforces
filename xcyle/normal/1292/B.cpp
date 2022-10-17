#include <iostream>
#include <cstdio>
#define maxn 100
using namespace std;
const long long INF = 2e16;
long long ax, ay, bx, by;
long long px, py, t;
long long x[maxn], y[maxn];
inline long long calc(long long a1, long long b1, long long a2, long long b2)
{
	if(a1 < a2) swap(a1, a2);
	if(b1 < b2) swap(b1, b2);
	return a1 - a2 + b1 - b2;
}
inline int check(int l, int r)
{
	long long res = calc(x[l], y[l], x[r], y[r]);
	res += min(calc(px, py, x[l], y[l]), calc(px, py, x[r], y[r]));
	return res <= t ? 1 : 0; 
}
int main()
{
	scanf("%lld%lld%lld%lld%lld%lld", &x[0], &y[0], &ax, &ay, &bx, &by);
	scanf("%lld%lld%lld", &px, &py, &t);
	for (int i = 1; i <= 58; i++)
	{
		x[i] = ax * x[i - 1] + bx;
		y[i] = ay * y[i - 1] + by;
		x[i] = min(x[i], INF);
		y[i] = min(y[i], INF);
	}
	int ans = 0;
	for (int i = 0; i <= 58; i++)
	{
		for (int j = i; j <= 58; j++)
		{
			if(check(i, j)) 
			{
				ans = max(ans, j - i + 1);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}