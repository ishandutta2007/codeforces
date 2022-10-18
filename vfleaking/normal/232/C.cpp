#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long s64;

const int MaxN = 1000;
const s64 MaxVertexNum = 10000000000000000ll;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

int n;
s64 fib[MaxN + 1];

s64 handle(const s64 &v, const s64 &u)
{
	static s64 vList[1 + MaxN];
	static s64 uList[1 + MaxN];
	
	vList[n] = v;
	uList[n] = u;
	for (int i = n - 1; i >= 1; i--)
	{
		vList[i] = vList[i + 1];
		if (vList[i] > fib[i])
			vList[i] -= fib[i];
		
		uList[i] = uList[i + 1];
		if (uList[i] > fib[i])
			uList[i] -= fib[i];
	}
	
	static s64 fvb[MaxN + 1], fve[MaxN + 1];
	static s64 fub[MaxN + 1], fue[MaxN + 1];
	static s64 distBE[MaxN + 1], distVU[MaxN + 1];
	
	fvb[0] = fve[0] = 0ll;
	fub[0] = fue[0] = 0ll;
	distBE[0] = 0;
	distVU[0] = 0;
	
	fvb[1] = vList[1] != 1, fve[1] = vList[1] != 2;
	fub[1] = uList[1] != 1, fue[1] = uList[1] != 2;
	distBE[1] = 1ll;
	distVU[1] = vList[1] != uList[1];
	
	for (int i = 2; i <= n; i++)
	{
		if (vList[i] > fib[i - 1])
		{
			fvb[i] = fvb[i - 2] + 1ll;
			fve[i] = fve[i - 2];
		}
		else
		{
			fvb[i] = min(fve[i - 1] + 2ll, fvb[i - 1]);
			fve[i] = min(fvb[i - 1], fve[i - 1]) + 1ll + distBE[i - 2];
		}
		
		if (uList[i] > fib[i - 1])
		{
			fub[i] = fub[i - 2] + 1ll;
			fue[i] = fue[i - 2];
		}
		else
		{
			fub[i] = min(fue[i - 1] + 2ll, fub[i - 1]);
			fue[i] = min(fub[i - 1], fue[i - 1]) + 1ll + distBE[i - 2];
		}
		
		distBE[i] = distBE[i - 2] + 1;
		
		if (vList[i] <= fib[i - 1] && uList[i] <= fib[i - 1])
		{
			distVU[i] = distVU[i - 1];
			tension(distVU[i], fvb[i - 1] + fue[i - 1] + 2ll);
			tension(distVU[i], fve[i - 1] + fub[i - 1] + 2ll);
		}
		else if (vList[i] > fib[i - 1] && uList[i] > fib[i - 1])
			distVU[i] = distVU[i - 2];
		else if (vList[i] <= fib[i - 1])
			distVU[i] = min(fvb[i - 1], fve[i - 1]) + fub[i - 2] + 1ll;
		else
			distVU[i] = min(fub[i - 1], fue[i - 1]) + fvb[i - 2] + 1ll;
	}
	return distVU[n];
}

int main()
{
	int nCases;
	cin >> nCases >> n;
	
	tension(n, 77);
	
	fib[0] = 1;
	fib[1] = 2;
	for (int i = 2; i <= n; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	
	while (nCases--)
	{
		s64 v, u;
		cin >> v >> u;
		cout << handle(v, u) << endl;
	}
	
	return 0;
}