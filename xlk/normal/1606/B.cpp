#include <bits/stdc++.h>
using namespace std;
int t;
long long n, k;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> k;
		long long z = 0, s = 1;
		while (s < n && s < k)
		{
			s *= 2;
			z++;
		}
		z += (n - s + k - 1) / k;
		cout << z << endl;
	}
	return 0;
}