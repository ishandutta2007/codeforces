#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int MaxM = 100;
const int MaxN = 100;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int m, k;
	static bool isGood[MaxM + 1];
	
	cin >> m >> k;
	for (int i = 1; i <= k; i++)
	{
		int a;
		cin >> a;
		isGood[a] = true;
	}
	
	int n;
	
	cin >> n;
	static int maxPoss[MaxN + 1], minPoss[MaxN + 1];
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		
		int d;
		cin >> d;
		int nGood = 0, nNotGood = 0;
		for (int j = 1; j <= d; j++)
		{
			int b;
			cin >> b;
			if (b == 0)
				continue;
			
			if (isGood[b])
				nGood++;
			else
				nNotGood++;
		}
		int rest = d - nGood - nNotGood;
		minPoss[i] = nGood;
		if (m - k - nNotGood < rest)
			minPoss[i] += rest - (m - k - nNotGood);
		
		maxPoss[i] = d - nNotGood;
		if (k - nGood < rest)
			maxPoss[i] = k;
	}
	
	for (int i = 1; i <= n; i++)
	{
		bool ok = true;
		for (int j = 1; j <= n; j++)
			if (i != j && minPoss[i] < maxPoss[j])
			{
				ok = false;
				break;
			}
		if (ok)
		{
			puts("0");
			continue;
		}
		
		ok = false;
		for (int j = 1; j <= n; j++)
			if (i != j && minPoss[j] > maxPoss[i])
			{
				ok = true;
				break;
			}
		if (ok)
		{
			puts("1");
			continue;
		}
		
		puts("2");
	}
	
	return 0;
}