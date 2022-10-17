#include <bits/stdc++.h>
using namespace std;
int w, h;
int pw(int x, int y, int p)
{
	int re = 1;
	for (; y > 0; y >>= 1)
	{
		if (y & 1)
		{
			re = (long long)re * x % p;
		}
		x = (long long)x * x % p;
	}
	return re;
}
int main()
{
	cin >> w >> h;
	cout << pw(2, w + h, 998244353) << endl;
	return 0;
}