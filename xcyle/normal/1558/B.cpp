#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define ll long long
#define maxn 8000005
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
int n, mo, f[maxn], sum[maxn], cf[maxn];
int main()
{
	scanf("%d%d", &n, &mo);
	f[1] = 1;
	int sum = 0, now = 0;
	for (int i = 1; i <= n; i++)
	{
		now = (now + cf[i]) % mo;
		if(i != 1) f[i] = (sum + now) % mo;
		//printf("%d\n", f[i]);
		for (int j = 2; i * j <= n; j++)
		{
			//printf("%d %d %d\n", j, i * j, (i + 1) * j);
			cf[i * j] = (cf[i * j] + f[i]) % mo;
			cf[min(n + 1, (i + 1) * j)] = (cf[min(n + 1, (i + 1) * j)] + mo - f[i]) % mo;
		}
		sum = (sum + f[i]) % mo;
	}
	printf("%d\n", f[n]);
	return 0;
}