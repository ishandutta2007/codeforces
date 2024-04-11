#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = (int)1e6 + 10;
char ans[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	
	int n, k;
	cin >> n >> k;
	if (k == 1)
	{
		if (n == 1)
			cout << "a";
		else
			cout << -1;
		return 0;
	}
	if (k > n)
	{
		cout << -1;
		return 0;
	}

	for (int i = 0; i < n; i++)
		ans[i] = (i % 2) + 'a';

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < 2)
			cnt++;
		putchar(ans[i]);
		if (cnt + (n - i - 1) == k)
		{
			for (int s = cnt; s < k; s++)
				putchar(s + 'a');
			return 0;
		}               
	}

	return 0;
}