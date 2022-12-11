#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map <int, int> cntId;

int main()
{          
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);	
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		if (a == 0)
			continue;
		if (cntId.find(a) == cntId.end())
			cntId[a] = 1;
		else
		{
			cntId[a]++;
			if (cntId[a] == 2)
				ans++;
			else 
			{
				puts("-1");
				return 0;
			}		
		}
	}
	printf("%d", ans);
	return 0;
}