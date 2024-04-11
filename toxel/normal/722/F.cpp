#include<bits/stdc++.h>
using namespace std;
const long long N = 200010;
const long long M = 45;
long long n, m, num[N][M], ans[N];
typedef pair <long long, long long> P;
P solve[N][20], now;
vector <P> v[N];
vector <int> prime;
long long lg(long long x)
{
	long long _lg = 0;
	while (x > 1)
	{
		x /= 2;
		_lg++;
	}
	return _lg;
}
long long mod(long long a, long long b, long long moder)
{
	if (b <= 100)
		return a * b % moder;
	return (a * (b % 100) % moder + mod(a, b / 100, moder) * 100 % moder) % moder;
}
long long power(long long num,long long index)
{
	long long i,j,bi[60];
	long long ans = 1;
	i = 0;
	while (index)
	{
		bi[i++] = index % 2;
		index /= 2;
	}
	for (j = 0;j < i;j++)
	{
		if (bi[j])
			ans *= num;
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
	long long sit;
	memset(ans, 0, sizeof(ans));
	prime.push_back(2), prime.push_back(3), prime.push_back(5), prime.push_back(7), prime.push_back(11), prime.push_back(13);
	prime.push_back(17), prime.push_back(19), prime.push_back(23), prime.push_back(29), prime.push_back(31), prime.push_back(37);
	scanf("%I64d%I64d", &n, &m);
	for (long long i = 0; i < n; i++)
	{
		scanf("%d", &num[i][0]);
		for (long long j = 1; j <= num[i][0]; j++)
			scanf("%d", &num[i][j]);
	}
	for (long long i = 0; i < n; i++)
		for (long long j = 1; j <= num[i][0]; j++)
			v[num[i][j]].push_back(make_pair(i, j));
	for (long long i = 1; i <= m; i++)
	{
		long long left = 0, right;
		while (left < v[i].size())
		{
			right = left;
			while (v[i][right].first + 1 == v[i][right + 1].first && right < v[i].size())
				right++;
			for (long long j = left; j <= right; j++)
			{
				solve[j][0] = make_pair(v[i][j].second, num[v[i][j].first][0]);
			}
			long long _lg = lg(right - left) + 1;
			for (long long j = 1; j <= _lg; j++)
				for (long long k = left; k <= right; k++)
				{
					solve[k][j] = crt(solve[k][j - 1], solve[k + power(2, j - 1)][j - 1]);
				}
			for (long long j = left; j <= right; j++)
			{
				now = make_pair(0, 1);
				sit = j; 
				for (long long k = _lg; k >= 0; k--)
				{
					if (crt(now, solve[sit][k]).second > 0)
					{
						now = crt(now, solve[sit][k]);
						sit += power(2, k);
					}
				}
				ans[i] = max(sit - j, ans[i]);
			}
			for (long long j = left; j <= right; j++)
				for (long long k = 0; k <= _lg; k++)
					solve[j][k] = make_pair(0, 0);
			left = right + 1;
		}
	}
	for (long long i = 1; i <= m; i++)
		printf("%I64d\n", ans[i]);
	return 0;
}