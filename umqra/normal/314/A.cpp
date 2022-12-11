#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;
const int N = (int)1e6;

int a[N];
ll sum[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n, d;
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);


	int del = 0;
	ll curD = 0;
	ll curSum = 0;
	for (int i = 1; i < n; i++)
	{                                              
		if (curD - (ll)(n - i - 1) * (ll)a[i] * (ll)(i - del) < (ll)d)
		{
			del++;
			printf("%d\n", i + 1);
		}
		else
		{                      
			curD += (ll)a[i] * (ll)(i - del);
		}	                    
	}

	return 0;
}