#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 300005
using namespace std;
char s[maxn];
int n;
long long x, y;
int main()
{
	scanf("%d%lld%lld%s", &n, &x, &y, s + 1);
	int cnt = 0;
	s[0] = '1';
	for (int i = 1; i <= n; i++)
	{
		if(s[i - 1] == '1' && s[i] == '0') cnt++;
	}
	if(cnt == 0)
	{
		printf("0\n");
		return 0;
	}
	if(x > y) printf("%lld", (long long)cnt * y);
	else printf("%lld", (long long)(cnt - 1) * x + y);
	return 0;
}