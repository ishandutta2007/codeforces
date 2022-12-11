#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[1000];

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif


	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	
		cin >> a[i];

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int s = i; s < n; s++)
		{             
			int cnt = 0;
			for (int q = 0; q < n; q++)
			{
				if (q < i || q > s)
					cnt += a[q];
				else
					cnt += (1 - a[q]);
			}
			ans = max(cnt, ans);
		}

	cout << ans;

	return 0;
}