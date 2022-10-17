#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#define ll long long
#define maxn 40005
using namespace std;
int T;
inline int read()
{
	int w = 0, x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') 
	{
		w |= ch == '-';
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar(); 
	}
	return w ? -x : x;
}
int a[maxn], n, k, ans1[maxn], ans2[maxn]; 
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 2; i <= n; i++)
	{
		printf("and 1 %d\n", i);
		fflush(stdout);
		scanf("%d", &ans1[i]);
		printf("or 1 %d\n", i);
		fflush(stdout);
		scanf("%d", &ans2[i]);
	}
	printf("or 2 3\n");
	fflush(stdout);
	int tmp;
	scanf("%d", &tmp);
	for (int i = 30; i >= 0; i--)
	{
		int flag2 = 1, flag1 = 0;
		for (int j = 2; j <= n; j++)
		{
			flag1 |= ((ans1[j] >> i) & 1);
			flag2 &= ((ans2[j] >> i) & 1);
		}
		int c = 0;
		if(flag2 == 1 && (flag1 || !((tmp >> i) & 1))) a[1] += (1 << i), c = 1;
		for (int j = 2; j <= n; j++)
		{
			if((c == 1 && ((ans1[j] >> i) & 1)) || (c == 0 && ((ans2[j] >> i) & 1))) a[j] += (1 << i);
		}
	}
	sort(a + 1, a + n + 1);
	printf("finish %d\n", a[k]);
	fflush(stdout);
	return 0;
}