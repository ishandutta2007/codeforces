#include <iostream>
#include <cstdio>
#include <numeric>
#include <algorithm>
using namespace std;

const int MaxN = 100000;
const int MaxM = 100000;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	static int a[MaxN + 1];
	int m;
	static int b[MaxN + 1];
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	cin >> m;
	for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
	
	int numLen = 0;
	static int num[MaxN + MaxM];
	static int val[MaxN + MaxM];
	
	int resLen = 0;
	static int res[MaxN + MaxM];
	for (int cur = 0, i = n, j = m; i >= 1 || j >= 1; cur ^= 1)
	{
		while (i >= 1 && a[i] == cur)
		{
			num[numLen] = i;
			val[numLen] = cur;
			numLen++;
			i--;
		}
		while (j >= 1 && b[j] == cur)
		{
			num[numLen] = j + n;
			val[numLen] = cur;
			numLen++;
			j--;
		}
	}
	
	reverse(num, num + numLen);
	reverse(val, val + numLen);
	for (int i = 0; i < numLen; i++)
		printf("%d ", num[i]);
	cout << endl;
	
	for (int i = 0, j = 0; i < numLen; i = j)
	{
		while (j < numLen && val[i] == val[j])
			j++;
		if (j == numLen && val[i] == 0)
			continue;
		res[resLen++] = j;
	}
	
	cout << resLen << endl;
	for (int i = 0; i < resLen; i++)
		printf("%d ", res[i]);
	cout << endl;
	
	return 0;
}