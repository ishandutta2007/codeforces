/***
4 1 1
1 1 2 1
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	int n, a, b, c = 0;
	cin >> n >> a >> b;
	int d = 0;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			if (a)
			{
				a--;
			}
			else
			{
				if (b)
				{
					b--;
					c++;
				}
				else if (c)
					c--;
				else
					d++;
			}
		}
		else
		{
			if (b)
			{
				b--;
			}
			else
				d += 2;
		}
	}
	cout << d;
}