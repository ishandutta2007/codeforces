#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> vec;
int n, a[202020][2];
void solve1(int a)
{
	for(int i = 2; i * i <= a; i++)
		if(a % i == 0)
		{
			vec.push_back(i);
			while(a % i == 0)
				a /= i;
		}
	if(a > 1)
		vec.push_back(a);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &a[i][0], &a[i][1]);
	solve1(a[1][0]);
	solve1(a[1][1]);
	for(int i: vec)
	{
		bool ok = true;
		for(int j = 1; j <= n; j++)
			if(a[j][0] % i != 0 && a[j][1] % i != 0)
			{
				ok = false;
				break;
			}
		if(ok)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}