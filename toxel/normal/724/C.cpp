#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef pair <long long, long long> P;
long long mod(long long a, long long b, long long moder)
{
	if (b <= 100)
		return a * b % moder;
	return (a * (b % 100) % moder + mod(a, b / 100, moder) * 100 % moder) % moder;
}
long long power(long long num,long long index)
{
	long long ans = 1;
	while (index)
	{
		if (index & 1)
			ans *= num;
		index /= 2;
		num *= num;
	}
	return ans;
}
long long extended_euclid(long long a, long long b, long long &x, long long &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long ans = extended_euclid(b, a % b, x, y);
	long long p = y;
	y = x - a / b * y;
	x = p;
	if (x < 0)
	{
		y += (x / b - 1) * a;
		x -= (x / b - 1) * b;
	}
	if (x > b)
	{
		y += x / b * a;
		x %= b;
	}
	return ans;
}
P crt(P p1, P p2)
{
	long long x, y;
	if (p1.second == 0 || p2.second == 0)
		return make_pair(0, 0);
	if (p2.first < p1.first)
	{
		P p = p1;
		p1 = p2;
		p2 =p;
	}
	long long gcd = extended_euclid(p1.second, p2.second, x, y);
	if ((p2.first - p1.first) % gcd)
		return make_pair(0, 0);
	long long lcm = p1.second / gcd * p2.second;
	long long ans = (p2.first - p1.first) / gcd;
	ans = mod(ans, x, lcm);
	ans = mod(ans, p1.second, lcm);
	ans = (ans + p1.first) % lcm;
	return make_pair(ans, lcm); 
}
int main()
{
	int n, m, k, x, y;
	long long ans[N];
	for (int i = 0; i < N; i++)
		ans[i] = -1;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d", &x, &y);
		P solve = crt(make_pair(x, n), make_pair(y, m));
		if (solve.second && !(solve.first / n & 1) && !(solve.first / m & 1))
		{
			if (ans[i] == -1)
				ans[i] = solve.first;
			else
				ans[i] = min(ans[i], solve.first);
		}
		solve = crt(make_pair(n - x, n), make_pair(y, m));
		if (solve.second && (solve.first / n & 1) && !(solve.first / m & 1))
		{
			if (ans[i] == -1)
				ans[i] = solve.first;
			else
				ans[i] = min(ans[i], solve.first);
		}
		solve = crt(make_pair(x, n), make_pair(m - y, m));
		if (solve.second && !(solve.first / n & 1) && (solve.first / m & 1))
		{
			if (ans[i] == -1)
				ans[i] = solve.first;
			else
				ans[i] = min(ans[i], solve.first);
		}
		solve = crt(make_pair(n - x, n), make_pair(m - y, m));
		if (solve.second && (solve.first / n & 1) && (solve.first / m & 1))
		{
			if (ans[i] == -1)
				ans[i] = solve.first;
			else
				ans[i] = min(ans[i], solve.first);
		}
	}
	for (int i = 0; i < k; i++)
		printf("%I64d\n", ans[i]);
	return 0;
}