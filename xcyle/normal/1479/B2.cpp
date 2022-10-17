#include <iostream>
#include <cstdio>
#define maxn 100005
using namespace std;
int n, a[maxn], lst[maxn];
int f[maxn];
int main()
{
	scanf("%d", &n);
	int tmp = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] != a[tmp]) a[++tmp] = a[i];
	}
	n = tmp;
	int mx = 0;
	for (int i = 1; i <= n; i++)
	{
		if(lst[a[i]]) f[i] = f[lst[a[i]] + 1] + 1;
		f[i] = max(f[i], mx);
		mx = max(mx, f[i]);		
		lst[a[i]] = i;
	}
	printf("%d", n - mx);
	return 0;
}