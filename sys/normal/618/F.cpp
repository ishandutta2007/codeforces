#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
pair <int, int> pos[Maxn];
int n;
long long sum1[Maxn], sum2[Maxn];
bool type;
void print(int lt1, int rt1, int lt2, int rt2)
{
	if (type)
	{
		printf("%d\n", rt2 - lt2 + 1);
		for (int i = lt2; i <= rt2; i++)
			printf("%d ", i);
		printf("\n%d\n", rt1 - lt1 + 1);
		for (int i = lt1; i <= rt1; i++)
			printf("%d ", i);
	}
	else
	{
		printf("%d\n", rt1 - lt1 + 1);
		for (int i = lt1; i <= rt1; i++)
			printf("%d ", i);
		printf("\n%d\n", rt2 - lt2 + 1);
		for (int i = lt2; i <= rt2; i++)
			printf("%d ", i);
	}
	exit(0);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		sum1[i] = sum1[i - 1] + x;
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		sum2[i] = sum2[i - 1] + x;
	}
	if (sum1[n] > sum2[n])
	{
		type = true;
		for (int i = 1; i <= n; i++)
			swap(sum1[i], sum2[i]);
	}
	int pnt = 0;
	for (int i = 0; i <= n; i++)
	{
		while (sum2[pnt] <= sum1[i]) pnt++;
		int d = sum2[pnt] - sum1[i];
		if (pos[d] != make_pair(0, 0)) print(pos[d].first + 1, i, pos[d].second + 1, pnt);
		pos[d] = make_pair(i, pnt);
	}
}