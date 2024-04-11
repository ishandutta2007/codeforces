#include <iostream>
#include <cstdio>
#define maxn 100005
using namespace std;
int n, a[maxn], p[maxn], f[maxn];
int main()
{ 
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &a[i]);
		p[a[i]] = i;
	}
	for (int i = n; i >= 1; i--)
	{
		for (int j = p[i] % i; j <= n; j += i)
		{
			if(j == 0 || a[j] <= i) continue;
			if(!f[j]) f[p[i]] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if(f[i]) printf("A");
		else printf("B");
	}
	return 0;
}