#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int MaxN = 2000;

const int Mod = 1000000007;
inline void modplusto(int &lhs, const int &rhs)
{
	lhs += rhs;
	if (lhs >= Mod)
		lhs -= Mod;
}
inline int modmult(const int &lhs, const int &rhs)
{
	return (s64)lhs * rhs % Mod;
}
inline int moddiv(const int &lhs, const int &rhs)
{
	int p1 = 1, q1 = 0, r1 = rhs;
	int p2 = 0, q2 = 1, r2 = Mod;
	
	while (r2 != 1)
	{
		int k = r1 / r2;
		int p3, q3, r3;
		p3 = p1 - k * p2;
		q3 = q1 - k * q2;
		r3 = r1 % r2;
		
		p1 = p2, q1 = q2, r1 = r2;
		p2 = p3, q2 = q3, r2 = r3;
	}
	if (p2 < 0)
		p2 += Mod;
	
	return modmult(lhs, p2);
}

int main()
{
	int n, k;
	static int a[MaxN];
	
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	static int res[MaxN];
	
	if (k != 0)
	{
		static int coe[MaxN];
		coe[0] = 1;
		for (int i = 1; i < n; i++)
			coe[i] = moddiv(modmult(coe[i - 1], (k + i - 1) % Mod), i);
		
		for (int i = 0; i < n; i++)
		{
			res[i] = 0;
			for (int j = 0; j <= i; j++)
				modplusto(res[i], modmult(a[j], coe[i - j]));
		}
	}
	else
		copy(a, a + n, res);
	
	for (int i = 0; i < n; i++)
		printf("%d ", res[i]);
	cout << endl;
	
	return 0;
}