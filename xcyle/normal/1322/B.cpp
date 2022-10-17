#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 400005
using namespace std;
int n, a[maxn], b[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for (int i = 0; i <= 28; i++)
	{
		for (int j = 1; j <= n; j++) b[j] = a[j] % (1 << i);
		sort(b + 1, b + n + 1);
		int k = n, cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			while(k && b[k] + b[j] >= (1 << i)) k--;
			cnt += n - k;
			if(k < j) cnt--;
		}
		cnt /= 2;
		cnt &= 1;
		for (int j = 1; j <= n; j++) 
		{
			cnt ^= (((a[j] >> i) & 1) & ((n - 1) & 1));
		}
		ans += cnt * (1 << i);
	}
	printf("%d ", ans);
	return 0;
}