#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t, n, m;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		if (n == 1)
		{
			m = 0;
		}
		else if (n > 2)
		{
			m *= 2;
		}
		cout << m << endl;
	}
	return 0;
}