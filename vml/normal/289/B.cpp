#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);
	n *= m;
	vector <int> v(n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	int mid = v[n / 2];
	int res = 0;
	for(int i = 0; i < n; i++)
	{
		int k = abs(mid - v[i]);
		if(k % d != 0)
		{
			printf("-1");
			return 0;
		}
		else
		{
			res += k / d;
		}
	}
	printf("%d", res);
	return 0;
}