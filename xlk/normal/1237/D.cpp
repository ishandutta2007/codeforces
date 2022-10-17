#include <bits/stdc++.h>
using namespace std;
int n, a[100020];
multiset<int> s;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (2**min_element(a, a + n) < *max_element(a, a + n))
	{
		for (int i = 0, j = 0; i < n;)
		{
			for (;s.empty() || 2 * a[j % n] >= *s.rbegin();)
			{
				s.insert(a[j++ % n]);
			}
			printf("%d%c", j - i, i == n - 1 ? '\n' : ' ');
			s.erase(s.find(a[i++]));
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d%c", -1, i == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}