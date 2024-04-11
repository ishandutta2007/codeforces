#include <bits/stdc++.h>
using namespace std;
int t;
long long a, b, c, d;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a >> b >> c >> d;
		vector<int> r, s;
		for (int i = 1; i * i <= a; i++)
		{
			if (a % i == 0)
			{
				r.push_back(i);
				r.push_back(a / i);
			}
		}
		for (int i = 1; i * i <= b; i++)
		{
			if (b % i == 0)
			{
				s.push_back(i);
				s.push_back(b / i);
			}
		}
		for (int i : r)
		{
			for (int j : s)
			{
				long long f = i * b / j;
				long long g = a / i * j;
				if (a / f != c / f && b / g != d / g)
				{
					cout << c / f * f << " " << d / g * g << endl;
					goto end;
				}
			}
		}
		cout << "-1 -1" << endl;
		end:;
	}
	return 0;
}