#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		mp[tmp]++;
	}
	printf("%d\n", max(0, n - mp.begin()->second - mp.rbegin()->second));
}