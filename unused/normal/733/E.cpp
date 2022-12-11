#include <stdio.h>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

char str[1000005];
long long dsum[1000005], usum[1000005];

// Returns the sum from index 1 to p, inclusive
long long dquery(int p) {
	long long ret = 0;
	for (; p > 0; p -= p & -p) ret += dsum[p];
	return ret;
}

// Adds val to element with index pos
void dadd(int p, int val) {
	for (; p <= 1000000; p += p & -p) dsum[p] += val;
}

// Returns the sum from index 1 to p, inclusive
long long uquery(int p) {
	long long ret = 0;
	for (; p > 0; p -= p & -p) ret += usum[p];
	return ret;
}

// Adds val to element with index pos
void uadd(int p, int val) {
	for (; p <= 1000000; p += p & -p) usum[p] += val;
}

int main()
{
	int n;
	scanf("%d%s", &n, str + 1);

	vector<int> u, d;

	for (int i = n; i >= 1; i--)
	{
		if (str[i] == 'D')
		{
			d.push_back(i);
			dadd(i, i);
		}
		else uadd(i, i);
	}

	// d:  
	// u:  

	for (int i = 1; i <= n; i++)
	{
		if (str[i - 1] == 'U') u.push_back(i - 1);
		while (d.empty() == false && d.back() <= i) d.pop_back();

		if (str[i] == 'U')
		{
			// U:  D   U   ,   
			if (d.size() > u.size()) // left
			{
				long long dnum = u.size() + 1; long long unum = u.size();

				long long ans = i;
				ans += (i * unum - uquery(i - 1)) * 2;
				ans += ((dquery(d[d.size() - dnum]) - dquery(i)) - i * dnum) * 2;
				printf("%lld ", ans);
			}
			else // right
			{
				long long dnum = d.size(); long long unum = d.size();

				long long ans = n - i + 1;
				ans += (i * unum - (uquery(i - 1) - (d.size() == u.size() ? 0 : uquery(u[u.size() - d.size() - 1])))) * 2;
				ans += (dquery(n) - dquery(i) - i * dnum) * 2;
				printf("%lld ", ans);
			}
		}
		else
		{
			// D:  D   U    ,   
			if (d.size() >= u.size()) // left
			{
				long long dnum = u.size(); long long unum = u.size();

				long long ans = i;
				ans += (i * unum - uquery(i - 1)) * 2;
				if (dnum) ans += ((dquery(d[d.size() - dnum]) - dquery(i)) - i * dnum) * 2;
				printf("%lld ", ans);
			}
			else // right
			{
				long long dnum = d.size(); long long unum = d.size() + 1;

				long long ans = n - i + 1;
				ans += (i * unum - (uquery(i - 1) - (unum == u.size() ? 0 : uquery(u[u.size() - unum - 1])))) * 2;
				ans += (dquery(n) - dquery(i) - i * dnum) * 2;
				printf("%lld ", ans);
			}
		}
	}
}