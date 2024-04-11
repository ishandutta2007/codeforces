#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef long long s64;

const int MaxN = 10000;
const int GL = 500000;
const int MaxM = 100000;

inline int gcd(int a, int b)
{
	while (b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

int pr;

inline int modpow(const int &a, const int &n)
{
	int res = 1;
	int t = a;
	for (int i = n; i >= 1; i >>= 1)
	{
		if (i & 1)
			res = (s64)res * t % pr;
		t = (s64)t * t % pr;
	}
	return res;
}

int main()
{
	int n, m;
	vector<int> divisor;

	cin >> n >> m >> pr;
	static int a[MaxN + 1], b[MaxM + 1];

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]);

	for (int i = 1; i * i <= pr - 1; i++)
		if ((pr - 1) % i == 0)
		{
			divisor.push_back(i);
			if ((pr - 1) / i != i)
				divisor.push_back((pr - 1) / i);
		}
	sort(divisor.begin(), divisor.end());

	int gcdB = 0;
	for (int i = 1; i <= m; i++)
		gcdB = gcd(gcdB, b[i]);

	vector<bool> has;
	has.resize(divisor.size());

	for (int i = 1; i <= n; i++)
	{
		int ag = modpow(a[i], gcdB);
		int k = (int)divisor.size() - 1;
		while (modpow(ag, (pr - 1) / divisor[k]) != 1)
			k--;
		has[k] = true;
	}

	static vector<int> coe[2];
	coe[0].resize(divisor.size());
	coe[1].resize(divisor.size());
	coe[0][0] = 1;

	for (int i = 0; i < (int)divisor.size(); i++)
		if (has[i])
		{
			for (int j = (int)divisor.size() - 1; j >= 0; j--)
			{
				int cur0 = coe[0][j], cur1 = coe[1][j];
				int k = lower_bound(divisor.begin(), divisor.end(), (s64)divisor[i] * divisor[j] / gcd(divisor[i], divisor[j])) - divisor.begin();
				coe[1][k] += cur0, coe[0][k] += cur1;
			}
		}

	s64 res = pr - 1;
	for (int i = 0; i < (int)divisor.size(); i++)
	{
		res -= (s64)(pr - 1) / divisor[i] * coe[0][i];
		res += (s64)(pr - 1) / divisor[i] * coe[1][i];
	}

	cout << res << endl;

	return 0;
}