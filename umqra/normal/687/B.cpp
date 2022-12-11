#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <algorithm>

#include <valarray>
#include <complex>
#include <functional>
#include <cassert>

using namespace std;
typedef long long ll;

const int N = (int)1e6 + 10;
int n, k;
int arr[N];
int minD[N];
int used[N];

void read()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
}

void precalc()
{
	for (int i = 0; i < N; i++)
		minD[i] = i;
		
	for (int i = 2; i < N; i++)
	{
		if (!used[i])
		{
			for (int s = i; s < N; s += i)
			{
				used[s] = 1;
				minD[s] = min(minD[s], i);
			}
		}
	}
}

int kFactors[N];
int arrFactors[N];

void getFactors(int x, int *f)
{
	int d = minD[x];
	int cnt = 0;
	
	while (1)
	{
		if (d == minD[x])
			cnt++;
		else
		{
			f[d] = max(f[d], cnt);
			
			d = minD[x];
			cnt = 1;
		}
		
		if (x == 1)
			break;
			
		x /= minD[x];
	}
}

void solve()
{
	precalc();
	getFactors(k, kFactors);
	for (int i = 0; i < n; i++)
	{
		getFactors(arr[i], arrFactors);
	}	
	for (int i = 0; i < N; i++)
	{
		if (arrFactors[i] < kFactors[i])
		{
			puts("No");
			return;
		}
	}
	puts("Yes");
}

int main()
{
	read();
	solve();
    return 0;
}