#include <bits/stdc++.h>
using namespace std;
int t;
long long n, a, b;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> a >> b;
		int flag = 1;
		for (long long r = 1; r <= n; r *= a)
		{
			if ((n - r) % b == 0)
			{
				cout << "Yes" << endl;
				flag = 0;
				break;
			}
			if (a == 1)
			{
				break;
			}
		}
		if (flag)
		{
			cout << "No" << endl;
		}
	}
	return 0;
}