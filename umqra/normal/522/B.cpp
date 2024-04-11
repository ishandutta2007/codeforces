#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;
const int N = (int)3e6 + 100;
int w[N], h[N];

int main()
{
	int n;
	scanf("%d", &n);
	int sumW = 0;
	int maxH1 = -1, maxH2 = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &w[i], &h[i]);
		sumW += w[i];
		
		if (h[i] >= maxH1)
		{
			maxH2 = maxH1;
			maxH1 = h[i];
		}
		else if (h[i] >= maxH2)
			maxH2 = h[i];
	}
	

	for (int i = 0; i < n; i++)
	{
		int curW = sumW - w[i];
		int curH = (h[i] == maxH1 ? maxH2 : maxH1);
		printf("%I64d ", (ll)curH * (ll)curW);
	}

	return 0;
}