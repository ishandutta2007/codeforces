#pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
long long v[1000010][2];
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	long long temp = 0, sum = 0, ans = 0;
	for (register int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] == 'v')
		{
			temp++;
		}
		else
		{
			if (temp > 1)
			{
				sum += temp - 1;
			}
			temp = 0;
			v[i][0] = sum;
		}
	}
	temp = 0;
	sum = 0;
	for (register int i = (int)s.size() - 1; i >= 0; i--)
	{
		if (s[i] == 'v')
		{
			temp++;
		}
		else
		{
			if (temp > 1)
			{
				sum += temp - 1;
			}
			temp = 0;
			v[i][1] = sum;
		}
	}
	for (register int i = 0; i <= (int)s.size(); i++)
	{
		if(s[i] == 'o')
		{
			ans += v[i][0] * v[i][1];
		}
	}
	cout << ans;
	return 0;
}