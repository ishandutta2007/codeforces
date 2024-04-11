#include<bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		long long s = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			s = (s + x) % n;
		}
		cout << s * (n - s) <<endl;
	}
	return 0;
}