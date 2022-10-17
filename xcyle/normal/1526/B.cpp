#include <iostream>
#include <cstdio>
#define maxn 5005
using namespace std;
int t, n, f[maxn];
int main()
{
	scanf("%d", &t);
	f[0] = 1;
	for (int i = 11; i < maxn; i++)
	{
		f[i] |= f[i - 11];
	}
	for (int i = 111; i < maxn; i++)
	{
		f[i] |= f[i - 111];
	}
	for (int i = 1111; i < maxn; i++)
	{
		f[i] |= f[i - 1111];
	}
	while(t--)
	{
		scanf("%d", &n);
		if(n >= maxn) printf("YES\n");
		else if(f[n]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}