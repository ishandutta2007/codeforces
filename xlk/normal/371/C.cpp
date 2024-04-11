#include <bits/stdc++.h>
using namespace std;
string s;
long long h[3], n[3], p[3], r;
bool ok(long long M)
{
	return
	max(h[0] * M - n[0], 0LL) * p[0] + 
	max(h[1] * M - n[1], 0LL) * p[1] + 
	max(h[2] * M - n[2], 0LL) * p[2] <= r;
}
int main()
{
	cin >> s >> n[0] >> n[1] >> n[2] >> p[0] >> p[1] >> p[2] >> r;
	for (char i: s)
	{
		if (i == 'B')
		{
			h[0]++;
		}
		else if (i == 'S')
		{
			h[1]++;
		}
		else
		{
			h[2]++;
		}
	}
	long long L = 0, R = 1e13;
	while (L < R - 1)
	{
		long long M = (L + R) / 2;
		if (ok(M))
		{
			L = M;
		}
		else
		{
			R = M;
		}
	}
	cout << L << endl;
	return 0;
}