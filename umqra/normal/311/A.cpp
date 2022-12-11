#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	
	int n, k;
	scanf("%d%d", &n, &k);
	if (n * (n - 1) / 2 <= k)
		puts("no solution");
	else
	{
		for (int i = 0; i < n; i++)
			printf("0 %d\n", i);
	}                    

	return 0;
}