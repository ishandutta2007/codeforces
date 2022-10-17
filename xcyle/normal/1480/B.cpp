#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 100005
using namespace std;
int t, n;
long long A, B, a[maxn], b[maxn];
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld%lld%d", &A, &B, &n);
		long long tmp = 0;
		for (int i = 1; i <= n; i++) 
		{
			scanf("%lld", &a[i]);
			tmp = max(tmp, a[i]);
		}
		for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
		long long ans = 0;
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			ans += ((b[i] - 1) / A + 1) * a[i];
			if(ans > B + tmp)
			{
				flag = 1;
				break;
			}
		}
		if(!flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}