#include <bits/stdc++.h>
using namespace std;
int n,x,now;
int main()
{
	scanf("%d",&n);
	now=3;
	while (n--)
	{
		scanf("%d",&x);
		if (x==now)
		{
			cout << "NO" << endl;
			return 0;
		}
		now=6-now-x;
	}
	cout << "YES" << endl;
	return 0;
}