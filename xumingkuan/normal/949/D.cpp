#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 101010;
int n, d, b, a[MAXN];
bool checkside(int ans, int ed)
{
	long long rem = 0;
	for(int i = 1; i <= ans; i++)
		rem += a[i];
	int now = ans + 1;
	while(now <= ed && rem + a[now] - b >= 0)
	{
		rem = rem + a[now] - b;
		now++;
	}
	if(now > ed)
		return true;
	rem += a[now];
	int p = now + 1;
	while(now <= ed)
	{
		while(rem < b)
		{
			if(p - now > (long long)now * d)
				return false;
			rem += a[p];
			p++;
		}
		rem -= b;
		now++;
	}
	return true;
}
bool check(int ans)
{
	if(!checkside(ans, (n + 1) / 2))
		return false;
	reverse(a + 1, a + n + 1);
	bool ret = checkside(ans, n / 2);
	reverse(a + 1, a + n + 1);
	return ret;
}
int main()
{
	scanf("%d%d%d", &n, &d, &b);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int le = 0, ri = (n + 1) / 2;
	while(le < ri)
	{
		int mi = (le + ri) / 2;
		if(check(mi))
			ri = mi;
		else
			le = mi + 1;
	}
	printf("%d\n", le);
	return 0;
}