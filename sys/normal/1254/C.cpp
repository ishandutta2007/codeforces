#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int n, x, y, maxi1, maxi2, result[Maxn];
long long val[Maxn];
vector <int> Ve[5];
bool cmp2(int x, int y)
{
	return val[x] > val[y];
}
bool cmp1(int x, int y)
{
	return val[x] < val[y];
}
int main()
{
	scanf("%d", &n);
	x = 1, y = 2;
	for (int i = 3; i <= n; i++)
	{
		printf("2 %d %d %d\n", x, y, i);
		fflush(stdout);
		scanf("%d", &result[i]);
		result[i] /= abs(result[i]);
		printf("1 %d %d %d\n", x, y, i);
		fflush(stdout);
		scanf("%lld", &val[i]);
		if (result[i] == -1 && val[i] > val[maxi1]) maxi1 = i;
		if (result[i] == 1 && val[i] > val[maxi2]) maxi2 = i;
	}
	for (int i = 3; i <= n; i++)
	{
		if (i != maxi1 && i != maxi2)
		{
			int res;
			printf("2 %d %d %d\n", x, result[i] == -1 ? maxi1 : maxi2, i);
			fflush(stdout);
			scanf("%d", &res);
			if (res == 1) Ve[result[i] + 3].push_back(i);
			else Ve[result[i] + 2].push_back(i);
		}
	}
	sort(Ve[4].begin(), Ve[4].end(), cmp2);
	sort(Ve[2].begin(), Ve[2].end(), cmp2);
	sort(Ve[1].begin(), Ve[1].end(), cmp1);
	sort(Ve[3].begin(), Ve[3].end(), cmp1);
	printf("0 "); 
	printf("%d\n", x);
	for (vector <int> :: iterator it = Ve[1].begin(); it != Ve[1].end(); it++)
		printf("%d ", *it);
	if (maxi1) printf("%d ", maxi1);
	for (vector <int> :: iterator it = Ve[2].begin(); it != Ve[2].end(); it++)
		printf("%d ", *it);
	printf("%d ", y);
	for (vector <int> :: iterator it = Ve[3].begin(); it != Ve[3].end(); it++)
		printf("%d ", *it);
	if (maxi2) printf("%d ", maxi2);
	for (vector <int> :: iterator it = Ve[4].begin(); it != Ve[4].end(); it++)
		printf("%d ", *it);
	fflush(stdout);
	return 0;
}